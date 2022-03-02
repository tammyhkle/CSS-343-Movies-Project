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
    movieGenre_ = 'C', 'F', 'D';
    yearReleased_ = 1000;
    itemType_ = 'Movie';
    mediaType_ = 'DVD';
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



