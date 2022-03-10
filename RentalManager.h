/**
 * @file RentalManager.h
 * @author Le, Tammy
 * @brief RentalManager class - Processes data from the Store's Inventory, Customers, and Transactions/ Commands
 * Notes:
 * Files are read in from main 
 * readMovies, readInventory, readCustomers, readCommands
 * @date 2022-02-26
 **/
#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include "HashMap.h"
#include "MovieFactory.h"
#include "Storage.h"
#include "TransFactory.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class TransFactory;
class HashMap;
class Storage;
class RentalManager {
//friend ostream &operator<<(ostream &out, const BSTree &bst);

public:
  // constructor default
  RentalManager();
  // destructor
  ~RentalManager();
  // preconditions: variable of type ifstream& contains correctly formatted .txt
  // file must be passed in
  void readInventory(istream & inFile);
  void readCustomer(istream & inFile);
  void readCommands(istream& inFile);

private:

  MovieFactory movieFac_;
  TransFactory transFac_;
  // hashmap of customer's account - call object method that process customer data
  HashMap customersMap_;
  // this contains map of BSTree objects that each contain Items of specific type
  Storage catalogueMap_;
};

#endif // RENTALMANAGER_H