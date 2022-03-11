/**
 * @file Borrow.h
 * @author Le, Tammy
 * @brief Borrow class
 * @date 2022-02-26
 **/
#ifndef BORROW_H
#define BORROW_H

#include "Transaction.h"
#include "Item.h"
#include <string>
using namespace std;

class Transaction;
class Borrow : public Transaction {

public:
  // default constructor,
  Borrow();
  //constructor,
  Borrow(Item*, Customer*);
  // destructor
  virtual ~Borrow();
  // sets data for item and patron involved in the Borrow transaction
  virtual bool setData(istream& inFile);
  //get customer ID
  virtual int getCustomerID();
  // creates and return new Borrow object
  virtual Transaction *create() const;
  /*overridden from Transaction
  performs Borrow on movie and
  adds Borrow details to
  customer's vector of transactions
  */
  virtual void doTransaction(Storage& storage, HashMap& customersMap);

private:
  // the movie that is being returned
  Item *theItem;
  // the Customer that returns the movie
  int customerID;
  // factory to create Item objects
  MovieFactory movieFac;
};

#endif // BORROW_H