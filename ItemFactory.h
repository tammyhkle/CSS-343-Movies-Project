/*
  ItemFactory is the class where we create Item objects
*/

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <map>
#include <vector>
#include <string>

#include "BSTree.h"
#include "Item.h"
#include "Movie.h"

using namespace std;

class ItemFactory {
public:
  ItemFactory(); // constructor
  virtual ~ItemFactory(); // destructor
  virtual Item *create(char prefix) const = 0; // where we create the item, using a char prefix that's been read and     passed in. We keep it virtual since it's going to be overriden.
};

#endif // ITEMFACTORY_H