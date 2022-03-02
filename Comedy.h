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

#include "Movie.h"

#include <iostream>
#include <string>

using namespace std;

class Comedy : public Movie {

friend ostream &operator<<(ostream &out, const Comedy &comedy);

public:
  Comedy(); // constructor
  virtual ~Comedy(); // destructor

  virtual char returnItemType() const;
  virtual char returnItemTypeGenre() const;
  // create() function can be used after the types of Movie
  virtual Item* create() const;
  // setting item
  virtual void setItem(istream &data);

  // assignment operator
  virtual Item& operator=(const Item &item);
  // virtual comparison operators 
  virtual bool operator==(const Item &item) const;
  virtual bool operator!=(const Item &item) const;
  virtual bool operator<(const Item &item) const;
  virtual bool operator>(const Item &item) const; 

  //print
  virtual void print(ostream &out) const;

private:
  string director_; //director of movie
};

#endif //COMEDY_H