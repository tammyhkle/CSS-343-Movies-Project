/**
 * @file History.cpp
 * @author Le, Tammy
 * @brief History class
 * @date 2022-02-26
 **/
#include "History.h"

// constructor for class History
History::History() 
{
    customerID_ = 0;
}
// destrcutor for History
History::~History() 
{}
//get customer ID
int History::getCustomerID()
{
    return customerID_;
}
// setData() method
bool History::setData(istream& inFile)
{
    inFile >> customerID_;
    //cerr << "Customer ID: " << customerID_ << endl;
    return true;
}
// create method to create and return a new History object pointer
Transaction* History::create() const
{
    return new History;
}
// displays transaction history of customer with ID equal to value of data member custID
void History::doTransaction(Storage& , HashMap& customerMap)
{
    //print history of the customer w/ customerID
    // cerr << "Start of doTransaction for History " << endl;
    //for (auto t : customerMap.getCustomer(customerID_)->history_){
        //cerr << t;
    //}
    return;
}