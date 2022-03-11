/**
 * @file History.h
 * @author Le, Tammy
 * @brief History class
 * @date 2022-02-26
 **/
#ifndef HISTORY_H
#define HISTORY_H

#include "Transaction.h"
using namespace std;

class Transaction;
class History : public Transaction {
public:
  History();                     // constructor for class History
  virtual ~History();            // destrcutor for History
  bool setData(istream &inFile); // setData() method
  // get customer ID
  virtual int getCustomerID();

  virtual Transaction *create() const; // create method to create and
                                       // return a new History object pointer
  virtual void doTransaction(Storage &storage,
                             HashMap &customersMap); // displays transaction
                                                     // history of customer with
                                                     // ID equal to value of
                                                     // data member custID
private:
  int customerID_; // the Customer whose history will be displayed
};

#endif // HISTORY_H
