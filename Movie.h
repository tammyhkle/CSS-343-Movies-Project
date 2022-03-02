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

//use globle constants?

class Movie : public Item {
  friend ostream &operator<<(ostream &out, const Movie &movie); //ostream operator used for printing

public:
  Movie(); // constructor
  virtual ~Movie(); // destructor

  virtual char returnItemType() const = 0;
  /* return genre of movie: 
    F - Comedy, D - Drama, C- Classics
  */
  virtual char getItemTypeGenre() const = 0;
  /* won't be created in Item.cpp & Movie.cpp,
    but appear in chilren classes
    Item & Movie ==> abstract classes
    create() function can be used after the types of Movie
  */
  virtual Item* create() const = 0;
  // setting item
  virtual void setItem(istream& data) = 0;
  // assignment operator
  virtual Item& operator=(const Item &item) = 0; 
  //print
  virtual void print (ostream& out) const = 0;

  // compare operators to sort items in BSTree
  virtual bool operator==(const Item &item) const = 0;
  virtual bool operator!=(const Item &item) const = 0;
  virtual bool operator<(const Item &item) const = 0;
  virtual bool operator>(const Item &item) const = 0;

protected:
  // gives chilren class access
  string title_;
  char movieGenre_;
  int yearReleased_;
};

#endif // MOVIE_H