#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>

#include "Models/Sheet.hpp"
#include "Models/User.hpp"
#include "Models/UserSheetRelation.hpp"

using namespace std;

extern vector<User *> UserTable;
extern vector<Sheet *> SheetTable;
extern vector<UserSheetRelation *> UserSheetRelationTable;

#endif