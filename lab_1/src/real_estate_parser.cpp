#include "real_estate_parser.h"

#include <chrono>
#include <optional>
#include <regex>
#include <string>
#include <vector>

namespace {
const std::regex kOwner(R"re("([^"]+)")re");
const std::regex kDate(R"re((?:^|\s)(\d{4})\.(\d{2})\.(\d{2})(?=\s|$))re");
const std::regex kCost(R"re((?:^|\s)(\d{1,9})(?=\s|$))re");

std::optional<std::vector<std::string> > FindOnly(const std::string &text,
                                                  const std::regex &re) {
  std::sregex_iterator it(text.begin(), text.end(), re);
  const std::sregex_iterator end;
  if (it == end) return std::nullopt;
  std::vector<std::string> groups;
  for (size_t i = 1; i < it->size(); ++i) {
    groups.push_back((*it)[i].str());
  }
  if (++it != end) return std::nullopt;
  return groups;
}

bool IsValidDate(int year, int month, int day) {
  return std::chrono::year_month_day(
             std::chrono::year(year),
             std::chrono::month(static_cast<unsigned>(month)),
             std::chrono::day(static_cast<unsigned>(day)))
      .ok();
}

std::optional<RealEstate> MakeEstate(const std::vector<std::string> &owner,
                                     const std::vector<std::string> &date,
                                     const std::vector<std::string> &cost) {
  const int year = std::stoi(date[0]);
  const int month = std::stoi(date[1]);
  const int day = std::stoi(date[2]);
  if (!IsValidDate(year, month, day)) return std::nullopt;
  return RealEstate(owner[0], year, month, day, std::stoul(cost[0]));
}
}  // namespace

std::optional<RealEstate> RealEstateParser::Parse(
    const std::string &line) const {
  const auto owner = FindOnly(line, kOwner);
  const std::string rest = std::regex_replace(
      line, kOwner, " ");  // На случай если во владельце есть цыфры
  const auto date = FindOnly(rest, kDate);
  const auto cost = FindOnly(rest, kCost);

  if (!owner || !date || !cost) return std::nullopt;
  return MakeEstate(*owner, *date, *cost);
}
