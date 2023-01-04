#include "Relation.hpp"

#include <iostream>
#include <vector>

#include "../Database.hpp"

using namespace std;

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

bool hasAccessTo(User *user, Sheet *sheet) {
  for (int i = 0; i < RelationTable.size(); i++) {
    if (RelationTable[i]->getEditor()->getName() == user->getName() &&
        RelationTable[i]->getSheet()->getName() == sheet->getName()) {
      return true;
    }
  }
  return false;
}

vector<Sheet *> getSheetsAccessibleByUser(string username) {
  vector<Sheet *> result;
  for (int i = 0; i < RelationTable.size(); i++) {
    if (RelationTable[i]->getEditor()->getName() == username) {
      result.push_back(RelationTable[i]->getSheet());
    }
  }
  return result;
}

vector<User *> getUsersHaveAccessToSheet(string sheetName) {
  vector<User *> result;
  for (int i = 0; i < RelationTable.size(); i++) {
    if (RelationTable[i]->getSheet()->getName() == sheetName) {
      result.push_back(RelationTable[i]->getEditor());
    }
  }
  return result;
}
