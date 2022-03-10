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
//friend class transaction; //forward declaration of transaction
public:
  // default constructor
  DisplayInventory();
  // destructor
  virtual ~DisplayInventory();
  //get customer ID
  virtual int getCustomerID();
  // virtual create method
  virtual Transaction *create() const;
  // virtual set data method
  virtual bool setData(istream& );
  // displays the storage(inventory)
  virtual void doTransaction(Storage& , HashMap& );
};

#endif // DISPLAYINVENTORY_H