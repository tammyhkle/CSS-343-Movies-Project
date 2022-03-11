/**
 * @file Customer.h
 * @author Le, Tammy
 * @brief Customer class - stores customers information, read from file
 * Notes
 * Includes unique 4 digit customerID
 * firstName, lastName
 * history vector - stores transactions of customer
 * @date 2022-02-26
 **/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "BSTree.h"
#include "Transaction.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Transaction;
class Customer {
  // friend ostream &operator<<(ostream &output, const BSTree& bst);

public:
  // default constructor
  Customer();
  // destructor
  virtual ~Customer();
  // add to history
  void addHistory(Transaction *transaction);
  // method to set all fields for the customer's account
  bool setData(int customerID, istream &infile);
  // returns customer ID - used to find a customer in the hash table
  int getCustomerID();
  // returns customer firstName
  string getFirstName();
  // returns customer lastName
  string getLastName();

private:
  int customerID = 0;
  string firstName;
  string lastName;
  // vector where we store the transactions objects
  vector<Transaction *> history;
};

#endif // CUSTOMER_H