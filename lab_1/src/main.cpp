#include <windows.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "real_estate.h"
#include "real_estate_parser.h"

std::vector<RealEstate> ReadEstates(std::ifstream& file) {
  const RealEstateParser parser;
  std::vector<RealEstate> estates;
  std::string line;
  while (std::getline(file, line)) {
    const auto estate = parser.Parse(line);
    if (estate) {
      estates.push_back(*estate);
    } else {
      std::cout << "Неправильная строка: " << line << "\n\n";
    }
  }
  return estates;
}

void PrintEstates(const std::vector<RealEstate>& estates) {
  for (size_t i = 0; i < estates.size(); i++) {
    std::cout << estates[i] << "\n";
  }
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  std::ifstream file("C:/Users/Povr/Desktop/OPPO/lab_1/untitled/input.txt");

  if (!file.is_open()) {
    std::cout << "Файл не найден\n";
    return 1;
  }

  PrintEstates(ReadEstates(file));
  return 0;
}
