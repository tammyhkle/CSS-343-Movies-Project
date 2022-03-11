/**
 * @file Comedy.cpp
 * @author Le, Tammy
 * @brief Comedy class - sorting by Title of movie, then yearReleased
 * Notes:
 * Comedy = "F" for funny
 * Output format: F, stock, director, title, yearReleased (same format as Drama)
 * @date 2022-02-26
 **/
#include "Comedy.h"
#include <iomanip>

// default constructor
Comedy::Comedy() { director = ""; }
// destructor
Comedy::~Comedy() {}
// return item type
char Comedy::getItemType() const { return itemType; }
// return item type genre
char Comedy::getGenre() const { return genre; }
// create() function can be used after the types of Movie
Item *Comedy::create() const { return new Comedy; }

// assignment operator
Item &Comedy::operator=(Item &item) {
  Comedy &movieComedy = dynamic_cast<Comedy &>(item);
  this->currCopies = movieComedy.currCopies;     // stock
  this->director = movieComedy.director;         // director
  this->title = movieComedy.title;               // title
  this->yearReleased = movieComedy.yearReleased; // year it released
  return *this;
}

// virtual comparison operator== COMEDY
bool Comedy::operator==(Item &item) const // add const in parameters
{
  Comedy &ptr = dynamic_cast<Comedy &>(item); // add const in front of comedy
  // cerr << "Start: Comedy check log for title/ director EQUALS == operator "
  // << endl;
  return (this->title == ptr.title &&
          this->yearReleased == ptr.yearReleased);
}
// virtual comparison operator!= COMEDY
bool Comedy::operator!=(Item &item) const {
  Comedy &ptr = dynamic_cast<Comedy &>(item);
  return !this->operator==(ptr);
}
//  comparison operator< COMEDY
bool Comedy::operator<(Item &item) const {
  Comedy &ptr = dynamic_cast<Comedy &>(item);
  // sorted by Title of movie, then directors name
  // cerr << "Start: Comedy check log for title/ director LESS THAN operator "
  // << endl;
  if (title < ptr.title) {
    // cerr << "Title is < item.title (is less than): " << title << " < " <<
    // ptr.title << endl;
    return true;
  } else if (title == ptr.title) {
    // cerr << "Title is == item.title: " << title << " == " << ptr.title <<
    // endl;
    return yearReleased < ptr.yearReleased;
  }
  // cerr << "Director < item.director (is less than): " << director << " < "
  // << ptr.director << endl;
  return false;
}
// comparison operator> COMEDY
bool Comedy::operator>(Item &item) const {
  Comedy &ptr = dynamic_cast<Comedy &>(item);
  // cerr << "Start: Comedy check log for title/ director GREATER THAN operator
  // " << endl;
  // return !(*this < ptr);
  // const Comedy& aComedy = dynamic_cast<const Comedy&>(item);

  if (this->operator==(item) || this->operator<(item)) {
    return false;
  }

  if (this->title > ptr.title) {
    return true;
  } else if (this->title == ptr.title) {
    return this->yearReleased > ptr.yearReleased;
  }
  return false;
}
// set Item
void Comedy::setItem(istream &infile) {
  // cerr << "Starting setItem for Comedy" << endl;

  // stock
  string stock;
  getline(infile, stock, ',');
  // cerr << "Stock: " << stock << endl;

  // Insert the director
  infile.get(); // grab empty space and delete
  getline(infile, director, ',');
  // cerr << "Director: " << director << endl;

  // Grab the title of movie
  infile.get(); // grab empty space and delete
  getline(infile, title, ',');
  // cerr << "Comedy's title: " << title << endl;

  // insert the yearReleased
  infile >> yearReleased;
  // cerr << "yearReleased: " << yearReleased << endl;

  // set defaults for rest of properties
  // set the itemType into the Item class - D for DVD
  itemType = 'D';
  // set stock/ current copies of movie
  currCopies = 10;
  // set the genre to "F" (Funny) for Comedy into the Movie class
  genre = 'F';
  // set max number of copies
  maxCopies = 26;

  infile.get();

  // cerr << "Finished Comedy setItem" << endl;
}
// oop, setting partial (unique to only comedy)
void Comedy::setPartialItem(istream &inFile, char itemType, char genre) {
  itemType = itemType;
  genre = genre;
  // Pirates of the Caribbean, 2003
  inFile.get();
  getline(inFile, title, ',');
  inFile >> yearReleased;

  // defaults
  director = "Default";
  currCopies = 0;
  maxCopies = 0;
}
// print Comedy
void Comedy::print(ostream &output) const {
  output << genre << " " << currCopies << " " << director << " " << title
         << " " << yearReleased << " " << endl;
}
