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
    theItem_ = nullptr;
    customerID_ = 0;
}
// destructor
Return::~Return()
{
}
//get customer ID
int Return::getCustomerID()
{
    return customerID_;
}
// sets data for item and customer involved in the return transaction
bool Return::setData(istream& inFile)
{
    char itemType;
    char genre;  

    inFile >> customerID_;
    inFile >> itemType;
    inFile >> genre;

    theItem_ = this->movieFac_.create(genre);
    //checking genre
    if(theItem_ == nullptr)
    {
        cerr << "Wrong Item Type " << endl;
        return false;
    }
    //setting data
    theItem_->setPartialItem(inFile, itemType, genre);
    return true;
}
// creates and returns new Return object
Transaction* Return::create() const
{
    return new Return;
}
// overridden from Transaction; performs return on movie and; adds return
// details to; customers's vector of transactions
void Return::doTransaction(Storage& storageMap, HashMap& customersMap)
{
    Item* temp = nullptr;
    //Storage tempStorage = storageMap;
    if (!storageMap.retrieveItem(theItem_, temp))
    {
        cerr << "Cannot find item" << endl;
        return;
    }
    else
    {
        cerr << "Item found with this Key Temp: " << temp->getItemType() << temp->getGenre() << endl;
        Customer* tempCustomer;
        tempCustomer = customersMap.getCustomer(customerID_);
        tempCustomer->addHistory(this); 
        cerr << "Added to history " << endl;

        cerr << "Return - Item is found" << endl;
        temp->returnItem();
        cerr << "Item is returned" << endl;
    }
}