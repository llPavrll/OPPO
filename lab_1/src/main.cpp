#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>

#include "real_estate.h"
#include "real_estate_parser.h"


void ParserFile(std::ifstream &file) {
    RealEstateParser parser;
    std::string line;
    while (std::getline(file, line)) {
        auto estate = parser.Parse(line);
        if (estate != std::nullopt) { std::cout << estate.value() << "\n"; }
        else { std::cout << "Неправильная строка: " << line << "\n\n"; }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::ifstream file("C:/Users/Povr/Desktop/OPPO/lab_1/untitled/input.txt");

    if (!file.is_open()) {
        std::cout << "Файл не найден\n";
        return 1;
    }



    ParserFile(file);
    return 0;
}
