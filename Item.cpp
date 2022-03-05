/**
 * @file Item.cpp
 * @author Le, Tammy
 * @brief Item class - Item is the nodes in the BSTree class
 * Notes:
 * The items in the BSTree have nodeData ptr (points to the movie)
 * Extenibles can be added (i.e. music)
 * @date 2022-02-26
 **/
#include "Item.h"

// ostream operator<<
ostream &operator<<(ostream &out, const Item &item) 
{
    item.print(out);
    return out;
}
// default constructor - initialize privtates/protecteds
Item::Item() 
{
    int maxCopies_ = 10;      // max number of copies of item
    int currCopies_ = ' ';    // number of current copies of item
    char itemType_ = 'Movie'; // indicating it's a movie
    char mediaType_ = 'DVD';  // indicating the format (D - DVD)
}
// destructor
Item::~Item() {}
// decrement -1 copies of private variables (for each item borrowed)
// denoted as 'B'
void Item::borrowItem() 
{
    if (currCopies_ > 0) 
    {
        currCopies_--;
        return;
    }
    cout << "Can't borrow, out of stock." << endl;
}
// increment +1 copies of private variables (for each item returned)
// denoted as 'R'
void Item::returnItem() 
{
    if (currCopies_ < maxCopies_)
    {
        currCopies_++;
        return;
    }
    cout << "Can't return, no space." << endl;
}