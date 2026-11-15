#ifndef REAL_ESTATE_H_
#define REAL_ESTATE_H_

#include <chrono>
#include <cstdint>
#include <string>

class RealEstate {
 public:
  RealEstate(const std::string& owner, std::chrono::year_month_day date,
             unsigned long cost);
  RealEstate(const std::string& owner, int year, int month, int day,
             unsigned long cost);

  const std::string& getOwner() const { return owner_; }
  std::chrono::year_month_day getDate() const { return date_; }
  unsigned long getCost() const { return cost_; }

 private:
  std::string owner_;
  std::chrono::year_month_day date_;
  unsigned long cost_;
};

std::ostream& operator<<(std::ostream& out, const RealEstate& estate);

#endif
