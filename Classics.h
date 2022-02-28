/**
 * @file Classics.h
 * @author Le, Tammy
 * @brief Classics class - sorting by Release Date, then by Major Actor
 * Notes:
 * Classics = "C"
 * Output format: C, stock, director, title, majorActor, releaseDate
 * @date 2022-02-26
 **/

#ifndef CLASSICS_H
#define CLASSICS_H

#include "Movie.h"

#include <iostream>
#include <string>

using namespace std;

class Classics : public Movie {

public:
  Classics(); //default constructor
  virtual ~Classics(); // destructor

  // create() function can be used after the types of Movie
  virtual Item* create() const;
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
  virtual void setItem(istream &data);
  //print
  virtual void print(ostream& out) const;

private:
  string director_;
  string majorActor_;
  int dateReleased_;
};

#endif //CLASSICS_H