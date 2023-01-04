#include "User.hpp"

#include <iostream>
#include <vector>

#include "../Database.hpp"

using namespace std;

User::User(string name) {
  this->name = name;
  UserTable.push_back(this);
}

string User::getName() {
  return this->name;
}

User *getUserByName(string name) {
  for (int i = 0; i < UserTable.size(); i++) {
    if (UserTable[i]->getName() == name) {
      return UserTable[i];
    }
  }
  return NULL;
}