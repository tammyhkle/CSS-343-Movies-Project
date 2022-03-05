#ifndef RETURN_H
#define RETURN_H
#include "Customer.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Transaction.h"
#include <string>
using namespace std;

class Return : public Transaction {

public:
  // default constructor
  Return();
  // destructor
  virtual ~Return();
  // sets data for item and customer involved in the return transaction
  virtual bool setData(istream &);
  // creates and returns new Return object
  virtual Transaction *create() const;
  // overridden from Transaction; performs return on movie and; adds return
  // details to; customers's vector of transactions
  virtual void doTransaction(Storage &, HashMap &);

private:
  // the movie that is being returned
  Item *theItem;
  // the customer that returns the movie
  int custID;
  // factory to create Item objects
  MovieFactory MovieFactory;
};
#endif // RETURN_H
