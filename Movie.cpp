/**
 * @file Movie.cpp
 * @author Le, Tammy
 * @brief Movie class - Movie are children classes of Item
 * @date 2022-02-26
 **/
#include "Movie.h"

// ostream operator<<
ostream &operator<<(ostream &output, const Movie &movie) 
{
    movie.print(output);
    return output;
}

// constructor
Movie::Movie() 
{
    title_ = "";
    // Setting to Z, if genre no change to F/C/D, then it's invalid
    genre_ = 'Z';
    // setting to 0 bc year can be any
    yearReleased_ = 0;
    // M for Movie
    itemType_ = 'D';
    // D for DVD
    mediaType_ = 'D';
}

// destructor
Movie::~Movie() {}

// print - virtual print that prints the data of movie object
void Movie::print(ostream &output) const 
{ 
    output << title_ << genre_ << yearReleased_ << itemType_ << mediaType_;
}