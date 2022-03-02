/**
 * @file Movie.cpp
 * @author Le, Tammy
 * @brief Movie class - Movie are children classes of Item
 * @date 2022-02-26
 **/

#include "Movie.h"

//ostream operator<<
ostream &operator<<(ostream &out, const Movie &movie)
{
    movie.print(out);
    return out;
}
// constructor
Movie::Movie()
{
    title_ = "";
    genre_ = 'Z'; //Setting to Z so we know that if genre doesn't change to F, C, or D, then it's invalid
    yearReleased_ = 0; //setting to 0 bc year can be any
    itemType_ = 'M'; //M for Movie
    mediaType_ = 'D'; //D for DVD
} 

// destructor
Movie::~Movie()
{
}

//print - virtual print that prints the data of movie object
void Movie::print (ostream &out) const
{
    this->print(out);
}



