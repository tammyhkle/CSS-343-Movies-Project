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
Comedy::Comedy() { director_ = ""; }
// destructor
Comedy::~Comedy() {}
// return item type
char Comedy::getItemType() const { return itemType_; }
// return item type genre
char Comedy::getGenre() const { return genre_; }
// create() function can be used after the types of Movie
Item *Comedy::create() const { return new Comedy; }

// assignment operator
Item &Comedy::operator=(Item &item) {
  Comedy &movieComedy = static_cast<Comedy &>(item);
  this->currCopies_ = movieComedy.currCopies_;     // stock
  this->director_ = movieComedy.director_;         // director
  this->title_ = movieComedy.title_;               // title
  this->yearReleased_ = movieComedy.yearReleased_; // year it released
  return *this;
}

// virtual comparison operator== COMEDY
bool Comedy::operator==(Item &item) const // add const in parameters
{
  Comedy &ptr = static_cast<Comedy &>(item); // add const in front of comedy
  // cerr << "Start: Comedy check log for title/ director EQUALS == operator "
  // << endl;
  return (this->title_ == ptr.title_ &&
          this->yearReleased_ == ptr.yearReleased_);
}
// virtual comparison operator!= COMEDY
bool Comedy::operator!=(Item &item) const {
  Comedy &ptr = static_cast<Comedy &>(item);
  return !this->operator==(ptr);
}
//  comparison operator< COMEDY
bool Comedy::operator<(Item &item) const {
  Comedy &ptr = static_cast<Comedy &>(item);
  // sorted by Title of movie, then directors name
  // cerr << "Start: Comedy check log for title/ director LESS THAN operator "
  // << endl;
  if (title_ < ptr.title_) {
    // cerr << "Title is < item.title (is less than): " << title_ << " < " <<
    // ptr.title_ << endl;
    return true;
  } else if (title_ == ptr.title_) {
    // cerr << "Title is == item.title: " << title_ << " == " << ptr.title_ <<
    // endl;
    return yearReleased_ < ptr.yearReleased_;
  }
  // cerr << "Director_ < item.director_ (is less than): " << director_ << " < "
  // << ptr.director_ << endl;
  return false;
}
// comparison operator> COMEDY
bool Comedy::operator>(Item &item) const {
  Comedy &ptr = static_cast<Comedy &>(item);
  // cerr << "Start: Comedy check log for title/ director GREATER THAN operator
  // " << endl;
  // return !(*this < ptr);
  // const Comedy& aComedy = static_cast<const Comedy&>(item);

  if (this->operator==(item) || this->operator<(item)) {
    return false;
  }

  if (this->title_ > ptr.title_) {
    return true;
  } else if (this->title_ == ptr.title_) {
    return this->yearReleased_ > ptr.yearReleased_;
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
  getline(infile, director_, ',');
  // cerr << "Director: " << director_ << endl;

  // Grab the title of movie
  infile.get(); // grab empty space and delete
  getline(infile, title_, ',');
  // cerr << "Comedy's title: " << title_ << endl;

  // insert the yearReleased
  infile >> yearReleased_;
  // cerr << "yearReleased: " << yearReleased_ << endl;

  // set defaults for rest of properties
  // set the itemType into the Item class - D for DVD
  itemType_ = 'D';
  // set stock/ current copies of movie
  currCopies_ = 10;
  // set the genre_ to "F" (Funny) for Comedy into the Movie class
  genre_ = 'F';
  // set max number of copies
  maxCopies_ = 26;

  infile.get();

  // cerr << "Finished Comedy setItem" << endl;
}
// oop, setting partial (unique to only comedy)
void Comedy::setPartialItem(istream &inFile, char itemType, char genre) {
  itemType_ = itemType;
  genre_ = genre;
  // Pirates of the Caribbean, 2003
  inFile.get();
  getline(inFile, title_, ',');
  inFile >> yearReleased_;

  // defaults
  director_ = "Default";
  currCopies_ = 0;
  maxCopies_ = 0;
}
// print Comedy
void Comedy::print(ostream &output) const {
  // output format for Comedy: F (genre_), stock (currCopies_), director_,
  // title_, yearReleased_
  output << genre_ << " " << currCopies_ << " " << director_ << " " << title_
         << " " << yearReleased_ << " " << endl;
}
