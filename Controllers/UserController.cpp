#include "UserController.hpp"

#include <iostream>
#include <vector>

User *UserController::create(std::string name) {
  return (new User(name));
}

std::vector<Sheet *> UserController::getSheetsAccessibleByUser(std::string name) {
  return relationController.getSheetsAccessibleByUser(name);
}

User *UserController::getUserByName(std::string name) {
  for (int i = 0; i < UserTable.size(); i++) {
    if (UserTable[i]->getName() == name) {
      return UserTable[i];
    }
  }
  return NULL;
}