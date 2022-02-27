#ifndef TRANSFACTORY_H
#define TRANSFACTORY_H
#include "borrow.h"
#include "displayinventory.h"
#include "history.h"
#include "return.h"
#include "transaction.h"
#include <unordered_map>
#include <vector>
using namespace std;

class TransFactory {

  public:
    TransFactory();                             // default constructor
    virtual ~TransFactory();                    // virtual destrcutor
    Transaction *createTransaction(char) const; // create Treansaction method

  private:
    // HashMap with keys equal to char variables of every possible movie type
    // and values equal to integers ranging from 0  to the number of
    // transaction types - 1.
    unordered_map<char, int> transMap;

    // Vector with elements that are initialized as new
    // Transaction objects of every possible transaction type
    vector<Transaction *> transFac;
};

#endif
