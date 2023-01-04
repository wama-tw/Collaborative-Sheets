#include "Sheet.hpp"

#include <iostream>
#include <vector>

#include "../Database.hpp"

using namespace std;

Sheet::Sheet(string name) {
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

string Sheet::getName() {
  return this->name;
}

string Sheet::getAccessRights() {
  return this->accessRights;
}

float **Sheet::getContent() {
  return this->sheetContent;
}

void Sheet::setSheetContent(int row, int col, float newValue) {
  (this->sheetContent)[row][col] = newValue;
}

void Sheet::setAccessRights(string newAccessRights) {
  this->accessRights = newAccessRights;
}

Sheet *getSheetByName(string name) {
  for (int i = 0; i < SheetTable.size(); i++) {
    if (SheetTable[i]->getName() == name) {
      return SheetTable[i];
    }
  }
  return NULL;
}