/*
Customer object stores the customer info that's been read from the file. This
includes a unique four-digit ID, their first and last name, and also a history
vector where we store the transactions of the customer.
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "BSTree.h"
#include "HashMap.h"
#include "Transaction.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
  // friend class Hashmap;
  friend ostream &operator<<(ostream &, const BSTree &);

public:
  // default constructor
  Customer();
  // destructor
  virtual ~Customer();

  // adding the transaction to customer's history
  void addToHistory(Transaction *&);
  // printing out customer's history
  void printHistory const();
  // returns customer ID
  int getCustomerID();
  // returns customer firstName
  string getFirstName();
  // returns customer lastName
  string getLastName();

private:
  int customerID;
  string firstName;
  string lastName;
  // vector where we store the transactions objects
  vector<Transaction *> history;
};

#endif // CUSTOMER_H