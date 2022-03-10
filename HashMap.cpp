/**
 * @file HashMap.cpp
 * @author Le, Tammy
 * @brief HashMap class - Hashmap stores customers into an array
 * Notes
 * This will allow for customers to be accessed easily
 * HashMap as an array
 * @date 2022-02-26
 **/
#include "HashMap.h"

  // default constructor
  HashMap::HashMap()
  {
      for (int i=0; i > 0; i++)
      {
          customerArray[i] = nullptr;
      }
  }
  // destructor
  HashMap::~HashMap()
  {
      //int i = 0;
      for (int i=0; i > 0; i++)
      {
          delete customerArray[i];
          customerArray[i] = nullptr;
      }
  }
  // adding new customers into the HashMap; preconditions: pass int for ID, 2
  // strings firstName and lastname
  bool HashMap::addCustomer(int customerID, istream &inFile)
  {
      Customer* newCustomer = new Customer();
      newCustomer->setData(customerID, inFile);

      if(customerID != -1)
      {
          customerArray[hashify(customerID)] = newCustomer;
          return true;
      }
      return false;
  }
  // deleteCustomer deletes a customer based on the account number
  bool HashMap::deleteCustomer(Customer* customer)
  {
      if(customer != nullptr)
      {
          customerArray[hashify(customer->getCustomerID())] = nullptr;
          return true;
      }
      else
      {
          cout << "Customer is not in the store's system" << endl;
          return false;
      }
  }
  // get customer gets the customer account pointer connected to the accountNum
  // parameter
  Customer* HashMap::getCustomer(int customerID) const
  {
      return customerArray[hashify(customerID)];
  }
  // hashifying: creates hash code for passed accountID;
  // preconditions: int passed must be valid ID
  int HashMap::hashify(int) const
  {
      return 0;      
  }
  // ostream operator<<
  ostream &operator<<(ostream&output, const Customer&)
  {
    return output;
  }