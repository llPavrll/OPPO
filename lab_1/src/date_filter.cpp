#include "date_filter.h"

#include <algorithm>
#include <iostream>
#include <optional>
#include <regex>
#include <string>

namespace {

const std::regex kDateText(R"re((\d{4})\.(\d{2})\.(\d{2}))re");

std::optional<std::chrono::year_month_day> ParseDate(const std::string& text) {
  std::smatch match;
  if (!std::regex_match(text, match, kDateText)) return std::nullopt;
  const std::chrono::year_month_day date(
      std::chrono::year(std::stoi(match[1].str())),
      std::chrono::month(static_cast<unsigned>(std::stoi(match[2].str()))),
      std::chrono::day(static_cast<unsigned>(std::stoi(match[3].str()))));
  if (!date.ok()) return std::nullopt;
  return date;
}

std::optional<std::chrono::year_month_day> AskDate(const std::string& prompt) {
  std::string text;
  std::cout << prompt;
  if (!(std::cin >> text)) return std::nullopt;
  const auto date = ParseDate(text);
  if (!date) {
    std::cout << "Неверная дата: нужен формат гггг.мм.дд, "
              << "и такая дата должна существовать\n";
  }
  return date;
}

void PrintFound(const std::vector<RealEstate>& found) {
  if (found.empty()) {
    std::cout << "В этом диапазоне ничего нет\n";
    return;
  }
  for (size_t i = 0; i < found.size(); i++) {
    std::cout << found[i] << "\n";
  }
}

}  // namespace

std::vector<RealEstate> FilterByDates(const std::vector<RealEstate>& estates,
                                      std::chrono::year_month_day from,
                                      std::chrono::year_month_day to) {
  const auto low = std::min(from, to);
  const auto high = std::max(from, to);
  std::vector<RealEstate> found;
  for (size_t i = 0; i < estates.size(); i++) {
    const auto date = estates[i].getDate();
    if (low <= date && date <= high) found.push_back(estates[i]);
  }
  return found;
}

void RunDateFilter(const std::vector<RealEstate>& estates) {
  const auto from = AskDate("Начальная дата (гггг.мм.дд): ");
  if (!from) return;
  const auto to = AskDate("Конечная дата (гггг.мм.дд): ");
  if (!to) return;
  PrintFound(FilterByDates(estates, *from, *to));
}