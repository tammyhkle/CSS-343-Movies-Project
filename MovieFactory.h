#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "ItemFactory.h"
#include "Movie.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"
#include <map>
#include <vector>

/*
MovieFactory is the child of ItemFactory. In MovieFactory
we're creating the movie objects
*/
class MovieFactory: public ItemFactory {
public:
  // constructor
  MovieFactory();

  // destructor
  virtual ~MovieFactory();

  // creating the movie object, overrides Item's create function
  Item *create(char prefix) const override; // override is     optional
    
private:

  // Hashmap with keys equal to char variables of every possible movie genre and values equal to integers ranging from 0 to the number of move types -1
  unordered_map<char, int> movieMap; 

  // vector with elements that are initialized as new movie objects of every possible movie type
  vector<Movie*> movieFac;
};

#endif // MOVIEFACTORY_H