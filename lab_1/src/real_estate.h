#ifndef REAL_ESTATE_H_
#define REAL_ESTATE_H_

#include <cstdint>
#include <ostream>
#include <string>

#include "date.h"

class RealEstate {
 public:
  RealEstate(const std::string &owner, const Date &date, unsigned long cost);

  RealEstate(const std::string &owner, int year, int month, int day,
             unsigned long cost);

  const std::string &getOwner() const { return owner_; }
  const Date &getDate() const { return date_; }
  long long getCost() const { return cost_; }

 private:
  std::string owner_;
  Date date_;
  uint64_t cost_;
};

std::ostream &operator<<(std::ostream &out, const RealEstate &estate);

#endif
