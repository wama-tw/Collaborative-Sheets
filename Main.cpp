#include <iostream>
#include <utility>
#include <vector>

#include "Controllers/SheetController.hpp"
#include "Controllers/UserController.hpp"
#include "Views/View.hpp"

using namespace std;

int main() {
  bool ChangeAccessRight = true;
  bool Collaborate = true;
  UserController userController;
  SheetController sheetController;
  while (true) {
    printMenu(ChangeAccessRight, Collaborate);
    switch (getInputChoice()) {
      case 1:
        printCreateUser(userController);
        break;
      case 2:
        printCreateSheet(userController, sheetController);
        break;
      case 3:
        printCheckSheet(userController, sheetController);
        break;
      case 4:
        printChangeValueInSheet(userController, sheetController);
        break;
      case 5:
        if (ChangeAccessRight) {
          printChangeAccessRight(userController, sheetController);
        } else {
          cout << "Unknown choice." << endl;
        }
        break;
      case 6:
        if (Collaborate) {
          printCollaborateWithUser(userController, sheetController);
        } else {
          cout << "Unknown choice." << endl;
        }
        break;
      default:
        cout << "Unknown choice." << endl;
        break;
    }
    cout << endl;
  }
}
