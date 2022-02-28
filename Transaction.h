
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <fstream>
#include <string>

#include "Hashmap.h"
#include "Customer.h"
#include "Storage.h"
#include "RentalManager.h"

using namespace std;

class Transaction {

  public:
    Transaction();                           // default constructor
    virtual ~Transaction();                  // virtual destructor
    virtual Transaction *create() const = 0; // virtual create method
    virtual bool setData(istream&) = 0;     // virtual set data method
    // virtual doTransaction method, defined in derived classes
    virtual void doTransaction(Storage&, HashMap&) = 0;
};

#endif //TRANSACTION_H
