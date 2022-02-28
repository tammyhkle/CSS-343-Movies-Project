/*
Customer object stores the customer info that's been read from the file. This includes a unique four-digit ID, their first and last name, and also a history vector where we store the transactions of the customer. 
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

#include "HashMap.h"

using namespace std;

class Customer {
  //friend class Hashmap;
  friend ostream& operator<<(ostream&, const BSTree&);

public:
  Customer(); // constructor
  virtual ~Customer(); // destructor

  void addToHistory(Transaction*& ); // adding the transaction to customer's history
  //void printHistory const(); // printing out customer's history
  int getCustomerID(); // returns customer ID
  string getFirstName(); // returns customer firstName
  string getLastName(); // returns customer lastName

private:
  int customerID; // unique ID for customer
  string firstName; // customer firstname
  string lastName; // customer lastname
  vector<Transaction*> history; // vector where we store the transactions objects
};

#endif // CUSTOMER_H