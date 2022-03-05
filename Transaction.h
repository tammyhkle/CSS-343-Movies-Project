/**
 * @file Transaction.h
 * @author Le, Tammy
 * @brief Transaction class
 * @date 2022-02-26
 **/
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Customer.h"
#include "Movie.h"
#include "RentalManager.h"
#include <fstream>
#include <string>
using namespace std;

class Transaction {

public:
  // default constructor
  Transaction();
  // virtual destructor
  virtual ~Transaction();
  // virtual create method
  virtual Transaction *create() const = 0;
  // virtual set data method
  virtual bool setData(istream &) = 0;
  // virtual doTransaction method, defined in derived classes
  virtual void doTransaction(Storage &, HashMap &) = 0;
};

#endif // TRANSACTION_H
