#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include "HashMap.h"
#include "Item.h"
#include "Storage.h"
#include "TransFactory.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class RentalManager {
  friend Transaction;
  friend ostream &operator<<(ostream &, const BSTree &);

public:
  // constructor default
  RentalManager();
  // destructor
  ~RentalManager();
  // preconditions: variable of type ifstream& contains correctly formatted .txt
  // file must be passed in
  void readMovies(istream &);
  void readInventory(istream &);
  void readCustomer(istream &);
  void readCommands(istream &);

private:
  MovieFactory movieFac;
  TransFactory transFac;
  // hashmap of customer's account - call object method that process customer data
  HashMap customer;
  // this contains map of BSTree objects that each contain Items of specific type
  Storage catalouge;
};

#endif // RENTALMANAGER_H