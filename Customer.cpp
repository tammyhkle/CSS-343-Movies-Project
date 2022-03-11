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

using namespace std;

// default constructor
Customer::Customer() {}
// destructor
Customer::~Customer() {}

// add to history
void Customer::addHistory(Transaction *transaction) {
  history_.push_back(transaction);
}

// returns customer ID
int Customer::getCustomerID() { return customerID_; }
// returns customer firstName
string Customer::getFirstName() { return firstName_; }
// returns customer lastName
string Customer::getLastName() { return lastName_; }
// method to set all fields for the customer's account
bool Customer::setData(int customerID, istream &infile) {
  customerID_ = customerID;
  if (customerID_ >= 0) {
    infile >> lastName_;
    infile >> firstName_;
    infile.get();

    // cerr << "Done setting customer's account " << endl;
    // cerr << "customerID: " << customerID_ << endl;
    // cerr << "firstName: " << firstName_ << endl;
    // cerr << "lastName: " << lastName_ << endl;

    return true;
  } else {
    cerr << "ERROR: " << customerID_ << " is not a valid customer ID." << endl;
    return false; // customer not valid
  }
}

// ostream operator<<
// ostream& operator<<(ostream &output, const BSTree& bst) {}