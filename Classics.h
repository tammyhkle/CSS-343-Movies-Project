#ifndef CLASSICS_H
#define CLASSICS_H

#include "Movie.h"

using namespace std;

class Classics : public Movie {

public:
  // constructor
  Classics();
  
  // destructor
  virtual ~Classics();

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
  string director_;
  string majorActor_;
  int dateReleased_;
};

#endif // CLASSICS_H