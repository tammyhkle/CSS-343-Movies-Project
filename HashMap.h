/*
  Hashmap stores customers into an array, that way
  customers can be accessed easily. We are implementing the hash table as an
  array.
*/
#ifndef HASHMAP_H
#define HASHMAP_H

#include "Customer.h"
#include <fstream>
#include <string>
using namespace std;

class HashMap {
public:
  // ostream operator<<
  friend ostream &operator<<(ostream &, const Customer &);

  // default constructor
  HashMap();
  // destructor
  virtual ~HashMap();

  // adding new customers into the HashMap; preconditions: pass int for ID, 2
  // strings firstName and lastname
  bool addCustomer(int spot, ifstream &line);
  // deleteCustomer deletes a customer based on the account number
  bool deleteCustomer(const int accountID);
  // get customer gets the customer account pointer connected to the accountNum
  // parameter
  Customer *getCustomer(int accountID) const;
  // hashifying: creates hash code for passed accountID;
  // preconditions: int passed must be valid ID
  int hashify(int) const;

private:
  // array which stores customers
  Customer *customerArray[];
};

#endif // HASHMAP_H