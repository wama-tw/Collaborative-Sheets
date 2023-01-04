#ifndef USER_MODELS_H
#define USER_MODELS_H

#include <iostream>
#include <vector>

class User {
 private:
  std::string name;

 public:
  User(std::string name);
  std::string getName();
};

User *getUserByName(std::string name);

#endif