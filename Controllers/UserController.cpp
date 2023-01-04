#include "UserController.hpp"

#include <iostream>
#include <vector>

#include "../Views/View.hpp"

void UserController::create() {
  cout << "> ";
  string newUserName;
  cin >> newUserName;

  bool alreadyExists = true;
  if (getUserByName(newUserName) != NULL) {
    return printCreateUser(newUserName, alreadyExists);
  }
  User *newUser = new User(newUserName);
  return printCreateUser(newUser->getName(), (!alreadyExists));
}
