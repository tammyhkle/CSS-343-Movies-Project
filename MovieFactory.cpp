/**
 * @file MovieFactory.cpp
 * @author Le, Tammy
 * @brief MovieFactory class - MovieFactory is the child of ItemFactory.
 * Notes:
 * In MovieFactory we're creating the movie objects
 * @date 2022-02-26
 **/

#include "Movie.h"

// default constructor
MovieFactory::MovieFactory()
{
}
// destructor - deletes movie objects from vector 
MovieFactory::~MovieFactory()
{
}
// creating the movie object, overrides Item's create function
// override is optional
Item* MovieFactory::create(char movieType) const 
{
}