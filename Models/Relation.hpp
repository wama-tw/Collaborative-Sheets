#ifndef RELATION_MODELS_H
#define RELATION_MODELS_H

#include <iostream>

#include "Sheet.hpp"
#include "User.hpp"

class Relation {
 private:
  User *editor;
  Sheet *sheet;

 public:
  Relation(User *user, Sheet *sheet);
  User *getEditor();
  Sheet *getSheet();
};

bool hasAccessTo(User *user, Sheet *sheet);
std::vector<Sheet *> getSheetsAccessibleByUser(std::string username);
std::vector<User *> getUsersHaveAccessToSheet(std::string sheetName);

#endif