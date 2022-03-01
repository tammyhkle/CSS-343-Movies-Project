/**
 * @file BSTree.cpp
 * @author Le, Tammy
 * @brief BSTree class - Binary search tree includes commons actions of a BSTree
 * Notes:
 * Storing and retrieving Item objects of movie 
 * Movie are being compared to other movie object 
 * Uses inorder traversal to sort 
 * @date 2022-02-26
 **/

#include "BSTree.h"
#include "Item.h"

#include <stack>

using namespace std;

//operator output
ostream &operator<<(ostream &out, const BSTree &bst)
{
    bst.print(out);
    return out;
}
//default constructor, set root to nullptr
BSTree::BSTree():root(nullptr)
{
}
//destructor - deletes all nodes in BSTree
BSTree::~BSTree()
{
    makeEmpty(root);
    root = nullptr;
}
//returns bool if BSTree is empty or not; will return true is the BSTree is empty
bool BSTree::isEmpty() const
{
    if (root == nullptr)
    {
        return true;
    }
    return false;
}
//makeEmpty - recursive delete helper
void BSTree::makeEmpty(Node*& ptr)
{
    if (ptr != nullptr)
    {
        makeEmpty(ptr->left);
        makeEmpty(ptr->right);
        delete ptr->itemPtr;
        ptr->itemPtr = nullptr;
        delete ptr;
        ptr = nullptr;
    }
}







