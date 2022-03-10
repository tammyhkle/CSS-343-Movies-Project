/**
 * @file DisplayInventory.h
 * @author Le, Tammy
 * @brief Transaction class
 * @date 2022-02-26
 **/
#include "DisplayInventory.h"

// default constructor
DisplayInventory::DisplayInventory()
{}
// destructor
DisplayInventory::~DisplayInventory()
{}
//get customer ID
int DisplayInventory::getCustomerID()
{
    return 0;
}
// virtual create method
Transaction* DisplayInventory::create() const
{
    return new DisplayInventory;
}
// virtual set data method
bool DisplayInventory::setData(istream& )
{
    return true;
}
// displays the storage 
void DisplayInventory::doTransaction(Storage& storage, HashMap& )
{
    cout << "Movie Inventory: " << endl;
    cout << storage << endl;
    return;
}