#ifndef SHEET_MODELS_H
#define SHEET_MODELS_H

#include <iostream>

using namespace std;

class Sheet {
 private:
  string name;
  string accessRights;  // "Editable" or "ReadOnly"
  float **sheetContent;

 public:
  Sheet(string name);
  string getName();
  string getAccessRights();
  float **getContent();
  void setSheetContent(int row, int col, float newValue);
  void setAccessRights(string newAccessRights);
};

Sheet *getSheetByName(string name);

#endif