/*
  Hashmap stores customers into an array, that way
  customers can be accessed easily. We are implementing the hash table as an array.
*/

#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <fstream>

#include "Customer.h"
#include "RentalManager.h"

using namespace std;

class HashMap {
public:
  friend ostream& operator<<(ostream&, const Customer&);

  HashMap(); // default constructor
  virtual ~HashMap(); // destructor

  bool addCustomer(int spot, ifstream& line); // adding new customers into the HashMap; preconditions: pass int for ID, 2 strings firstName and lastname
  bool deleteCustomer(const int accountID); // deleteCustomer deletes a customer based on the account number
  Customer* getCustomer(int accountID) const; // get customer gets the customer account pointer connected to the accountNum parameter

  int hashify(int) const; // hashifying: creates hash code for passed accountID; preconditions: int passed must be valid ID

private:
  Customer* customerArray[]; // array which stores customers

};

#endif // HASHMAP_H