#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Item.h"

/*
ItemFactory is the class where we create Item objects
*/
class ItemFactory {
public:

  // constructor
  ItemFactory();

  // destructor
  virtual ~ItemFactory();

  // where we create the item, using a char prefix that's been read and     passed in. We keep it virtual since it's going to be overriden.
  virtual Item *create(char prefix) const = 0;
};

#endif // ITEMFACTORY_H