#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>

#include "Models/Relation.hpp"
#include "Models/Sheet.hpp"
#include "Models/User.hpp"

extern std::vector<User *> UserTable;
extern std::vector<Sheet *> SheetTable;
extern std::vector<Relation *> RelationTable;

#endif