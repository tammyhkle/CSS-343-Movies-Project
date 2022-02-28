/*
  Drama class - sorting by Director, then Title of movie
  Notes:
    Drama = "D"
    Output format: D, stock, director, title, yearReleased
*/
#include "Drama.h"

//default constructor
Drama::Drama()
{
    director_ = "";
}
//destructor
Drama::~Drama() 
{
}
//return item type
char Drama::returnItemType() const
{
    return itemType_;
}
//return item type genre 
char Drama::returnItemGenre() const
{
    return movieGenre_;
}
// create() function can be used after the types of Movie
Item* Drama::create() const
{
    return new Drama;
}
//assignment operator
Item& Drama::operator=(const Item& item)
{
    const Drama& movieDrama = static_cast<const Drama&>(item);
    this->currCopies_ = movieDrama.currCopies_; //stock
    this->director_ = movieDrama.director_; //director
    this->title_ = movieDrama.title_; //title
    this->yearReleased_ = movieDrama.yearReleased_; //year it released
    return *this;
}
// virtual comparison operator==
bool Drama::operator==(const Item& item) const
{
    const Drama& movieDrama = static_cast<const Drama&>(item);
    return (this->title_ == movieDrama.title_ && this->director_ == movieDrama.director_);
}
// virtual comparison operator!=
bool Drama::operator!=(const Item& item) const
{
    return !this->operator==(item);
}
// virtual comparison operator<
bool Drama::operator<(const Item& item) const
{
    const Drama& movieDrama = static_cast<const Drama&>(item);
    // sorted by directors name then title of movie
    if (this->director_ < movieDrama.director_)
    {
        return true;
    }
    else if (this->director_ == movieDrama.director_)
    {
        return this->title_ < movieDrama.title_;
    }
    return false;
}
// virtual comparison operator>
bool Drama::operator>(const Item& item) const
{
    const Drama& movieDrama = static_cast<const Drama&>(item);
    if (this->operator==(item) || this->operator<(item))
    {
        return false;
    }
    if (this->director_ > movieDrama.director_)
    {
        return true;
    }
    else if (this->director_ == movieDrama.director_)
    {
        return this->title_ > movieDrama.title_;
    }
    return false;
}
//set Item
void Drama::setItem(istream& infile)
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
//print Drama
void Drama::print(ostream& out) const
{
    out << movieGenre_ << " " << currCopies_ << " " << director_ << " " << title_ << " " << yearReleased_ << " " << endl;
}






