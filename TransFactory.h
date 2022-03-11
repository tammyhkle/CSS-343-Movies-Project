/**
 * @file TransFactory.h
 * @author Le, Tammy
 * @brief TransFactory class - creates and returns a new transaction object
 * @date 2022-02-26
 **/
#ifndef TRANSFACTORY_H
#define TRANSFACTORY_H

#include "Borrow.h"
#include "DisplayInventory.h"
#include "History.h"
#include "Item.h"
#include "ItemFactory.h"
#include "Return.h"
#include "Transaction.h"

#include <unordered_map>
#include <vector>
using namespace std;

// forward declaration
class TransFactory {
public:
  // default constructor
  TransFactory();
  // virtual destrcutor
  virtual ~TransFactory();
  // create Treansaction method
  Transaction *createTransaction(char transType) const;

private:
  /* HashMap with keys equal to char variables of every possible movie type
   * and values equal to integers ranging
   * from 0 to the number of transaction types - 1.
   */
  unordered_map<char, int> transMap;
  // Vector with elements that are initialized as new Transaction objects of
  // every possible transaction type
  vector<Transaction *> transFac;
};

#endif // TRANSFACTORY_H
