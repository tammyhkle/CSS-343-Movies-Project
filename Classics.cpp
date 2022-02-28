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

//default constructor
Classics::Classics()
{
    director_ = "";
}
//destructor
Classics::~Classics() 
{
}
//return item type
char Classics::returnItemType() const
{
    return itemType_;
}
//return item type genre 
char Classics::returnItemGenre() const
{
    return movieGenre_;
}
// create() function can be used after the types of Movie
Item* Classics::create() const
{
    return new Classics;
}
//assignment operator
Item& Classics::operator=(const Item& item)
{
    const Classics& movieClassics = static_cast<const Classics&>(item);
    this->currCopies_ = movieClassics.currCopies_; //stock
    this->director_ = movieClassics.director_; //director
    this->title_ = movieClassics.title_; //title
    this->yearReleased_ = movieClassics.yearReleased_; //year it released
    return *this;
}
// virtual comparison operator==
bool Classics::operator==(const Item& item) const
{
    const Classics& movieClassics = static_cast<const Classics&>(item);
    return (this->title_ == movieClassics.title_ && this->director_ == movieClassics.director_);
}
// virtual comparison operator!=
bool Classics::operator!=(const Item& item) const
{
    return !this->operator==(item);
}
// virtual comparison operator<
bool Classics::operator<(const Item& item) const
{
    const Classics& movieClassics = static_cast<const Classics&>(item);
    // sorted by directors name then title of movie
    if (this->director_ < movieClassics.director_)
    {
        return true;
    }
    else if (this->director_ == movieClassics.director_)
    {
        return this->title_ < movieClassics.title_;
    }
    return false;
}
// virtual comparison operator>
bool Classics::operator>(const Item& item) const
{
    const Classics& movieClassics = static_cast<const Classics&>(item);
    if (this->operator==(item) || this->operator<(item))
    {
        return false;
    }
    if (this->director_ > movieClassics.director_)
    {
        return true;
    }
    else if (this->director_ == movieClassics.director_)
    {
        return this->title_ > movieClassics.title_;
    }
    return false;
}
//set Item
void Classics::setItem(istream& infile)
{
    //Insert the director
    getline(infile, director_, ','); 
    // Grab the title of movie
    infile.get();
    // insert the yearReleased
    infile >> yearReleased_;
    // set the itemType into the Item class
    itemType_ = 'DVD'; 
    // set stock/ current copies of movie
    currCopies_ = 10;
    // set the movieGenre to "D" for Drama into the Movie class
    movieGenre_ = 'D'; 
    //set max number of copies in
    maxCopies_ = 10;
}
//print Classics
void Classics::print(ostream& out) const
{
    out << movieGenre_ << " " << currCopies_ << " " << director_ << " " << title_ << " " << yearReleased_ << " " << endl;
}
