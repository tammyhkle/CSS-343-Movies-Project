#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

#include "BSTree.h"
#include "Movie.h"
#include "ItemFactory.h"

using namespace std;

class Item {
  friend class BSTree;
  friend ostream &operator<<(ostream&, const Item&);

public:
  Item(); // constructor
  virtual ~Item(); // destructor
  void borrowItem(); // decrement copies of private variables
  void returnItem(); // increment copies of private variables 

  // won't be created in Item.cpp & Movie.cpp, 
  // but appear in chilren classes
  // Item & Movie ==> abstract classes
  // create() function can be used after the types of Movie
  virtual Item* create() const = 0;
  virtual void setItem(istream&) = 0; // setting item

  // assignment operator
  virtual Item& operator=(const Item &other) = 0; 
  // compare operators to sort items in BSTree
  virtual bool operator==(const Item &other) const = 0;
  virtual bool operator!=(const Item &other) const = 0;
  virtual bool operator<(const Item &other) const = 0;
  virtual bool operator>(const Item &other) const  = 0;

// gives children class access
protected:
  int maxCopies_; //max number of copies of item 
  int currCopies_; // number of current copies of item
  char itemType_; // indicating it's a movie
  char mediaType_; // indicating the format (D for DVD)
};

#endif // ITEM_H