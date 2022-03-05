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
// virtual create method
Transaction* DisplayInventory::create() const
{
    return new DisplayInventory;
}
// virtual set data method
bool DisplayInventory::setData(istream &)
{}
// displays the catalogue
void DisplayInventory::doTransaction(Storage &, HashMap &)
{
    cout << catalouge;
    return;
}