#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>

#include "models.hpp"

extern std::vector<User *> UserTable;
extern std::vector<Sheet *> SheetTable;
extern std::vector<Relation *> RelationTable;

#endif