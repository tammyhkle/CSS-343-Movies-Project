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

//default constructor
Comedy::Comedy()
{
    director_ = "";
}
//destructor
Comedy::~Comedy() 
{
}
//return item type
char Comedy::returnItemType() const
{
    return itemType_;
}
//return item type genre 
char Comedy::returnItemTypeGenre() const
{
    return movieGenre_;
}
// create() function can be used after the types of Movie
Item* Comedy::create() const
{
    return new Comedy;
}
//assignment operator
Item& Comedy::operator=(const Item &item)
{
    const Comedy& movieComedy = static_cast<const Comedy&>(item);
    this->currCopies_ = movieComedy.currCopies_; //stock
    this->director_ = movieComedy.director_; //director
    this->title_ = movieComedy.title_; //title
    this->yearReleased_ = movieComedy.yearReleased_; //year it released
    return *this;
}
// virtual comparison operator==
bool Comedy::operator==(const Item &item) const
{
    const Comedy& movieComedy = static_cast<const Comedy&>(item);
    return (this->title_ == movieComedy.title_ && this->director_ == movieComedy.director_);
}
// virtual comparison operator!=
bool Comedy::operator!=(const Item &item) const
{
    return !this->operator==(item);
}
// virtual comparison operator<
bool Comedy::operator<(const Item &item) const
{
    const Comedy& movieComedy = static_cast<const Comedy&>(item);
    // sorted by Title of movie, then directors name 
    if (this->title_ < movieComedy.title_)
    {
        return true;
    }
    else if (this->title_ == movieComedy.title_)
    {
        return this->director_ < movieComedy.director_;
    }
    return false;
}
// virtual comparison operator>
bool Comedy::operator>(const Item &item) const
{
    const Comedy& movieComedy = static_cast<const Comedy&>(item);
    if (this->operator==(item) || this->operator<(item))
    {
        return false;
    }
    if (this->director_ > movieComedy.director_)
    {
        return true;
    }
    else if (this->director_ == movieComedy.director_)
    {
        return this->title_ > movieComedy.title_;
    }
    return false;
}
//set Item
void Comedy::setItem(istream &infile)
{
    //Insert the director
    getline(infile, director_, ','); 
    // Grab the title of movie
    infile.get();
    // insert the yearReleased
    infile >> yearReleased_;
    // set the itemType into the Item class
    itemType_ = 'Movie'; 
    // set stock/ current copies of movie
    currCopies_ = 10;
    // set the movieGenre to "F" (Funny) for Comedy into the Movie class
    movieGenre_ = 'F'; 
    //set max number of copies in
    maxCopies_ = 10;
}
//print Comedy
void Comedy::print(ostream &out) const
{
    out << movieGenre_ << " " << currCopies_ << " " << director_ << " " << title_ << " " << yearReleased_ << " " << endl;
}






