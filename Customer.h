#ifndef CUSTOMER_H
#def CUSTOMER_H

#include "Transaction.h"
#include <string>
#include <vector>

/*
Customer object stores the customer info that's been read from the file. This includes a unique four-digit ID, their first and last name, and also a history vector where we store the transactions of the customer. 
*/
class Customer {

friend class Hashmap;

public:
  // constructor
  customer();

  // destructor
  virtual ~customer();

  // adding the transaction to customer's history
  void addToHistory(Transaction*& );

  // printing out customer's history
  void printHistory const();

  // returning customeri information
  int getCustomerID();

private:
  // unique ID for customer
  int customerID;

  // customer firstname
  string firstName;

  // customer lastname
  string lastName;

  // vector where we store the transactions
  vector<Transaction*> history;
};

#endif // CUSTOMER_H