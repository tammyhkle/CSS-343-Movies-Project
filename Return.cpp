/**
 * @file Return.cpp
 * @author Le, Tammy
 * @brief Return class
 * @date 2022-02-26
 **/
#include "Return.h"

// default constructor
Return::Return()
{
    theItem = nullptr;
    customer = nullptr;
}
// destructor
Return::~Return()
{
    theItem = nullptr;
    customer = nullptr;
}
// sets data for item and customer involved in the return transaction
bool Return::setData(istream& inFile)
{
    return;
}
// creates and returns new Return object
Transaction* Return::create() const
{
    return;
}
// overridden from Transaction; performs return on movie and; adds return
// details to; customers's vector of transactions
void Return::doTransaction(Storage &, HashMap &)
{
    return;
}