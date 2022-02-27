#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"
#include <string>
using namespace std;

class Return : public Transaction {

  private:
    Item *theItem;           // the movie that is being returned
    int custID;            // the customer that returns the movie
    MovieFactory MovieFactory; // factory to create Item objects

  public:
    Return();                        // default constructor
    virtual ~Return();               // destructor
    virtual bool setData(istream &); // sets data for item and customer involved
                                     // in the return transaction
    virtual Transaction *
    create() const; // creates and returns new Return object
    virtual void doTransaction(Storage &,
                               HashMap &); // overridden from Transaction
                                           // performs return on movie and
                                           // adds return details to
                                           // customers's vector of transactions
};

#endif
