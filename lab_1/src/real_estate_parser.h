#ifndef REAL_ESTATE_PARSER_H_
#define REAL_ESTATE_PARSER_H_

#include <optional>
#include <string>

#include "real_estate.h"


class RealEstateParser {
public:
    std::optional<RealEstate> Parse(const std::string &line) const;
};

#endif
