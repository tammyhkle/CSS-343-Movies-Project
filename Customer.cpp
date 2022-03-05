/**
 * @file Customer.cpp
 * @author Le, Tammy
 * @brief Customer class - stores customers information, read from file
 * Notes
 * Includes unique 4 digit customerID
 * firstName, lastName
 * history vector - stores transactions of customer
 * @date 2022-02-26
 **/
#include "Customer.h"

// default constructor
Customer::Customer() {}
// destructor
Customer::~Customer() {}

// adding the transaction to customer's history
void Customer::setData(int, string, string) {}
// returns customer ID
int Customer::getCustomerID() {}
// returns customer firstName
string Customer::getFirstName() {}
// returns customer lastName
string Customer::getLastName() {}
//sets customerID, firstName, lastName
bool Customer::setCustomerID(int) {}
bool Customer::setFirstName(string) {}
bool Customer::setLastName(string) {}

//ostream operator<<
ostream& operator<<(ostream&, const BSTree&)
{}