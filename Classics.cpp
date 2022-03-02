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
#include <iomanip>

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
char Classics::getItemType() const
{
    return itemType_;
}
//return item type genre 
char Classics::getGenre() const
{
    return genre_;
}
// create() function can be used after the types of Movie
Item* Classics::create() const
{
    return new Classics;
}
//assignment operator
Item& Classics::operator=(const Item &item)
{
    const Classics& movieClassics = static_cast<const Classics&>(item);
    this->currCopies_ = movieClassics.currCopies_; //stock
    this->director_ = movieClassics.director_; //director
    this->title_ = movieClassics.title_; //title
    this->majorActor_ = movieClassics.majorActor_; //majorActor
    this->monthReleased_ = movieClassics.monthReleased_; //date it released
    this->yearReleased_ = movieClassics.yearReleased_; //date it released
    return *this;
}
// virtual comparison operator==
bool Classics::operator==(const Item &item) const
{
    const Classics& movieClassics = static_cast<const Classics&>(item);
    return (this->title_ == movieClassics.title_ && this->director_ == movieClassics.director_);
}
// virtual comparison operator!=
bool Classics::operator!=(const Item& item) const
{
    return !this->operator==(item);
}
// virtual comparison operator< (slighly different than drama and comedy)
bool Classics::operator<(const Item &item) const
{
    const Classics& movieClassics = static_cast<const Classics&>(item);
    // sorted by directors name then title of movie
    if (this->yearReleased_ < movieClassics.yearReleased_)
    {
        return true;
    }
    else if (this->yearReleased_ == movieClassics.yearReleased_)
    {
        if (this->monthReleased_ == movieClassics.monthReleased_)
        {
            return this->title_ < movieClassics.title_;
        }
        return this->monthReleased_ < movieClassics.monthReleased_;
    }
    return false;
}
// virtual comparison operator>
bool Classics::operator>(const Item &item) const
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
        return this->majorActor_ > movieClassics.majorActor_;
    }
    return false;
}
//set Item
void Classics::setItem(istream &infile)
{
    //Insert the director
    getline(infile, director_, ','); 
    // Grab the title of movie
    infile.get();
    // insert the monthReleased
    infile >> monthReleased_;
    // get (and ignore) blank before year
    infile.get();               
    // insert the yearReleased
    infile >> yearReleased_;
    
    // set defaults for rest of properties
    // set the itemType into the Item class - M for Movie
    itemType_ = 'M'; 
    // set stock/ current copies of movie
    currCopies_ = 10;
    // set the genre_ to "D" for Drama into the Movie class
    genre_ = 'C'; 
    //set max number of copies
    maxCopies_ = 26;
}
//print Classics
void Classics::print(ostream &out) const
{
    //output format for classics: C (genre), stock (currCopies), director, title, majorActor, then date it released (monthReleased then yearReleased)
    out << genre_ << " " << currCopies_ << " " << director_ << " " << title_ << " " << majorActor_ << " " << monthReleased_ << " " << yearReleased_ << " " << endl;
}
