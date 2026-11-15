#include "real_estate.h"

#include <format>

RealEstate::RealEstate(const std::string& owner,
                       std::chrono::year_month_day date, unsigned long cost)
    : owner_(owner), date_(date), cost_(cost) {}

RealEstate::RealEstate(const std::string& owner, int year, int month, int day,
                       unsigned long cost)
    : RealEstate(owner,
                 std::chrono::year_month_day(
                     std::chrono::year(year),
                     std::chrono::month(static_cast<unsigned>(month)),
                     std::chrono::day(static_cast<unsigned>(day))),
                 cost) {}

std::ostream& operator<<(std::ostream& out, const RealEstate& estate) {
  return out << "Недвижимость\n"
             << "Владелец: " << estate.getOwner() << "\n"
             << "Дата: " << std::format("{:%Y.%m.%d}", estate.getDate()) << "\n"
             << "Стоимость: " << estate.getCost() << "\n";
}
