#ifndef USER_SHEET_RELATION_MODELS_H
#define USER_SHEET_RELATION_MODELS_H

#include <iostream>
#include <vector>

#include "Sheet.hpp"
#include "User.hpp"

using namespace std;

class UserSheetRelation {
 private:
  User *editor;
  Sheet *sheet;

 public:
  UserSheetRelation(User *user, Sheet *sheet);
  User *getEditor();
  Sheet *getSheet();
};

bool hasAccessTo(User *user, Sheet *sheet);
vector<Sheet *> getSheetsAccessibleByUser(string username);
vector<User *> getUsersHaveAccessToSheet(string sheetName);

#endif