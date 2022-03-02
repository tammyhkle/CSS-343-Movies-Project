/**
 * @file Drama.h
 * @author Le, Tammy
 * @brief Drama class - sorting by Director, then Title of movie
 * Notes:
 * Drama = "D"
 * Output format: D, stock, director, title, yearReleased (same format as Comedy)
 * @date 2022-02-26
 **/

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
  virtual char getItemType() const;
  virtual char getGenre() const;

  // assignment operator
  virtual Item& operator=(const Item &item); 

  // virtual comparison operators 
  virtual bool operator==(const Item &item) const;
  virtual bool operator!=(const Item &item) const;
  virtual bool operator<(const Item &item) const;
  virtual bool operator>(const Item &item) const;

  // setting item
  virtual void setItem(istream &data);
  
  //print
  virtual void print(ostream &out) const;

private:
  string director_;
};

#endif //DRAMA_H