#include <windows.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "date_filter.h"
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
  for (const auto& item : estates) {
    std::cout << item << "\n";
  }
}

void PrintMenu() {
  std::cout << "\n1. Показать все\n"
            << "2. Фильтр по датам\n"
            << "0. Выход\n"
            << "Выбор: ";
}

int ReadChoice() {
  int choice = -1;
  if (!(std::cin >> choice)) {
    if (std::cin.eof()) return 0;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    return -1;
  }
  return choice;
}

bool HandleChoice(int choice, std::vector<RealEstate>& estates) {
  switch (choice) {
    case 1:
      PrintEstates(estates);
      return true;
    case 2:
      RunDateFilter(estates);
      return true;
    case 0:
      return false;
    default:
      std::cout << "Неизвестный пункт\n";
      return true;
  }
}

void RunMenu(std::vector<RealEstate>& estates) {
  bool running = true;
  while (running) {
    PrintMenu();
    running = HandleChoice(ReadChoice(), estates);
  }
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  std::ifstream file("C:/Users/Povr/Desktop/OPPO/lab_1/untitled/input.txt");

  if (!file.is_open()) {
    std::cout << "Файл не найден\n";
    return 1;
  }
  std::vector<RealEstate> estates = ReadEstates(file);
  RunMenu(estates);
  return 0;
}
