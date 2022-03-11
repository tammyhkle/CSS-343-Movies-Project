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
ostream &operator<<(ostream &output, const Item &item) {
  item.print(output);
  return output;
}
// default constructor - initialize privtates/protecteds
Item::Item() {
  int maxCopies = 26;   // max number of copies of item
  int currCopies = ' '; // number of current copies of item
  char itemType = 'D';  // indicating the format (D - DVD)
  char mediaType = 'M'; // m for movie
}
// destructor
Item::~Item() {}
// decrement -1 copies of private variables (for each item borrowed)
// denoted as 'B'
void Item::borrowItem() {
  if (currCopies > 0) {
    currCopies--;
    return;
  }
  cout << "Can't borrow, out of stock." << endl;
}
// increment +1 copies of private variables (for each item returned)
// denoted as 'R'
void Item::returnItem() {
  if (currCopies < maxCopies) {
    currCopies++;
    return;
  }
  cout << "Can't return, no space." << endl;
}