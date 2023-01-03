#ifndef USER_CONTROLLERS_H
#define USER_CONTROLLERS_H

#include <iostream>
#include <vector>

#include "../Database.hpp"
#include "../Models/Sheet.hpp"
#include "../Models/User.hpp"
#include "RelationController.hpp"

class UserController {
 private:
  RelationController relationController;

 public:
  User *create(std::string name);
  std::vector<Sheet *> getSheetsAccessibleByUser(std::string name);
  User *getUserByName(std::string name);
};

#endif