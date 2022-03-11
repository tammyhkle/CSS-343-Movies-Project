/**
 * @file Storage.cpp
 * @author Le, Tammy
 * @brief Storage class - contains a map of the BSTree objects
 * @date 2022-02-26
 **/
#include "Storage.h"

// default constructor
Storage::Storage() {}
// destructor
Storage::~Storage() { makeEmpty(); }
// deleting value in BSTree
void Storage::makeEmpty() {
  for (auto i = bstMap.begin(); i != bstMap.end(); i++) {
    i->second->~BSTree();
    delete i->second;
  }
  bstMap.clear();
}
// insert means add, changing to true/false (bool)
bool Storage::insertItem(Item *item) {
  // cerr << "start of insertItem" << endl;
  BSTree *toStore;

  string key = "";
  key.push_back('D');
  key.push_back(item->getGenre());
  // cerr << "Key: " << key << endl;

  if (!(retrieveBSTree(item, toStore))) {
    // cerr << "creating new bst for bst map " << endl;
    BSTree *bst = new BSTree();
    bst->insert(item);
    // cerr << "insert item " << endl;
    bstMap.insert(std::make_pair(key, bst));
    // cerr << "insert pair: " << key << "," << bst << endl;
  } else {
    // cerr << "did retrieve key: " << key << endl;
    bstMap.at(key)->insert(item);
    // cerr << "Inserted item " << endl;
  }
  //Storage::print(cerr);
  // cerr << "Returning True " << endl;
  return true;
}
// finds item object inside on of the BSTree object in BSTree Map
bool Storage::retrieveItem(Item *item, Item *&retriever) const {
  // cerr << "start of retrieveItem" << endl;

  string key = "";
  key.push_back('D');
  // cerr << endl;
  key.push_back(item->getGenre());
  // cerr << "The Key: " << key << endl;

  // cerr << "Size of bstMap: " << bstMap_.size() << endl;
  // cerr << endl;
  // printing out key to validate if it's checking
  for (auto i = bstMap.begin(); i != bstMap.end(); i++) {
    // cerr << "Key: " << i->first << endl;
    if (i->first == key) {
      if (i->second->retrieve(item, retriever)) {
        return true;
      }
    }
  }
  // cerr << "Failed to find item" << endl;
  return false;

}
// finds BSTree object stored in the BSTree Map - contains Item objects
bool Storage::retrieveBSTree(Item *item, BSTree *&retriever) const {
  // cerr << "start of retrieveBSTree" << endl;

  string key = "";
  // key.push_back(item->getItemType());
  key.push_back('D');
  key.push_back(item->getGenre());
  // cerr << "Key: " << key << endl;

  if (!(bstMap.find(key) == bstMap.end())) {
    // cerr << "did retrieve" << endl;
    retriever = (bstMap.at(key));
    return true;
  } else {
    // cerr << "did not retrieve" << endl;
    retriever = nullptr;
    return false;
  }
}
// prints the data of Item objects from BSTree
void Storage::print(ostream &out) const {
  for (auto i = bstMap.begin(); i != bstMap.end(); i++) {
    // cerr << i->first;
    out << *i->second;
  }
}
// ostream operator<<
ostream &operator<<(ostream &output, const Storage &storage) {
  storage.print(output);
  return output;
}
