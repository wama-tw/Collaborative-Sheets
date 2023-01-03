#ifndef RELATION_CONTROLLERS_H
#define RELATION_CONTROLLERS_H

#include <iostream>
#include <vector>

#include "../Database.hpp"
#include "../Models/Relation.hpp"
#include "../Models/Sheet.hpp"
#include "../Models/User.hpp"

class RelationController {
 public:
  Relation *create(User *editor, Sheet *sheet);
  bool hasAccessTo(User *user, Sheet *sheet);
  std::vector<Sheet *> getSheetsAccessibleByUser(std::string username);
  std::vector<User *> getUsersHaveAccessToSheet(std::string sheetName);
};

#endif