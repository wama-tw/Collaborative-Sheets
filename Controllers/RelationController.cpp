#include "RelationController.hpp"

#include <iostream>
#include <vector>

Relation *RelationController::create(User *editor, Sheet *sheet) {
  return (new Relation(editor, sheet));
}

bool RelationController::hasAccessTo(User *user, Sheet *sheet) {
  for (int i = 0; i < RelationTable.size(); i++) {
    if (RelationTable[i]->getEditor()->getName() == user->getName() &&
        RelationTable[i]->getSheet()->getName() == sheet->getName()) {
      return true;
    }
  }
  return false;
}

std::vector<Sheet *> RelationController::getSheetsAccessibleByUser(std::string username) {
  std::vector<Sheet *> result;
  for (int i = 0; i < RelationTable.size(); i++) {
    if (RelationTable[i]->getEditor()->getName() == username) {
      result.push_back(RelationTable[i]->getSheet());
    }
  }
  return result;
}

std::vector<User *> RelationController::getUsersHaveAccessToSheet(std::string sheetName) {
  std::vector<User *> result;
  for (int i = 0; i < RelationTable.size(); i++) {
    if (RelationTable[i]->getSheet()->getName() == sheetName) {
      result.push_back(RelationTable[i]->getEditor());
    }
  }
  return result;
}