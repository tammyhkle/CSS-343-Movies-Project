// BSTree Class: binary search tree includes common actions of a BSTree
// insert and retrieve of node w BST
// This BSTree will 
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "Movie.h"
#include "Item.h"
#include "Storage.h"

using namespace std;

class BSTree {
  struct Node;
  friend ostream& operator<<(ostream&, const BSTree&); //operator output

public:
  //constructors
  BSTree(); //default 
  ~BSTree(); //destructor
  
  bool isEmpty() const; //returns bool if BSTree is empty or not
  void makeEmpty(Node*&); //makeEmpty - recursive delete helper
  bool insert(Item*); //inserts item into BSTree
  bool find(Item*); //find an item object from the BSTree
  bool retrieve(Item *target, Item *&retrieverItem) const;   //retrieves an item from the BSTree
  void printMovie(); // prints 

private:
  struct Node
    {
    Item *itemPtr; //pointer to data
    Node *left; //left subtree pointer
    Node *right; //right subtree pointer
    };
  Node* root; //root of the tree
  Node* retrieveHelper(Node*&, Item*) const; // retrieve helper function - recursive
  void print(ostream&) const; //private print method for ostream <<
};

#endif //BSTREE_H
