#ifndef USER_MODELS_H
#define USER_MODELS_H

#include <iostream>
#include <vector>

using namespace std;

class User {
 private:
  string name;

 public:
  User(string name);
  string getName();
};

User *getUserByName(string name);

#endif