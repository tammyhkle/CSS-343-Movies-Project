/**
 * @file DisplayInventory.h
 * @author Le, Tammy
 * @brief Transaction class
 * @date 2022-02-26
 **/
#ifndef DISPLAYINVENTORY_H
#define DISPLAYINVENTORY_H

#include "Transaction.h"
#include <string>
using namespace std;

class DisplayInventory : public Transaction {

public:
  // default constructor
  DisplayInventory();
  // destructor
  virtual ~DisplayInventory();

  // virtual create method
  virtual Transaction *create() const;
  // virtual set data method
  virtual bool setData(istream &);
  // displays the catalogue
  virtual void doTransaction(Storage &, HashMap &);
};

#endif // DISPLAYINVENTORY_H
