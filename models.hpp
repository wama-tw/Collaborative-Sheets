#ifndef MODELS_H
#define MODELS_H

#include <iostream>

class User {
 private:
  std::string name;

 public:
  User(std::string name);
  std::string getName();
};

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

class Relation {
 private:
  User *editor;
  Sheet *sheet;

 public:
  Relation(User *user, Sheet *sheet);
  User *getEditor();
  Sheet *getSheet();
};

#endif