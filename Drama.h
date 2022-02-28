/*
  Drama class - sorting by Director, then Title of movie
  Notes:
    Drama = "D"
    Output format: D, stock, director, title, yearReleased
*/

#ifndef DRAMA_H
#define DRAMA_H

#include <iostream>
#include <string>

#include "Movie.h"

using namespace std;

class Drama : public Movie {

public:
  Drama(); // default constructor
  virtual ~Drama(); // destructor

  virtual Item* create() const; // create() function can be used after the types of Movie
  virtual char returnItemType() const;
  virtual char returnItemGenre() const;
  // assignment operator
  virtual Item& operator=(const Item&); 
  // virtual comparison operators 
  virtual bool operator==(const Item&) const;
  virtual bool operator!=(const Item&) const;
  virtual bool operator<(const Item&) const;
  virtual bool operator>(const Item&) const;
  // setting item
  virtual void setItem(istream& data);
  //print
  virtual void print(ostream& out) const;

private:
  string director_;
};

#endif // DRAMA_H