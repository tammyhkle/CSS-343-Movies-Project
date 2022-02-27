#ifndef HASHMAP_H
#def HASHMAP_H

#include "Customer.h"

/*
  Hashmap stores customers into an array, that way
  customers can be accessed easily. We are implementing the hash table as an array.
*/
class HashMap {
public:

  // constructor
  HashMap();

  // destructor
  virtual ~HashMap();

  // adding customers into the Hash table
  bool addCustomers(int spot, ifstream& line);

  // deleteCustomer deletes a customer based on the account number
  bool deleteCustomers(const int accountNum);

  // get customer gets the customer account pointer connected to the accountNum parameter
  Customer* getCustomer(const int accountNum*);

  // hashifying
  int hashify(int spot);

private:
  // array which stores customers
  Customer* customerArray[];
};

#endif // HASHMAP_H