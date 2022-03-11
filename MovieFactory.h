/**
 * @file MovieFactory.h
 * @author Le, Tammy
 * @brief MovieFactory class - MovieFactory is the child of ItemFactory.
 * Notes:
 * In MovieFactory we're creating the movie objects
 * This means we will be creating and returning a new movie object
 * All factory classes are like Hashmaps
 * @date 2022-02-26
 **/
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "Classics.h"
#include "Comedy.h"
#include "Drama.h"
#include "Item.h"
#include "ItemFactory.h"
#include "Movie.h"
/*
#include "Classics.h"
#include "Comedy.h"
#include "Drama.h"
#include "Item.h"
#include "ItemFactory.h"
#include "Movie.h"
*/
#include <unordered_map>
#include <vector>
using namespace std;

class MovieFactory : public ItemFactory {
public:
  // default constructor
  MovieFactory();
  // destructor: deletes movie objects from vector
  virtual ~MovieFactory();
  // creates the movie object, overrides Item's create function, override is
  // optional
  Item *create(char movieType) const;

private:
  // Hashmap with keys equal to char variables of every possible movie genre
  // and values equal to integers ranging from 0 to the number of move types -1
  unordered_map<char, int> movieMap_;
  // vector with elements that are initialized as new movie objects of every
  // possible movie type
  vector<Movie *> movieFac_;
};

#endif // MOVIEFACTORY_H