/**
 * @file Item.h
 * @author Le, Tammy
 * @brief Item class - Item is the nodes in the BSTree class
 * Notes:
 * The items in the BSTree have nodeData ptr (points to the movie)
 * Extenibles can be added (i.e. music)
 * @date 2022-02-26
 **/
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
  friend class BSTree;
  friend ostream &operator<<(ostream &output, const Item &item);

public:
  // default constructor
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
  virtual Item *create() const = 0;

  // get itemType
  virtual char getItemType() const = 0;
  // type of itemType
  virtual char getGenre() const = 0;

  // setting item
  virtual void setItem(istream &) = 0;
  virtual void setPartialItem(istream &inFile, char itemType, char genre) = 0;

  // assignment operator
  virtual Item &operator=(Item &) = 0;
  // compare operators to sort items in BSTree
  virtual bool operator==(Item &) const = 0;
  virtual bool operator!=(Item &) const = 0;
  virtual bool operator<(Item &) const = 0;
  virtual bool operator>(Item &) const = 0;

  // virtual print
  virtual void print(ostream &out) const = 0;

  // gives children class access
protected:
  int maxCopies_;
  int currCopies_;
  char itemType_;  // M for Movie
  char mediaType_; // D for DVD
};

#endif // ITEM_H