#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <iostream>
#include <vector>

#include "database.hpp"
#include "models.hpp"

class RelationController {
 public:
  Relation *create(User *editor, Sheet *sheet);
  bool hasAccessTo(User *user, Sheet *sheet);
  std::vector<Sheet *> getSheetsAccessibleByUser(std::string username);
  std::vector<User *> getUsersHaveAccessToSheet(std::string sheetName);
};

class UserController {
 private:
  RelationController relationController;

 public:
  User *create(std::string name);
  std::vector<Sheet *> getSheetsAccessibleByUser(std::string name);
  User *getUserByName(std::string name);
};

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
  std::string CollaborateWithUser(User *sharer, Sheet *sheet, User *newEditor);
};

#endif