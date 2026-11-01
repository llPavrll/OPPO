#include "date.h"

#include <chrono>

Date::Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {}

bool Date::IsValid(int year, int month, int day) {
  return std::chrono::year_month_day(
             std::chrono::year(year),
             std::chrono::month(static_cast<unsigned>(month)),
             std::chrono::day(static_cast<unsigned>(day)))
      .ok();
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
  return out << date.getYear() << "." << date.getMonth() << "."
             << date.getDay();
}
