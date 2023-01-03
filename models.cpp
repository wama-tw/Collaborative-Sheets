#include "models.hpp"

#include <iostream>

#include "database.hpp"

User::User(std::string name) {
  this->name = name;
  UserTable.push_back(this);
}
std::string User::getName() {
  return this->name;
}

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

Relation::Relation(User *user, Sheet *sheet) {
  this->editor = user;
  this->sheet = sheet;
  RelationTable.push_back(this);
}

User *Relation::getEditor() {
  return this->editor;
}

Sheet *Relation::getSheet() {
  return this->sheet;
}
