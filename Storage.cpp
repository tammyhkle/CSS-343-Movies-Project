/**
 * @file Storage.cpp
 * @author Le, Tammy
 * @brief Storage class - contains a map of the BSTree objects 
 * @date 2022-02-26
 **/
#include "Storage.h"
  // default constructor
  Storage::Storage(){}
  // destructor
  Storage::~Storage() 
  {
      makeEmpty();
  }
  // deleting value in BSTree
  void Storage::makeEmpty()
  {
  }
  // insert means add, changing to true/false (bool)
  bool Storage::insertItem(Item *item)
  {
      return;
  }
  // finds item object inside on of the BSTree object in BSTree Map
  bool Storage::retrieveItem(Item* item, Item*& retriever) const
  {
      return;
  }
  // finds BSTree object stored in the BSTree Map - contains Item objects
  bool Storage::retrieveBSTree(Item* item, BSTree*& retriever) const
  {
      return;
  }
  // prints the data of Item objects from BSTree
  void Storage::print(ostream& out) const
  {
  }
  //ostream operator<<
  ostream &operator<<(ostream &out, const Storage &storage)
  {
      storage.print(out);
      return out;
  }

