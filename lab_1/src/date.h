#ifndef DATE_H_
#define DATE_H_

#include <ostream>

class Date {
public:
    Date(int year, int month, int day);

    static bool IsValid(int year, int month, int day);

    int getYear() const { return year_; }
    int getMonth() const { return month_; }
    int getDay() const { return day_; }

private:
    int year_;
    int month_;
    int day_;
};

std::ostream &operator<<(std::ostream &out, const Date &date);

#endif
