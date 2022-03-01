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

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "Item.h"
#include "Movie.h"
#include "Storage.h"

using namespace std;

class Item; //reference to Item Class

class BSTree {
  struct Node;
  friend class Item;
  friend ostream &operator<<(ostream &out, const BSTree &bst); //operator output

public:
  BSTree(); //default constructor
  ~BSTree(); //destructor
  
  bool isEmpty() const; //returns bool if BSTree is empty or not
  void makeEmpty(Node*&); //makeEmpty - recursive delete helper
  bool insert(Item*); //inserts item into BSTree
  bool find(Item*); //find an item object from the BSTree
  bool retrieve(Item *target, Item *&retrieverItem) const; //retrieves an item from the BSTree
  void printMovie(); // prints 

private:
  struct Node
    {
    Item *itemPtr; //pointer to Item object in node
    Node *left; //node's left child ptr
    Node *right; //node's right child ptr
    };
  Node *root; //root of the tree
  Node *retrieveHelper(Node*&, Item*) const; // retrieve helper function - recursive
  void print(ostream &out) const; //private print for ostream <<
};

#endif //BSTREE_H
