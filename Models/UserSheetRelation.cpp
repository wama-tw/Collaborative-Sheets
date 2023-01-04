#include "UserSheetRelation.hpp"

#include <iostream>
#include <vector>

#include "../Database.hpp"

using namespace std;

UserSheetRelation::UserSheetRelation(User *user, Sheet *sheet) {
  this->editor = user;
  this->sheet = sheet;
  UserSheetRelationTable.push_back(this);
}

User *UserSheetRelation::getEditor() {
  return this->editor;
}

Sheet *UserSheetRelation::getSheet() {
  return this->sheet;
}

bool hasAccessTo(User *user, Sheet *sheet) {
  for (int i = 0; i < UserSheetRelationTable.size(); i++) {
    if (UserSheetRelationTable[i]->getEditor()->getName() == user->getName() &&
        UserSheetRelationTable[i]->getSheet()->getName() == sheet->getName()) {
      return true;
    }
  }
  return false;
}

vector<Sheet *> getSheetsAccessibleByUser(string username) {
  vector<Sheet *> result;
  for (int i = 0; i < UserSheetRelationTable.size(); i++) {
    if (UserSheetRelationTable[i]->getEditor()->getName() == username) {
      result.push_back(UserSheetRelationTable[i]->getSheet());
    }
  }
  return result;
}

vector<User *> getUsersHaveAccessToSheet(string sheetName) {
  vector<User *> result;
  for (int i = 0; i < UserSheetRelationTable.size(); i++) {
    if (UserSheetRelationTable[i]->getSheet()->getName() == sheetName) {
      result.push_back(UserSheetRelationTable[i]->getEditor());
    }
  }
  return result;
}
