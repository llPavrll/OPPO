#include "real_estate.h"

RealEstate::RealEstate(const std::string &owner, const Date &date,
                       unsigned long cost)
    : owner_(owner), date_(date), cost_(cost) {}

RealEstate::RealEstate(const std::string &owner, int year, int month, int day,
                       unsigned long cost)
    : RealEstate(owner, Date(year, month, day), cost) {}

std::ostream &operator<<(std::ostream &out, const RealEstate &estate) {
  return out << "Недвижимость\n"
             << "Владелец: " << estate.getOwner() << "\n"
             << "Дата: " << estate.getDate() << "\n"
             << "Стоимость: " << estate.getCost() << "\n";
}
