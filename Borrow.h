#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"
#include <string>
using namespace std;

class Borrow : public Transaction {

  public:
    Borrow();                      // default constructor,
    virtual ~Borrow();             // destructor
    virtual bool setData(istream &); // sets data for item and patron involved
                                     // in the Borrow transaction

    virtual Transaction*
    create() const; // creates and return new Borrow object
    virtual void doTransaction(Storage &, HashMap &); // overridden from Transaction
                                           // performs Borrow on movie and
                                           // adds Borrow details to
                                           // customer's vector of transactions

private:
    Item *theItem;           // the movie that is being returned
    int custID;            // the Customer that returns the movie
    MovieFactory movieFactory;     // factory to create Item objects
};

#endif
