#ifndef USER_MODELS_H
#define USER_MODELS_H

#include <iostream>

class User {
 private:
  std::string name;

 public:
  User(std::string name);
  std::string getName();
};

#endif