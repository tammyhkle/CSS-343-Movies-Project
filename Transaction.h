/**
 * @file Transaction.h
 * @author Le, Tammy
 * @brief Transaction class
 * @date 2022-02-26
 **/
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "MovieFactory.h"
#include "Customer.h"
#include "Movie.h"
#include "Storage.h"
#include "HashMap.h"

#include <fstream>
#include <string>
using namespace std;

class HashMap;
class TransFactory;
class Transaction {
public:
  // default constructor
  Transaction();
  // virtual destructor
  virtual ~Transaction();
  // virtual create method
  virtual Transaction* create() const = 0;
  // get customer ID
  virtual int getCustomerID() = 0;
  // virtual set data method
  virtual bool setData(istream&) = 0;
  // virtual doTransaction method, defined in derived classes
  virtual void doTransaction(Storage&, HashMap&) = 0;
};

#endif // TRANSACTION_H