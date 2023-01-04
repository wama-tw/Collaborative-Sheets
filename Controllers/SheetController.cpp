#include "SheetController.hpp"

#include <iostream>
#include <utility>
#include <vector>

#include "../Libraries/exprtk.hpp"
#include "../Models/Relation.hpp"
#include "../Models/Sheet.hpp"
#include "../Models/User.hpp"
#include "../Views/View.hpp"

using namespace std;

void SheetController::create() {
  cout << "> ";
  string creatorName, sheetName;
  cin >> creatorName >> sheetName;
  User *creator = getUserByName(creatorName);
  if (!(isExist(creator, "User", creatorName))) {
    return;
  }

  bool alreadyExists = true;
  vector<User *> users = getUsersHaveAccessToSheet(sheetName);
  for (int i = 0; i < users.size(); i++) {
    if (users[i]->getName() == creator->getName()) {
      return printCreateSheet(sheetName, creatorName, alreadyExists);
    }
  }
  Sheet *newSheet = new Sheet(sheetName);
  Relation(creator, newSheet);

  return printCreateSheet(sheetName, creatorName, (!alreadyExists));
}

void SheetController::check() {
  cout << "> ";
  string userName, sheetName;
  cin >> userName >> sheetName;
  User *user = getUserByName(userName);
  Sheet *sheet = getSheetByName(sheetName);
  if (!(isExist(user, "User", userName) &&
        isExist(sheet, "Sheet", sheetName))) {
    return;
  }

  if (!hasAccessTo(user, sheet)) {
    return printUserDontHaveAccessToSheet(userName, sheetName);
  }

  return printContent(sheet->getContent());
}

void SheetController::changeValue() {
  cout << "> ";
  string userName, sheetName;
  cin >> userName >> sheetName;
  User *user = getUserByName(userName);
  Sheet *sheet = getSheetByName(sheetName);
  if (!(isExist(user, "User", userName) &&
        isExist(sheet, "Sheet", sheetName))) {
    return;
  }
  if (!hasAccessTo(user, sheet)) {
    return printUserDontHaveAccessToSheet(userName, sheetName);
  }
  printContent(sheet->getContent());

  cout << endl
       << "> ";
  int row, col;
  string inputValue;
  cin >> row >> col >> inputValue;
  float newValue = evaluate(inputValue);

  bool isInRightPosition = true;
  bool isAccessible = true;
  if (row > 3 || row < 0 || col > 3 || col < 0) {
    return printChangeValueInSheetError((!isInRightPosition), isAccessible);
  }
  if (sheet->getAccessRights() != "Editable") {
    return printChangeValueInSheetError(isInRightPosition, (!isAccessible));
  }

  sheet->setSheetContent(row, col, newValue);

  return printContent(sheet->getContent());
}

void SheetController::changeAccessRights() {
  cout << "> ";
  string userName, sheetName, newAccessRights;
  cin >> userName >> sheetName >> newAccessRights;
  User *user = getUserByName(userName);
  Sheet *sheet = getSheetByName(sheetName);
  if (!(isExist(user, "User", userName) &&
        isExist(sheet, "Sheet", sheetName))) {
    return;
  }

  if (!hasAccessTo(user, sheet)) {
    return printUserDontHaveAccessToSheet(userName, sheetName);
  } else if (newAccessRights != "Editable" && newAccessRights != "ReadOnly") {
    return printWrongRightAccessType(newAccessRights);
  }

  sheet->setAccessRights(newAccessRights);

  return;
}

void SheetController::collaborateWithUser() {
  cout << "> ";
  string sharerName, sheetName, newEditorName;
  cin >> sharerName >> sheetName >> newEditorName;
  User *sharer = getUserByName(sharerName);
  User *newEditor = getUserByName(newEditorName);
  Sheet *sheet = getSheetByName(sheetName);
  if (!(isExist(sharer, "User", sharerName) &&
        isExist(newEditor, "User", newEditorName) &&
        isExist(sheet, "Sheet", sheetName))) {
    return;
  }

  if (!hasAccessTo(sharer, sheet)) {
    return printUserDontHaveAccessToSheet(sharerName, sheetName);
  }

  Relation(newEditor, sheet);

  return printCollaborateWithUser(sharerName, sheetName, newEditorName);
}

float SheetController::evaluate(string expression_string) {
  typedef exprtk::expression<double> expression_t;
  typedef exprtk::parser<double> parser_t;

  expression_t expression;

  parser_t parser;

  if (parser.compile(expression_string, expression)) {
    return expression.value();
  } else
    cout << "Error in expression." << endl;

  return 0;
}