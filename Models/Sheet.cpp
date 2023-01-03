#include "Sheet.hpp"

#include <iostream>

#include "../Database.hpp"

Sheet::Sheet(std::string name) {
  this->name = name;
  this->accessRights = "Editable";
  this->sheetContent = new float *[3];
  for (int i = 0; i < 3; i++) {
    this->sheetContent[i] = new float[3];
    for (int j = 0; j < 3; j++) {
      (this->sheetContent)[i][j] = 0;
    }
  }
  SheetTable.push_back(this);
}

std::string Sheet::getName() {
  return this->name;
}

std::string Sheet::getAccessRights() {
  return this->accessRights;
}

float **Sheet::getContent() {
  return this->sheetContent;
}

void Sheet::setSheetContent(int row, int col, float newValue) {
  (this->sheetContent)[row][col] = newValue;
}

void Sheet::setAccessRights(std::string newAccessRights) {
  this->accessRights = newAccessRights;
}
