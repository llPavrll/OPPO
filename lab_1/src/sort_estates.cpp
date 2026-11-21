#include "sort_estates.h"

#include <algorithm>

namespace {

bool CostLess(const RealEstate& a, const RealEstate& b) {
  return a.getCost() < b.getCost();
}

}

void SortByCost(std::vector<RealEstate>& estates) {
  std::sort(estates.begin(), estates.end(), CostLess);
}