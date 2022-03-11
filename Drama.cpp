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
Drama::Drama() { director_ = ""; }

// destructor
Drama::~Drama() {}

// return item type
char Drama::getItemType() const { return itemType_; }

// return item type genre
char Drama::getGenre() const { return genre_; }

// create() function can be used after the types of Movie
Item *Drama::create() const { return new Drama; }

// assignment operator
Item &Drama::operator=(Item &item) {
  const Drama &movieDrama = static_cast<const Drama &>(item);
  this->currCopies_ = movieDrama.currCopies_;     // stock
  this->director_ = movieDrama.director_;         // director
  this->title_ = movieDrama.title_;               // title
  this->yearReleased_ = movieDrama.yearReleased_; // year it released
  return *this;
}
// comparison operator== DRAMA
bool Drama::operator==(Item &item) const {
   Drama &ptr = static_cast< Drama &>(item);
    //prints
    cerr << "Drama Director: "  << director_ << endl;
    cerr << "movieDrama Director: "  << ptr.director_ << endl;
    cerr << "Drama Title: "  << title_ << endl;
    cerr << "movieDrama Title: "  << ptr.title_ << endl;
    return (director_ == ptr.director_ && title_ == ptr.title_);
}
// comparison operator!= DRAMA
bool Drama::operator!=(Item &item) const {
	return !(*this == item);
}
// comparison operator< DRAMA
bool Drama::operator<(Item &item) const {
  Drama &ptr = static_cast< Drama &>(item);
  // sorted by directors name then title of movie
  if (director_ < ptr.director_) 
  {
    return true;
  } 
  else if (director_ == ptr.director_) 
  {
    return title_ < ptr.title_;
  }
  return false;
}
// comparison operator> DRAMA
bool Drama::operator>(Item &item) const {
  Drama &ptr = static_cast<Drama &>(item);
  //return !(*this < ptr);
   if (this->operator==(item) || this->operator<(item)) {
      return false;
   }

   if (this->director_ > ptr.director_) {
      return true;
   }
   else if (this->director_ == ptr.director_) {
      return this->title_ > ptr.title_;
   }
   return false;
}

// set Item
void Drama::setItem(istream &infile) {
  cerr << "Starting setItem for Drama" << endl;

  //stock 
  string stock;
  getline(infile, stock, ',');
  cerr << "Stock: " << stock << endl;

  // Insert the director
  infile.get();
  getline(infile, director_, ',');
  cerr << "Director: " << director_ << endl;

  // Grab the title of movie
  infile.get();
  getline(infile, title_, ',');
  cerr << "Drama's title: " << title_ << endl;

  // insert the yearReleased
  infile >> yearReleased_;
  cerr << "yearReleased: " << yearReleased_ << endl;

  // set defaults for rest of properties
  // set the itemType into the Item class - D for DVD
  itemType_ = 'D';
  // set stock/ current copies of movie
  currCopies_ = 10;
  // set the genre_ to "D" for Drama into the Movie class
  genre_ = 'D';
  // set max number of copies in
  maxCopies_ = 26;

  infile.get();

  cerr << "Finished Drama setItem" << endl;
}
// oop, setting partial (unique to only drama)
void Drama::setPartialItem(istream &inFile, char itemType, char genre)
{
  itemType_ = itemType;
  genre_ = genre;
  //Steven Spielberg, Schindler's List
  inFile.get();
  getline(inFile, director_, ',');
  inFile.get();
  getline(inFile, title_, ',');

  //defaults
  yearReleased_ = 0;
  currCopies_ = 0;
  maxCopies_ = 0;
}

// print Drama
void Drama::print(ostream &output) const {
  // output format for Drama: D (genre_), stock (currCopies_), director_,
  // title_, yearReleased_
  output << genre_ << " " << currCopies_ << " " << director_ << " " << title_
      << " " << yearReleased_ << " " << endl;
}
