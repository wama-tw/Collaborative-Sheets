#ifndef SHEET_MODELS_H
#define SHEET_MODELS_H

#include <iostream>

class Sheet {
 private:
  std::string name;
  std::string accessRights;  // "Editable" or "ReadOnly"
  float **sheetContent;

 public:
  Sheet(std::string name);
  std::string getName();
  std::string getAccessRights();
  float **getContent();
  void setSheetContent(int row, int col, float newValue);
  void setAccessRights(std::string newAccessRights);
};

#endif