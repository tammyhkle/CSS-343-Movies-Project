#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

#include "Item.h"

using namespace std;

class Movie : public Item {
  friend ostream &operator<<(ostream&, const Movie&); //ostream operator used for printing

public:
  Movie(); // constructor
  virtual ~Movie(); // destructor

  /* return genre of movie: 
    F - Comedy, D - Drama, C- Classics
  */
  char getMovieGenre() const;

  /* won't be created in Item.cpp & Movie.cpp,
    but appear in chilren classes
    Item & Movie ==> abstract classes
    create() function can be used after the types of Movie
  */
  virtual Item* create() const = 0;
  
  // setting item
  virtual void setItem(istream& data) = 0;
  
  // assignment operator
  virtual Item& operator=(const Item &other) = 0; 

  // compare operators to sort items in BSTree
  virtual bool operator==(const Item &other) const = 0;
  virtual bool operator!=(const Item &other) const = 0;
  virtual bool operator<(const Item &other) const = 0;
  virtual bool operator>(const Item &other) const = 0;

protected:
  // gives chilren class access
  string title_;
  char movieGenre_;
  int yearReleased_;
};

#endif // MOVIE_H