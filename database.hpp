#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>

#include "Models/Relation.hpp"
#include "Models/Sheet.hpp"
#include "Models/User.hpp"

using namespace std;

extern vector<User *> UserTable;
extern vector<Sheet *> SheetTable;
extern vector<Relation *> RelationTable;

#endif