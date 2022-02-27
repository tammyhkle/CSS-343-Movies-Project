#ifndef ITEM_H
#define ITEM_H

#include "Movie.h"
#include "BSTree.h"

using namespace std;

class Item {
//ostream operators used for printing
friend ostream &operator<<(ostream &out, const Item &item);

public:
  // constructor
  Item();
  
  // destructor
  virtual ~Item();

  // decrement copies of private variables
  void borrowItem();

  // increment copies of private variables 
  void returnItem();

  // won't be created in Item.cpp & Movie.cpp, 
  // but appear in chilren classes
  // Item & Movie ==> abstract classes
  // create() function can be used after the types of Movie
  virtual Item* create() const = 0;

  // compare operators to sort items in BSTree
  virtual bool operator==(const Item &other) const = 0;

  virtual bool operator!=(const Item &other) const = 0;

  virtual bool operator<(const Item &other) const = 0;

  virtual bool operator>(const Item &other) const  = 0;
  
  // assignment operator
  virtual Item& operator=(const Item &other) = 0; 

  // setting item
  virtual void setItem(istream& data) = 0;

protected:
  // gives chilren class access
  int maxCopies;
  int currCopies;
  char itemType; // indicating it's a movie
  char mediaType; // indicating the format (D for DVD)
};

#endif // ITEM_H