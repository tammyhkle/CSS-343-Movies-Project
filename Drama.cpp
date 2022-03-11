/**
 * @file Drama.cpp
 * @author Le, Tammy
 * @brief Drama class - sorting by Director, then Title of movie
 * Notes:
 * Drama = "D"
 * Output format: D, stock, director, title, yearReleased
 * (same format as Comedy)
 * @date 2022-02-26
 **/
#include "Drama.h"

// default constructor
Drama::Drama() { director = ""; }

// destructor
Drama::~Drama() {}

// return item type
char Drama::getItemType() const { return itemType; }

// return item type genre
char Drama::getGenre() const { return genre; }

// create() function can be used after the types of Movie
Item *Drama::create() const { return new Drama; }

// assignment operator
Item &Drama::operator=(Item &item) {
  const Drama &movieDrama = dynamic_cast<const Drama &>(item);
  this->currCopies = movieDrama.currCopies;     // stock
  this->director = movieDrama.director;         // director
  this->title = movieDrama.title;               // title
  this->yearReleased = movieDrama.yearReleased; // year it released
  return *this;
}
// comparison operator== DRAMA
bool Drama::operator==(Item &item) const {
  Drama &ptr = dynamic_cast<Drama &>(item);
  return (director == ptr.director && title == ptr.title);
}
// comparison operator!= DRAMA
bool Drama::operator!=(Item &item) const { return !(*this == item); }
// comparison operator< DRAMA
bool Drama::operator<(Item &item) const {
  Drama &ptr = dynamic_cast<Drama &>(item);
  // sorted by directors name then title of movie
  if (director < ptr.director) {
    return true;
  } else if (director == ptr.director) {
    return title < ptr.title;
  }
  return false;
}
// comparison operator> DRAMA
bool Drama::operator>(Item &item) const {
  Drama &ptr = dynamic_cast<Drama &>(item);
  // return !(*this < ptr);
  if (this->operator==(item) || this->operator<(item)) {
    return false;
  }

  if (this->director > ptr.director) {
    return true;
  } else if (this->director == ptr.director) {
    return this->title > ptr.title;
  }
  return false;
}

// set Item
void Drama::setItem(istream &infile) {
  // cerr << "Starting setItem for Drama" << endl;

  // stock
  string stock;
  getline(infile, stock, ',');
  // cerr << "Stock: " << stock << endl;

  // Insert the director
  infile.get();
  getline(infile, director, ',');
  // cerr << "Director: " << director << endl;

  // Grab the title of movie
  infile.get();
  getline(infile, title, ',');
  // cerr << "Drama's title: " << title << endl;

  // insert the yearReleased
  infile >> yearReleased;
  // cerr << "yearReleased: " << yearReleased << endl;

  // set defaults for rest of properties
  // set the itemType into the Item class - D for DVD
  itemType = 'D';
  // set stock/ current copies of movie
  currCopies = 10;
  // set the genre to "D" for Drama into the Movie class
  genre = 'D';
  // set max number of copies in
  maxCopies = 26;

  infile.get();

  // cerr << "Finished Drama setItem" << endl;
}
// oop, setting partial (unique to only drama)
void Drama::setPartialItem(istream &inFile, char itemType, char genre) {
  itemType = itemType;
  genre = genre;
  // Steven Spielberg, Schindler's List
  inFile.get();
  getline(inFile, director, ',');
  inFile.get();
  getline(inFile, title, ',');

  // defaults
  yearReleased = 0;
  currCopies = 0;
  maxCopies = 0;
}

// print Drama
void Drama::print(ostream &output) const {
  // output format for Drama: D (genre), stock (currCopies), director,
  // title, yearReleased
  output << genre << " " << currCopies << " " << director << " " << title
         << " " << yearReleased << " " << endl;
}
