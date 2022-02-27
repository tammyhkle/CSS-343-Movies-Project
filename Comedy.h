#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"

using namespace std;

class Comedy : public Movie {

public:
  // constructor
  Comedy();
  
  // destructor
  virtual ~Comedy();

  // create() function can be used after the types of Movie
  virtual Item* create() const;

  // compare operators to sort items in BSTree
  virtual bool operator==(const Item &other) const;

  virtual bool operator!=(const Item &other) const;

  virtual bool operator<(const Item &other) const;

  virtual bool operator>(const Item &other) const;
  
  // assignment operator
  virtual Item& operator=(const Item &other); 

  // setting item
  virtual void setItem(istream &data);

private:
  string director;
};

#endif // COMEDY_H