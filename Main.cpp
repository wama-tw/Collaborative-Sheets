#include <iostream>
#include <utility>
#include <vector>

#include "Controllers/SheetController.hpp"
#include "Controllers/UserController.hpp"
#include "Views/View.hpp"

using namespace std;

int getInputChoice();

int main() {
  bool ChangeAccessRight = true;
  bool Collaborate = true;
  UserController userController;
  SheetController sheetController;
  while (true) {
    printMenu(ChangeAccessRight, Collaborate);
    switch (getInputChoice()) {
      case 1:
        userController.create();
        break;
      case 2:
        sheetController.create();
        break;
      case 3:
        sheetController.check();
        break;
      case 4:
        sheetController.changeValue();
        break;
      case 5:
        if (ChangeAccessRight)
          sheetController.changeAccessRights();
        else
          cout << "Unknown choice." << endl;
        break;
      case 6:
        if (Collaborate)
          sheetController.collaborateWithUser();
        else
          cout << "Unknown choice." << endl;
        break;
      default:
        cout << "Unknown choice." << endl;
        break;
    }
    cout << endl;
  }
}

int getInputChoice() {
  string input;
  cin >> input;
  if ((input.length() != 1) || (input[0] < '0' || input[0] > '9')) {
    return (-1);
  }
  return (input[0] - '0');
}
