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
