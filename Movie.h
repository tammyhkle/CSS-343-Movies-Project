/**
 * @file Movie.h
 * @author Le, Tammy
 * @brief Movie class - Movie are children classes of Item
 * @date 2022-02-26
 **/

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

#include "Item.h"
#include "Classics.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class Movie : public Item {
  friend ostream &operator<<(ostream &out, const Movie &movie); //ostream operator used for printing

public:
  Movie(); // default constructor
  virtual ~Movie(); // destructor

  virtual char getItemType() const = 0; // return item type as char

  /* return genre of movie as char: 
    F - Comedy, D - Drama, C- Classics
  */
  virtual char getGenre() const = 0;

  /* won't be created in Item.cpp & Movie.cpp,
    but appear in children classes
    Item & Movie ==> abstract classes
    create() function can be used after the types of Movie
  */
  virtual Item* create() const = 0;
  virtual void setItem(istream& data) = 0; // setting item
  virtual Item& operator=(const Item &item) = 0; // assignment operator
  virtual void print (ostream& out) const = 0; //print
  // compare operators to sort items in BSTree
  virtual bool operator==(const Item &item) const = 0;
  virtual bool operator!=(const Item &item) const = 0;
  virtual bool operator<(const Item &item) const = 0;
  virtual bool operator>(const Item &item) const = 0;

protected: // gives chilren class access
  string title_;
  char genre_;
  int yearReleased_;
};

#endif // MOVIE_H