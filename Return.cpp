/**
 * @file Return.cpp
 * @author Le, Tammy
 * @brief Return class
 * @date 2022-02-26
 **/
#include "Return.h"

// default constructor
Return::Return() {
  theItem = nullptr;
  customerID = 0;
}
// destructor
Return::~Return() {}
// get customer ID
int Return::getCustomerID() { return customerID; }
// sets data for item and customer involved in the return transaction
bool Return::setData(istream &inFile) {
  char itemType;
  char genre;

  inFile >> customerID;
  inFile >> itemType;
  inFile >> genre;

  theItem = this->movieFac.create(genre);
  // checking genre
  if (theItem == nullptr) {
    //cerr << "Wrong Item Type " << endl;
    return false;
  }
  // setting data
  theItem->setPartialItem(inFile, itemType, genre);
  return true;
}
// creates and returns new Return object
Transaction *Return::create() const { return new Return; }
// overridden from Transaction; performs return on movie and; adds return
// details to; customers's vector of transactions
void Return::doTransaction(Storage &storageMap, HashMap &customersMap) {
  Item *temp = nullptr;
  // Storage tempStorage = storageMap;
  if (!storageMap.retrieveItem(theItem, temp)) {
    //cerr << "Cannot find item" << endl;
    return;
  } else {
    Customer *tempCustomer;
    tempCustomer = customersMap.getCustomer(customerID);
    tempCustomer->addHistory(this);
    //cerr << "Added to history " << endl;

    //cerr << "Return - Item is found" << endl;
    temp->returnItem();
    //cerr << "Item is returned" << endl;
  }
}