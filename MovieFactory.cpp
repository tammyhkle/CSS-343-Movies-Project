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
    movieFac_.push_back(new Comedy);
    movieFac_.push_back(new Drama);
    movieFac_.push_back(new Classics);
    // insert elements - movie genre ({key, value}) into map in a random order
    movieMap_.insert(make_pair('F', 0));
    movieMap_.insert(make_pair('D', 1));
    movieMap_.insert(make_pair('C', 2));
}
// destructor - deletes movie objects from vector
MovieFactory::~MovieFactory() 
{
    for (int i = 0; i < movieFac_.size(); i++)
    {
        delete movieFac_[i];
        movieFac_[i] = nullptr;
        }
}
// creating the movie object, overrides Item's create function
// override is optional
Item *MovieFactory::create(char movieType) const 
{
    cerr << "MovieType" << movieType << endl;
    if (movieMap_.find(movieType) == movieMap_.end()) 
    {
        return nullptr;
    } 
    else 
    {
        int subscript = movieMap_.at(movieType);
        cerr << "subscript" << subscript << endl;
        return movieFac_[subscript]->create();
    }
}