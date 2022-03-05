/**
 * @file HashMap.h
 * @author Le, Tammy
 * @brief HashMap class - Hashmap stores customers into an array
 * Notes
 * This will allow for customers to be accessed easily
 * HashMap as an array
 * @date 2022-02-26
 **/
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
  bool addCustomer(int customerID, ifstream&);
  // deleteCustomer deletes a customer based on the account number
  bool deleteCustomer(Customer* customer);
  // get customer gets the customer account pointer connected to the accountNum
  // parameter
  Customer* getCustomer(int customerID) const;
  // hashifying: creates hash code for passed accountID;
  // preconditions: int passed must be valid ID
  int hashify(int) const;

private:
  // array which stores customers
  Customer *customerArray[];
};

#endif // HASHMAP_H