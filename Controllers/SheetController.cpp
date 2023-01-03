#include "SheetController.hpp"

#include <iostream>
#include <vector>

Sheet *SheetController::create(std::string name, User *creator) {
  std::vector<User *> users = getUsersHaveAccessToSheet(name);
  for (int i = 0; i < users.size(); i++) {
    if (users[i]->getName() == creator->getName()) {
      return NULL;
    }
  }
  Sheet *newSheet = new Sheet(name);
  relationController.create(creator, newSheet);
  return newSheet;
}

std::vector<User *> SheetController::getUsersHaveAccessToSheet(std::string sheetName) {
  return relationController.getUsersHaveAccessToSheet(sheetName);
}

float **SheetController::check(User *user, Sheet *sheet) {
  if (!relationController.hasAccessTo(user, sheet)) {
    return NULL;
  }
  return sheet->getContent();
}

Sheet *SheetController::getSheetByName(std::string name) {
  for (int i = 0; i < SheetTable.size(); i++) {
    if (SheetTable[i]->getName() == name) {
      return SheetTable[i];
    }
  }
  return NULL;
}

std::string SheetController::changeValue(User *user, Sheet *sheet, int row, int col, float newValue) {
  if (!relationController.hasAccessTo(user, sheet)) {
    return "userDenied";
  }
  if (sheet->getAccessRights() != "Editable") {
    return "accessRightDenied";
  }
  sheet->setSheetContent(row, col, newValue);
  this->check(user, sheet);
  return "";
}

std::string SheetController::changeAccessRights(User *user, Sheet *sheet, std::string newAccessRights) {
  if (!relationController.hasAccessTo(user, sheet)) {
    return "userDenied";
  }
  if (newAccessRights != "Editable" && newAccessRights != "ReadOnly") {
    return "accessRightTypeDenied";
  }
  sheet->setAccessRights(newAccessRights);
  return "";
}

std::string SheetController::collaborateWithUser(User *sharer, Sheet *sheet, User *newEditor) {
  if (!relationController.hasAccessTo(sharer, sheet)) {
    return "userDenied";
  }
  relationController.create(newEditor, sheet);
  return "";
}