#ifndef SHEET_CONTROLLERS_H
#define SHEET_CONTROLLERS_H

#include <iostream>
#include <vector>

#include "../Models/Sheet.hpp"
#include "../Models/User.hpp"

class SheetController {
 private:
  float evaluate(std::string expression_string);

 public:
  void create();
  void check();
  void changeValue();
  void changeAccessRights();
  void collaborateWithUser();
};

#endif