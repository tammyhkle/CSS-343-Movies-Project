#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

using namespace std;

class Drama : public Movie {

public:
  // constructor
  Drama();
  
  // destructor
  virtual ~Drama();

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
  virtual void setItem(istream& data);

private:
  string director;
};

#endif // DRAMA_H