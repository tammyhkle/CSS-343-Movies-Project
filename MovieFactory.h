/*
MovieFactory is the child of ItemFactory. In MovieFactory
we're creating the movie objects
*/

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <map>
#include <vector>

#include "ItemFactory.h"
#include "Item.h"
#include "Movie.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"

class MovieFactory: public ItemFactory {
public:
  MovieFactory(); // constructor
  virtual ~MovieFactory(); // destructor

  Item *create(char prefix) const override; // creating the movie object, overrides Item's create function
  // override is optional
    
private:
  unordered_map<char, int> movieMap; // Hashmap with keys equal to char variables of every possible movie genre and values equal to integers ranging from 0 to the number of move types -1
  vector<Movie*> movieFac; // vector with elements that are initialized as new movie objects of every possible movie type
};
#endif // MOVIEFACTORY_H