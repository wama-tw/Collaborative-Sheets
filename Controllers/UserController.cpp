#include "UserController.hpp"

#include <iostream>
#include <vector>

#include "../Views/View.hpp"

void UserController::create() {
  cout << "> ";
  string newUserName;
  cin >> newUserName;
  User *newUser = new User(newUserName);
  return printCreateUser(newUser->getName());
}
