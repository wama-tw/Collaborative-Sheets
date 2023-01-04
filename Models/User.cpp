#include "User.hpp"

#include <iostream>

#include "../Database.hpp"

User::User(std::string name) {
  this->name = name;
  UserTable.push_back(this);
}

std::string User::getName() {
  return this->name;
}

User *getUserByName(std::string name) {
  for (int i = 0; i < UserTable.size(); i++) {
    if (UserTable[i]->getName() == name) {
      return UserTable[i];
    }
  }
  return NULL;
}