#ifndef DISPLAYINVENTORY_H
#define DISPLAYINVENTORY_H
#include "item.h"
#include "transaction.h"
#include <string>
using namespace std;

class DisplayInventory : public Transaction {

  public:
    DisplayInventory();                               // default constructor
    virtual ~DisplayInventory();                      // destructor
    virtual Transaction *create() const;              // virtual create method
    virtual bool setData(istream &);                  // virtual set data method
    virtual void doTransaction(Storage &, HashMap &); // displays the catalogue
};
#endif
