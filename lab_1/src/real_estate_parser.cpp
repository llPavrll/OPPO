#include <regex>

#include "real_estate_parser.h"
#include "date.h"


std::optional<RealEstate> RealEstateParser::Parse(const std::string &line) const {
    static const std::regex pattern(R"re(\s*Недвижимость\s+"([^"]+)"\s+(\d{4})\.(\d{2})\.(\d{2})\s+(-?\d+)\s*)re");

    std::smatch match;
    if (!std::regex_match(line, match, pattern)) {
        return std::nullopt;
    }
    if (!Date::IsValid(std::stoi(match[2].str()), std::stoi(match[3].str()), std::stoi(match[4].str()))) {
        return std::nullopt;
    }
    return RealEstate(match[1].str(), std::stoi(match[2].str()),
                      std::stoi(match[3].str()), std::stoi(match[4].str()),
                      std::stoll(match[5].str()));
}
