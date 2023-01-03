#include "Relation.hpp"

#include <iostream>

#include "../Database.hpp"

Relation::Relation(User *user, Sheet *sheet) {
  this->editor = user;
  this->sheet = sheet;
  RelationTable.push_back(this);
}

User *Relation::getEditor() {
  return this->editor;
}

Sheet *Relation::getSheet() {
  return this->sheet;
}
