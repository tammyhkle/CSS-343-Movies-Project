/**
 * @file Classics.cpp
 * @author Le, Tammy
 * @brief Classics class - sorting by Release Date, then by Major Actor
 * Notes:
 * Classics = "C"
 * Output format: C, stock, director, title, majorActor, releaseDate
 * @date 2022-02-26
 **/
#include "Classics.h"

// default constructor
Classics::Classics() { director = ""; }
// destructor
Classics::~Classics() {}
// return item type
char Classics::getItemType() const { return itemType; }
// return item type genre
char Classics::getGenre() const { return genre; }
// create() function can be used after the types of Movie
Item *Classics::create() const {
  // cerr << "Create new classics" << endl;
  return new Classics;
}

// assignment operator
Item &Classics::operator=(Item &item) {
  const Classics &movieClassics = dynamic_cast<const Classics &>(item);
  this->currCopies = movieClassics.currCopies;       // stock
  this->director = movieClassics.director;           // director
  this->title = movieClassics.title;                 // title
  this->majorActor = movieClassics.majorActor;       // majorActor
  this->monthReleased = movieClassics.monthReleased; // date it released
  this->yearReleased = movieClassics.yearReleased;   // date it released
  return *this;
}

// virtual comparison operator== CLASSICS
bool Classics::operator==(Item &item) const {
  Classics &ptr = dynamic_cast<Classics &>(item);
  return (majorActor == ptr.majorActor &&
          yearReleased == ptr.yearReleased &&
          monthReleased == ptr.monthReleased);
}

// virtual comparison operator!= CLASSICS
bool Classics::operator!=(Item &item) const {
  Classics &ptr = dynamic_cast<Classics &>(item);
  return !this->operator==(ptr);
}

// virtual comparison operator< (slighly different than drama and comedy)
// CLASSICS
bool Classics::operator<(Item &item) const {
  Classics &ptr = dynamic_cast<Classics &>(item);
  // sorted by Release Date, then by Major Actor
  if (yearReleased < ptr.yearReleased) {
    return true;
  } else if (yearReleased == ptr.yearReleased &&
             monthReleased == ptr.monthReleased) {
    if (lastName < ptr.lastName) {
      return true;
    }
  } else if (yearReleased == ptr.yearReleased) {
    return monthReleased < ptr.monthReleased;
  } else {
    return false;
  }
  return true;
}

// virtual comparison operator> CLASSICS
bool Classics::operator>(Item &item) const {
  Classics &ptr = dynamic_cast<Classics &>(item);
  // return !(*this < ptr);
  if (yearReleased > ptr.yearReleased) {
    return true;
  } else if (yearReleased == ptr.yearReleased &&
             monthReleased == ptr.monthReleased) {
    return majorActor > ptr.majorActor;
  } else if (yearReleased == ptr.yearReleased) {
    return monthReleased > ptr.monthReleased;
  } else {
    return false;
  }
}

// set Item
void Classics::setItem(istream &infile) {
  // cerr << "Starting Classics setItem" << endl;

  // stock
  string stock;
  getline(infile, stock, ',');
  // cerr << "Stock: " << stock << endl;

  // Insert the director
  infile.get();
  getline(infile, director, ',');
  // cerr << "director: " << director << endl;

  // Grab the title of movie
  infile.get();
  getline(infile, title, ',');
  // cerr << "title: " << title << endl;

  // Major actor
  infile >> firstName;
  infile >> lastName;
  majorActor = firstName + " " + lastName;
  // cerr << "majorActor: " << majorActor_ << endl;

  // insert the monthReleased
  infile >> monthReleased;
  // cerr << "monthReleased: " << monthReleased_ << endl;

  // get (and ignore) blank before year
  infile.get();

  // insert the yearReleased
  infile >> yearReleased;

  // set defaults for rest of properties
  // set the itemType into the Item class - D for DVD
  itemType = 'D';
  // set stock/ current copies of movie
  currCopies = 10;
  // set the genre to "C" for Classics into the Movie class
  genre = 'C';
  // set max number of copies
  maxCopies = 100;

  infile.get();

  // cerr << "Finished Classics setItem" << endl;
}
// oop, setting partial (unique to only classics)
void Classics::setPartialItem(istream &inFile, char itemType, char genre) {
  itemType = itemType;
  genre = genre;
  // 9 1938 Katherine Hepburn
  inFile >> monthReleased;
  inFile >> yearReleased;
  // Major actor
  inFile >> firstName;
  inFile >> lastName;
  majorActor = firstName + " " + lastName;

  // defaults
  director = "Default";
  title = "Default Title";
  currCopies = 0;
  maxCopies = 0;
}

// print Classics
void Classics::print(ostream &output) const {
  // output format for classics: C (genre), stock (currCopies), director, title,
  // majorActor, then date it released (monthReleased then yearReleased)
  output << genre << " " << currCopies << " " << director << " " << title
         << " " << majorActor << " " << monthReleased << " " << yearReleased
         << " " << endl;
}
