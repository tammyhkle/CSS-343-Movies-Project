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
Classics::Classics() { 
  director_ = ""; 
}
// destructor
Classics::~Classics() {}
// return item type
char Classics::getItemType() const 
{ 
  return itemType_; 
}
// return item type genre
char Classics::getGenre() const 
{ 
  return genre_; 
}
// create() function can be used after the types of Movie
Item *Classics::create() const {
  cerr << "Create new classics" << endl;
  return new Classics;
}

// assignment operator
Item &Classics::operator=(Item &item) {
  const Classics &movieClassics = static_cast<const Classics &>(item);
  this->currCopies_ = movieClassics.currCopies_;       // stock
  this->director_ = movieClassics.director_;           // director
  this->title_ = movieClassics.title_;                 // title
  this->majorActor_ = movieClassics.majorActor_;       // majorActor
  this->monthReleased_ = movieClassics.monthReleased_; // date it released
  this->yearReleased_ = movieClassics.yearReleased_;   // date it released
  return *this;
}

// virtual comparison operator== CLASSICS
bool Classics::operator==(Item &item) const {
  Classics &ptr = static_cast<Classics &>(item);
  return (majorActor_ == ptr.majorActor_ &&
          yearReleased_ == ptr.yearReleased_ &&
          monthReleased_ == ptr.monthReleased_);
}

// virtual comparison operator!= CLASSICS
bool Classics::operator!=(Item &item) const { 
  Classics &ptr = static_cast<Classics &>(item);
  return !this->operator==(ptr); 
}

// virtual comparison operator< (slighly different than drama and comedy)
// CLASSICS
bool Classics::operator<(Item &item) const {
  Classics &ptr = static_cast<Classics &>(item);
  // sorted by Release Date, then by Major Actor
  if (yearReleased_ < ptr.yearReleased_) 
  {
    return true;
  } 
  else if (yearReleased_ == ptr.yearReleased_ && monthReleased_ == ptr.monthReleased_) 
    {
      if (lastName_ < ptr.lastName_)
      {
        return true;
      }
    }
  else if ( yearReleased_ == ptr.yearReleased_)
  {
    return monthReleased_ < ptr.monthReleased_;
  }
  else 
  {
    return false;
  }
}

// virtual comparison operator> CLASSICS
bool Classics::operator>(Item &item) const {
    Classics &ptr = static_cast<Classics &>(item);
    //return !(*this < ptr);
    if (yearReleased_ > ptr.yearReleased_) 
  {
    return true;
  } 
  else if (yearReleased_ == ptr.yearReleased_ && monthReleased_ == ptr.monthReleased_) 
    {
      return majorActor_ > ptr.majorActor_;
    }
  else if ( yearReleased_ == ptr.yearReleased_)
  {
    return monthReleased_ > ptr.monthReleased_;
  }
  else 
  {
    return false;
  }
}

// set Item
void Classics::setItem(istream &infile) {
  cerr << "Starting Classics setItem" << endl;

  // stock
  string stock;
  getline(infile, stock, ',');
  cerr << "Stock: " << stock << endl;

  // Insert the director
  infile.get();
  getline(infile, director_, ',');
  cerr << "director: " << director_ << endl;

  // Grab the title of movie
  infile.get();
  getline(infile, title_, ',');
  cerr << "title: " << title_ << endl;

  // Major actor
  infile >> firstName_;
  infile >> lastName_;
  majorActor_ = firstName_ + " " + lastName_;
  cerr << "majorActor: " << majorActor_ << endl;

  // insert the monthReleased
  infile >> monthReleased_;
  cerr << "monthReleased: " << monthReleased_ << endl;

  // get (and ignore) blank before year
  infile.get();

  // insert the yearReleased
  infile >> yearReleased_;
  cerr << "yearReleased: " << yearReleased_ << endl;

  // set defaults for rest of properties
  // set the itemType into the Item class - D for DVD
  itemType_ = 'D';
  // set stock/ current copies of movie
  currCopies_ = 10;
  // set the genre_ to "C" for Classics into the Movie class
  genre_ = 'C';
  // set max number of copies
  maxCopies_ = 100;

  infile.get();

  cerr << "Finished Classics setItem" << endl;
}
// oop, setting partial (unique to only classics)
void Classics::setPartialItem(istream &inFile, char itemType, char genre) {
  itemType_ = itemType;
  genre_ = genre;
  // 9 1938 Katherine Hepburn
  inFile >> monthReleased_;
  inFile >> yearReleased_;
  // Major actor
  inFile >> firstName_;
  inFile >> lastName_;
  majorActor_ = firstName_ + " " + lastName_;

  //defaults
  director_ = "Default";
  title_ = "Default Title";
  currCopies_ = 0;
  maxCopies_ = 0;
}

// print Classics
void Classics::print(ostream &output) const {
  // output format for classics: C (genre), stock (currCopies), director, title,
  // majorActor, then date it released (monthReleased then yearReleased)
  output << genre_ << " " << currCopies_ << " " << director_ << " " << title_
         << " " << majorActor_ << " " << monthReleased_ << " " << yearReleased_
         << " " << endl;
}
