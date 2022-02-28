#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "BSTree.h"
#include "Item.h"
#include "RentalManager.h"

using namespace std;

class Storage {
  friend ostream& operator<<(ostream&, const Storage&);

public:
  Storage(); //default constructor
  ~Storage(); //destructor

  void makeEmpty(); // deleting value in BSTree
  bool insertItem(Item*); //insert means add, changing to true/false (bool)
  bool retrieveItem(Item*, Item*&) const; // finds item object inside on of the BSTree object in BSTree Map 
  bool retrieveBSTree(Item*, BSTree*&) const; // finds BSTree object stored in the BSTree Map - contains Item objects
  void printStorage(ostream&) const; // printss the data of Item objects from BSTree

private:
  unordered_map<string, BSTree*> BSTreeMap; //Key of map are 2-element char arrays. The first element indicates the 
  //type of the items in the corresponding BSTree object and the second element indicates the subtype of the items in the BSTree objects that all have the same Item type and subtype

};
#endif //STORAGE_H