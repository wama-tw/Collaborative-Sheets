#include <iostream>
#include <utility>
#include <vector>

#include "controllers.hpp"
#include "database.hpp"
#include "exprtk.hpp"
#include "models.hpp"

using namespace std;

void printMenu(bool ChangeAccessRight, bool Collaborate);
User *createUser(UserController userController);
Sheet *createSheet(UserController userController, SheetController sheetController);
pair<User *, Sheet *> checkSheet(UserController userController, SheetController sheetController);
pair<User *, Sheet *> changeValueInSheet(UserController userController, SheetController sheetController);
void changeAccessRight(UserController userController, SheetController sheetController);
void CollaborateWithUser(UserController userController, SheetController sheetController);
void printContent(float **sheetContent);
float evaluate(string expression_string);
bool isExist(void *object, string type, string name);

int main() {
  bool ChangeAccessRight = true;
  bool Collaborate = false;
  string input = "";
  int choice = 0;
  UserController userController;
  SheetController sheetController;
  while (true) {
    printMenu(ChangeAccessRight, Collaborate);
    cin >> input;
    if ((input.length() != 1) || (input[0] < '0' || input[0] > '9')) {
      cout << "Please input integer" << endl;
      continue;
    }
    choice = (input[0] - '0');
    switch (choice) {
      case 1:
        createUser(userController);
        break;
      case 2:
        createSheet(userController, sheetController);
        break;
      case 3:
        checkSheet(userController, sheetController);
        break;
      case 4:
        changeValueInSheet(userController, sheetController);
        break;
      case 5:
        if (ChangeAccessRight) {
          changeAccessRight(userController, sheetController);
        } else {
          cout << "Unknown choice" << endl;
        }
        break;
      case 6:
        if (Collaborate) {
          CollaborateWithUser(userController, sheetController);
        } else {
          cout << "Unknown choice" << endl;
        }
        break;
      default:
        cout << "Unknown choice" << endl;
        break;
    }
    cout << endl;
  }
}

void printMenu(bool ChangeAccessRight, bool Collaborate) {
  cout << "---------------Menu---------------" << endl;
  cout << "1. Create a user" << endl;
  cout << "2. Create a sheet" << endl;
  cout << "3. Check a sheet" << endl;
  cout << "4. Change a value in a sheet" << endl;
  if (ChangeAccessRight)
    cout << "5. Change a sheet's access right." << endl;
  if (Collaborate)
    cout << "6. Collaborate with an other user" << endl;
  cout << "----------------------------------" << endl;
  cout << "> ";
}

User *createUser(UserController userController) {
  cout << "> ";
  string newUserName;
  cin >> newUserName;
  User *newUser = userController.create(newUserName);
  cout << "Create a user named \"" << newUser->getName() << "\"." << endl;
  return newUser;
}

Sheet *createSheet(UserController userController, SheetController sheetController) {
  cout << "> ";
  string creatorName, sheetName;
  cin >> creatorName >> sheetName;
  User *creator = userController.getUserByName(creatorName);
  if (!(isExist(creator, "User", creatorName))) {
    return NULL;
  }

  Sheet *newSheet = sheetController.create(sheetName, creator);
  if (newSheet == NULL) {
    cout << "Sheet \"" << sheetName << "\" already exist." << endl;
    return NULL;
  }
  cout << "Create a sheet named \"" << newSheet->getName() << "\" for \"" << creator->getName() << "\"." << endl;
  return newSheet;
}

pair<User *, Sheet *> checkSheet(UserController userController, SheetController sheetController) {
  cout << "> ";
  string userName, sheetName;
  cin >> userName >> sheetName;
  User *user = userController.getUserByName(userName);
  Sheet *sheet = sheetController.getSheetByName(sheetName);
  if (!(isExist(user, "User", userName) &&
        isExist(sheet, "Sheet", sheetName))) {
    return make_pair(user, sheet);
  }
  float **sheetContent = sheetController.check(user, sheet);
  if (sheetContent == NULL) {
    cout << "\"" << user->getName() << "\" don't have access to sheet \""
         << sheet->getName() << "\"." << endl;
    sheet = NULL;
    return make_pair(user, sheet);
  }
  printContent(sheetContent);
  return make_pair(user, sheet);
}

pair<User *, Sheet *> changeValueInSheet(UserController userController, SheetController sheetController) {
  pair<User *, Sheet *> operation = checkSheet(userController, sheetController);
  if (operation.first == NULL || operation.second == NULL) {
    return operation;
  }
  User *user = operation.first;
  Sheet *sheet = operation.second;

  cout << endl
       << "> ";
  int row, col;
  string inputValue;
  cin >> row >> col >> inputValue;
  float newValue = evaluate(inputValue);
  if (row > 3 || row < 0 || col > 3 || col < 0) {
    cout << "Invalid position (0-2)" << endl;
    return make_pair(user, sheet);
  }
  string result = sheetController.changeValue(user, sheet, row, col, newValue);
  if (result == "userDenied") {  // not executed
    cout << "\"" << user->getName() << "\" don't have access to sheet \"" << sheet->getName() << "\"." << endl;
    sheet = NULL;
    return make_pair(user, sheet);
  }
  if (result == "accessRightDenied") {
    cout << "This sheet is not accessible." << endl;
  }

  printContent(sheetController.check(user, sheet));

  return operation;
}

void changeAccessRight(UserController userController, SheetController sheetController) {
  cout << "> ";
  string userName, sheetName, newAccessRight;
  cin >> userName >> sheetName >> newAccessRight;
  User *user = userController.getUserByName(userName);
  Sheet *sheet = sheetController.getSheetByName(sheetName);
  if (!(isExist(user, "User", userName) &&
        isExist(sheet, "Sheet", sheetName))) {
    return;
  }
  string result = sheetController.changeAccessRights(user, sheet, newAccessRight);

  if (result == "userDenied") {
    cout << "\"" << user->getName() << "\" don't have access to sheet \"" << sheet->getName() << "\"." << endl;
  } else if (result == "accessRightTypeDenied") {
    cout << "There is no access right named \"" << newAccessRight << "\"." << endl;
    cout << "Please use \"Editable\" or \"ReadOnly\"" << endl;
  }
  return;
}

void CollaborateWithUser(UserController userController, SheetController sheetController) {
  cout << "> ";
  string sharerName, sheetName, newEditorName;
  cin >> sharerName >> sheetName >> newEditorName;
  User *sharer = userController.getUserByName(sharerName);
  User *newEditor = userController.getUserByName(newEditorName);
  Sheet *sheet = sheetController.getSheetByName(sheetName);
  if (!(isExist(sharer, "User", sharerName) &&
        isExist(newEditor, "User", newEditorName) &&
        isExist(sheet, "Sheet", sheetName))) {
    return;
  }
  string result = sheetController.CollaborateWithUser(sharer, sheet, newEditor);

  if (result == "userDenied") {
    cout << "\"" << sharer->getName() << "\" don't have access to sheet \"" << sheet->getName() << "\"." << endl;
  } else if (result == "") {
    cout << "Share \"" << sharerName << "\"'s \"" << sheetName
         << "\" with \"" << newEditorName << "\"." << endl;
  }
  return;
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

float evaluate(string expression_string) {
  typedef exprtk::expression<double> expression_t;
  typedef exprtk::parser<double> parser_t;

  expression_t expression;

  parser_t parser;

  if (parser.compile(expression_string, expression)) {
    return expression.value();
  } else
    printf("Error in expression.\n");

  return 0;
}

bool isExist(void *object, string type, string name) {
  if (object == NULL) {
    cout << type << " \"" << name << "\" doesn't exist." << endl;
    return false;
  }
  return true;
}
