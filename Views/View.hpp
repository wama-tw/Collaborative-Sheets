#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <utility>
#include <vector>

#include "../Controllers/RelationController.hpp"
#include "../Controllers/SheetController.hpp"
#include "../Controllers/UserController.hpp"
#include "../Models/Relation.hpp"
#include "../Models/Sheet.hpp"
#include "../Models/User.hpp"

using namespace std;

int getInputChoice();
void printMenu(bool ChangeAccessRight, bool Collaborate);
User *printCreateUser(UserController userController);
Sheet *printCreateSheet(UserController userController, SheetController sheetController);
pair<User *, Sheet *> printCheckSheet(UserController userController, SheetController sheetController);
pair<User *, Sheet *> printChangeValueInSheet(UserController userController, SheetController sheetController);
void printChangeAccessRight(UserController userController, SheetController sheetController);
void printCollaborateWithUser(UserController userController, SheetController sheetController);
void printContent(float **sheetContent);
float evaluate(string expression_string);
bool isExist(void *object, string type, string name);

#endif