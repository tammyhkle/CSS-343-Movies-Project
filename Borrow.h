/**
 * @file Borrow.h
 * @author Le, Tammy
 * @brief Borrow class
 * @date 2022-02-26
 **/
#ifndef BORROW_H
#define BORROW_H

#include "Customer.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include <string>
using namespace std;

class Borrow : public Transaction {

public:
  // default constructor,
  Borrow();
  // destructor
  virtual ~Borrow();
  // sets data for item and patron involved in the Borrow transaction
  virtual bool setData(istream &);

  // creates and return new Borrow object
  virtual Transaction *create() const;
  /*overridden from Transaction
  performs Borrow on movie and
  adds Borrow details to
  customer's vector of transactions
  */
  virtual void doTransaction(Storage &, HashMap &);

private:
  // the movie that is being returned
  Item *theItem;
  // the Customer that returns the movie
  int custID;
  // factory to create Item objects
  MovieFactory movieFactory;
};

#endif // BORROW_H
