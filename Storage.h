#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include "BSTree.h"
#include "RentalManager.h"

using namespace std;

class Storage {
public:
  //constructors
  Storage(); //default
  ~Storage(); //destructor

  void makeEmpty();
  bool insertItem(Item*); //insert means add, changing to true/false (bool)
  Item& retrieveItem(string itemName) const;
  bool retrieve(BSTree*); // add retrieve BST*
  void printStorage(); // add print function

private:
//Key of map are 2-element char arrays. The first element indicates the type of the items in the corresponding BSTree object and the second element indicates the subtype of the items in the BSTree objects that all have the same Item type and subtype
  unordered_map<string, BSTree*> BSTreeMap;
};
#endif //STORAGE_H