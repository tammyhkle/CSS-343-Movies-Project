/**
 * @file MovieFactory.cpp
 * @author Le, Tammy
 * @brief MovieFactory class - MovieFactory is the child of ItemFactory.
 * Notes:
 * In MovieFactory we're creating the movie objects
 * This means we will be creating and returning a new movie object
 * All factory classes are like Hashmaps
 * comedy: F, Stock, Director, title, yearReleased
 * drama: D, Stock, Director, title, yearReleased
 * classics: C, Stock, Director, title, majorActor, releaseDate
 * @date 2022-02-26
 **/
#include "MovieFactory.h"
#include "Movie.h"

// default constructor - need to declare elements in hashmap and in movieFactory
MovieFactory::MovieFactory() 
{
    // pushback
    movieFac.push_back(new Comedy);
    movieFac.push_back(new Drama);
    movieFac.push_back(new Classics);
    // insert elements - movie genre ({key, value}) into map in a random order
    movieMap.insert(make_pair('F', 0));
    movieMap.insert(make_pair('D', 1));
    movieMap.insert(make_pair('C', 2));
}
// destructor - deletes movie objects from vector
MovieFactory::~MovieFactory() 
{
    for (int i = 0; i < movieFac.size(); i++)
    {
        delete movieFac[i];
        movieFac[i] = nullptr;
        }
}
// creating the movie object, overrides Item's create function
// override is optional
Item *MovieFactory::create(char movieType) const 
{
    if (movieMap.find(movieType) == movieMap.end()) 
    {
        return nullptr;
    } 
    else 
    {
        int subscript = movieMap.at(movieType);
        return movieFac[subscript]->create();
    }
}