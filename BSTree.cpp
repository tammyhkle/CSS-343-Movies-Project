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
//inserts item (movie object) into BSTree; pointer of movie object needs same type of movie obj. tht BSTree uses
bool BSTree::insert(Item* insertPtr)
{
    //first, we need to check for duplicates
    if (find(insertPtr))
    {
        return false;
    }
    //then, verify if BSTree is empty or not
    if (isEmpty())
    {
        root = new Node();
        root->itemPtr = insertPtr;
        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
        Node *current = root;
        bool inserted = false;
        //determine whether to go into the left or right subtree
        while (!inserted)
        {
            if (*insertPtr < *current->itemPtr)
            {
                if (current->left == nullptr)
                {
                    Node *temp = new Node();
                    temp->itemPtr = insertPtr;
                    temp->left = nullptr;
                    temp->right = nullptr;
                    current->left = temp;
                }
                else
                {
                    current = current->left;
                } 
            }
            else
            {
                if (current->right == nullptr)
                {
                    Node *temp = new Node();
                    temp->itemPtr = insertPtr;
                    temp->left = nullptr;
                    temp->right = nullptr;
                    current->right = temp;
                }
                else
                {
                    current = current->right;
                } 
            }
        }
     }
     return true;
}
//find an item object from the BSTree 
bool BSTree::find(Item *target)
{
    Node *current = root;
    bool found = false;
    while (!found)
    {
        if (current == nullptr)
        {
            break;
        }
        else if (*current->itemPtr == *target)
        {
            found = true;
            break;
        }
        else if (*target > *current->itemPtr)
        {
            current = current->right;
        }
        else if (*target < *current->itemPtr)
        {
            current = current->left;
        }
    }
    return found;
}







