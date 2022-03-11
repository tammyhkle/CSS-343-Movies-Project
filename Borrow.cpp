/**
 * @file Borrow.cpp
 * @author Le, Tammy
 * @brief Borrow class
 * @date 2022-02-26
 **/
#include "Borrow.h"

// default constructor
Borrow::Borrow() {}
// constructor
Borrow::Borrow(Item *, Customer *) {}
// destructor
Borrow::~Borrow() {} // empty on purpose
// get customer ID
int Borrow::getCustomerID() { return customerID_; }
// create method
Transaction *Borrow::create() const { return new Borrow; }
// sets data using passed ifream
bool Borrow::setData(istream &inFile) // infile
{
  char itemType;
  char genre;

  inFile >> customerID_;
  inFile >> itemType;
  inFile >> genre;

  theItem_ = this->movieFac_.create(genre);
  // checking genre
  if (theItem_ == nullptr) {
    // cerr << "Wrong Item Type! " << endl;
    return false;
  }
  // setting data
  theItem_->setPartialItem(inFile, itemType, genre);
  theItem_->print(cerr);
  return true;
}
/*overridden from Transaction
performs Borrow on movie and
adds Borrow details to
customer's vector of transactions
*/
void Borrow::doTransaction(Storage &storageMap, HashMap &customersMap) {
  Item *temp = nullptr;
  // Storage tempStorage = storageMap;
  if (!storageMap.retrieveItem(theItem_, temp)) {
    // cerr << "Cannot find item" << endl;
    return;
  } else {
    // cerr << "Item found with this Key Temp: " << temp->getItemType() <<
    // temp->getGenre() << endl;
    Customer *tempCustomer;
    tempCustomer = customersMap.getCustomer(customerID_);
    tempCustomer->addHistory(this);
    // cerr << "Added to history " << endl;

    // cerr << "Borrow - Item is found" << endl;
    temp->borrowItem();
    // cerr << "Item is borrowed" << endl;
  }
}
