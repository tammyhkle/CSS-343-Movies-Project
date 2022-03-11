/**
 * @file Return.h
 * @author Le, Tammy
 * @brief Return class
 * @date 2022-02-26
 **/
#ifndef RETURN_H
#define RETURN_H

#include "Customer.h"
#include "Movie.h"
#include "Transaction.h"

#include <string>
using namespace std;

class Transaction;
class Return : public Transaction {

public:
  // default constructor
  Return();
  // destructor
  virtual ~Return();
  // get customer ID
  virtual int getCustomerID();
  // sets data for item and customer involved in the return transaction
  virtual bool setData(istream &);
  // creates and returns new Return object
  virtual Transaction *create() const;
  // overridden from Transaction; performs return on movie and; adds return
  // details to; customers's vector of transactions
  virtual void doTransaction(Storage &, HashMap &);

private:
  // the movie that is being returned
  Item *theItem_;
  // the customer that returns the movie
  int customerID_;
  // factory to create Item objects
  MovieFactory movieFac_;
};
#endif // RETURN_H