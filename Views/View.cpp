#include "View.hpp"

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printMenu(bool canChangeAccessRights, bool canCollaborate) {
  cout << "---------------Menu---------------" << endl;
  cout << "1. Create a user" << endl;
  cout << "2. Create a sheet" << endl;
  cout << "3. Check a sheet" << endl;
  cout << "4. Change a value in a sheet" << endl;
  if (canChangeAccessRights)
    cout << "5. Change a sheet's access right." << endl;
  if (canCollaborate)
    cout << "6. Collaborate with an other user" << endl;
  cout << "----------------------------------" << endl;
  cout << "> ";
}

void printCreateUser(string newUserName, bool alreadyExists) {
  if (alreadyExists) {
    cout << "User \"" << newUserName << "\" already exist." << endl;
    cout << "User name must be unique." << endl;
  } else
    cout << "Create a user named \"" << newUserName << "\"." << endl;
}

void printCreateSheet(string newSheetName, string creatorName, bool alreadyExists) {
  if (alreadyExists) {
    cout << "Sheet \"" << newSheetName << "\" already exist." << endl;
    cout << "Sheet name must be unique." << endl;
  } else
    cout << "Create a sheet named \"" << newSheetName << "\" for \"" << creatorName << "\"." << endl;
}

void printChangeValueInSheetError(bool isInRightPosition, bool isAccessible) {
  if (!isInRightPosition)
    cout << "Invalid position (0-2)" << endl;
  else if (!isAccessible)
    cout << "This sheet is not accessible." << endl;
}

void printWrongRightAccessType(string newAccessRight) {
  cout << "There is no access right named \"" << newAccessRight << "\"." << endl;
  cout << "Please use \"Editable\" or \"ReadOnly\"" << endl;
}

void printCollaborateWithUser(string sharerName, string sheetName, string newEditorName) {
  cout << "Share \"" << sharerName << "\"'s \"" << sheetName
       << "\" with \"" << newEditorName << "\"." << endl;
}

void printUserDontHaveAccessToSheet(string userName, string sheetName) {
  cout << "\"" << userName << "\" don't have access to sheet \""
       << sheetName << "\"." << endl;
}

void printContent(float **sheetContent) {
  cout << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << sheetContent[i][j] << ", ";
    }
    cout << endl;
  }
}

bool isExist(void *object, string type, string name) {
  if (object == NULL) {
    cout << type << " \"" << name << "\" doesn't exist." << endl;
    return false;
  }
  return true;
}
