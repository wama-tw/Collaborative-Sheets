#ifndef SHEET_CONTROLLERS_H
#define SHEET_CONTROLLERS_H

#include <iostream>
#include <vector>

#include "../Database.hpp"
#include "../Models/Sheet.hpp"
#include "../Models/User.hpp"
#include "RelationController.hpp"

class SheetController {
 private:
  RelationController relationController;

 public:
  Sheet *create(std::string name, User *creator);
  std::vector<User *> getUsersHaveAccessToSheet(std::string sheetName);
  float **check(User *user, Sheet *sheet);
  Sheet *getSheetByName(std::string name);
  std::string changeValue(User *user, Sheet *sheet, int row, int col, float newValue);
  std::string changeAccessRights(User *user, Sheet *sheet, std::string newAccessRights);
  std::string collaborateWithUser(User *sharer, Sheet *sheet, User *newEditor);
};

#endif