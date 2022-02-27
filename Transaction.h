
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "hashmap.h"
#include "customer.h"
#include "storage.h"
#include <fstream>
#include <string>
using namespace std;

class Transaction {

  public:
    Transaction();                           // default constructor
    virtual ~Transaction();                  // virtual destructor
    virtual Transaction *create() const = 0; // virtual create method
    virtual bool setData(istream &) = 0;     // virtual set data method
    // virtual doTransaction method, defined in derived classes
    virtual void doTransaction(Storage &, HashMap &) = 0;
};

#endif
