#ifndef MOVIE_H
#define MOVIE_H

#include "Item.h"

using namespace std;

class Movie : public Item {
//ostream operators used for printing
friend ostream &operator<<(ostream&, const Item &);

public:
  // constructor
  Movie();
  
  // destructor
  virtual ~Movie();

  // won't be created in Item.cpp & Movie.cpp, 
  // but appear in chilren classes
  // Item & Movie ==> abstract classes
  // create() function can be used after the types of Movie
  virtual Item* create() const = 0;

  // compare operators to sort items in BSTree
  virtual bool operator==(const Item &other) const = 0;

  virtual bool operator!=(const Item &other) const = 0;

  virtual bool operator<(const Item &other) const = 0;

  virtual bool operator>(const Item &other) const = 0;
  
  // assignment operator
  virtual Item& operator=(const Item &other) = 0; 

  // setting item
  virtual void setItem(istream& data) = 0;

  // return genre of movie: 
  // F - Comedy, D - Drama, C- Classics
  char getMovieGenre() const;

protected:
  // gives chilren class access
  char movieGenre;
  string title;
  int yearReleased;
};

#endif // MOVIE_H