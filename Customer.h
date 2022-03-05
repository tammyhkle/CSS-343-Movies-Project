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
  void setData(int, string, string);
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

  bool setCustomerID(int);
  bool setFirstName(string);
  bool setLastName(string);
};

#endif // CUSTOMER_H