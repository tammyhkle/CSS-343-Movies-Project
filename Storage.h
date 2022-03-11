/**
 * @file Storage.h
 * @author Le, Tammy
 * @brief Storage class - contains a map of the BSTree objects
 * @date 2022-02-26
 **/
#ifndef STORAGE_H
#define STORAGE_H

#include "BSTree.h"
#include "Item.h"

//#include "BSTree.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Storage {
  friend ostream &operator<<(ostream &output, const Storage &storage);

public:
  unordered_map<string, BSTree *> bstMap_;

  // default constructor
  Storage();
  // destructor
  ~Storage();

  // deleting value in BSTree
  void makeEmpty();
  // insert means add, changing to true/false (bool)
  bool insertItem(Item *item);
  // finds item object inside on of the BSTree object in BSTree Map
  bool retrieveItem(Item *item, Item *&retriever) const;
  // finds BSTree object stored in the BSTree Map - contains Item objects
  bool retrieveBSTree(Item *item, BSTree *&retriever) const;
  // prints the data of Item objects from BSTree
  void print(ostream &out) const;

private:
  /*Key of map are 2-element char arrays.
  The first element indicates the type of the items in
  the corresponding BSTree object and the second element
  indicates the subtype of the items in the BSTree objects
  that all have the same Item type and subtype
  */
  // unordered_map<string, BSTree*> bstMap_;
};

#endif // STORAGE_H