/**
 * @file Movie.cpp
 * @author Le, Tammy
 * @brief Movie class - Movie are children classes of Item
 * @date 2022-02-26
 **/
#include "Movie.h"

// ostream operator<<
ostream &operator<<(ostream &output, const Movie &movie) {
  movie.print(output);
  return output;
}

// constructor
Movie::Movie() {
  title = "";
  // Setting to Z, if genre no change to F/C/D, then it's invalid
  genre = 'Z';
  // setting to 0 bc year can be any
  yearReleased = 0;
  // M for Movie
  itemType = 'D';
  // D for DVD
  mediaType = 'D';
}

// destructor
Movie::~Movie() {}

// print - virtual print that prints the data of movie object
void Movie::print(ostream &output) const {
  output << title << genre << yearReleased << itemType << mediaType;
}