/**
 * @file BSTree.h
 * @author Le, Tammy
 * @brief BSTree class - Binary search tree includes commons actions of a BSTree
 * Notes:
 * Storing and retrieving Item objects of movie
 * Movie are being compared to other movie object
 * Uses inorder traversal to sort
 * @date 2022-02-26
 **/
#ifndef BSTREE_H
#define BSTREE_H

#include "Item.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// forward reference to Item Class
class Item;

class BSTree {
  struct Node;
  friend class Item;
  friend ostream &operator<<(ostream &out, const BSTree &bst);

public:
  // default constructor
  BSTree();
  // destructor
  ~BSTree();

  // returns bool if BSTree is empty or not
  bool isEmpty() const;
  // makeEmpty - recursive delete helper
  void makeEmpty(Node *&);
  // inserts item into BSTree
  bool insert(Item *);
  // find an item object from the BSTree
  bool find(Item *);
  // retrieves an item from the BSTree
  bool retrieve(Item *target, Item *&retrieverItem) const;
  // prints
  void printMovie();

private:
  struct Node {
    Item *itemPtr;
    Node *left;
    Node *right;
  };
  Node *root;
  // retrieve helper function - recursive
  Node *retrieveHelper(Node *&, Item *) const;
  // private print for ostream <<
  void print(ostream &out) const;
};

#endif // BSTREE_H
