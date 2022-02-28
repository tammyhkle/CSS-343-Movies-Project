/**
 * @file Comedy.cpp
 * @author Le, Tammy
 * @brief Comedy class - sorting by Title of movie, then yearReleased
 * Notes:
 * Comedy = "F" for funny
 * Output format: F, stock, director, title, yearReleased (same format as Drama)
 * @date 2022-02-26
 **/

#ifndef COMEDY_H
#define COMEDY_H

#include <iostream>
#include <string>

#include "Movie.h"

using namespace std;

class Comedy : public Movie {

public:
  Comedy(); // constructor
  virtual ~Comedy(); // destructor

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
  virtual void setItem(istream& data);
  //print
  virtual void print(ostream& out) const;

private:
  string director_;
};

#endif //COMEDY_H