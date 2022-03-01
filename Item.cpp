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
ostream &operator<<(ostream &out, const Item& oneItem)
{
    oneItem.print(out);
    return out;
}
// default constructor - initialize privtates/protecteds
Item::Item()
{
    int maxCopies_ = 10; //max number of copies of item 
    int currCopies_ = ' '; // number of current copies of item
    char itemType_ = 'I'; // indicating it's a movie
    char mediaType_ = 'DVD'; // indicating the format (D - DVD)

}
// destructor  
Item::~Item()
{
}
 // decrement copies of private variables
void Item::borrowItem()
{    
}
// increment copies of private variables 
void Item::returnItem()
{
} 