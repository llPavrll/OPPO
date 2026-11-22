#ifndef DATE_FILTER_H_
#define DATE_FILTER_H_

#include <chrono>
#include <vector>

#include "real_estate.h"

std::vector<RealEstate> FilterByDates(const std::vector<RealEstate>& estates,
                                      std::chrono::year_month_day from,
                                      std::chrono::year_month_day to);

void RunDateFilter(const std::vector<RealEstate>& estates);

#endif