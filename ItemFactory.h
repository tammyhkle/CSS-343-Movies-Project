/**
 * @file ItemFactory.h
 * @author Le, Tammy
 * @brief ItemFactory class - ItemFactory is the class where we create Item
 *objects Notes: When the ItemFactory is called on, it creates an Item object
 * @date 2022-02-26
 **/
#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Item.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class ItemFactory {
public:
  // default constructor
  ItemFactory();
  // destructor
  virtual ~ItemFactory();
  // where we create the item, using a char prefix that's been read and
  // passed in. We keep it virtual since it's going to be overriden.
  virtual Item *create(char prefix) const = 0;
};

#endif // ITEMFACTORY_H