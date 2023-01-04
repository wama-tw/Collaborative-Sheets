#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printMenu(bool ChangeAccessRight, bool Collaborate);
void printCreateUser(string newUserName);
void printCreateSheet(string newSheetName, string creatorName, bool alreadyExists);
void printChangeValueInSheetError(bool isInRightPosition, bool isAccessible);
void printWrongRightAccessType(string newAccessRight);
void printCollaborateWithUser(string sharerName, string sheetName, string newEditorName);
void printUserDontHaveAccessToSheet(string userName, string sheetName);
void printContent(float **sheetContent);
bool isExist(void *object, string type, string name);

#endif