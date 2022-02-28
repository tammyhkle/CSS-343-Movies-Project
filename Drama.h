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
  // assignment operator
  virtual Item& operator=(const Item&); 
  // virtual comparison operators 
  virtual bool operator==(const Item&) const;
  virtual bool operator!=(const Item&) const;
  virtual bool operator<(const Item&) const;
  virtual bool operator>(const Item&) const;

  // setting item
  virtual void setItem(istream& data);

private:
  string director;
};

#endif // DRAMA_H