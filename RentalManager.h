#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

#include "BSTree.h"
#include "Classic.h"
#include "Comedy.h"
#include "Customer.h"
#include "Drama.h"
#include "HashMap.h"
#include "Item.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "Storage.h"
#include "Transaction.h"
#include "TransFactory.h"

using namespace std;

class RentalManager {
  friend Transaction;
  friend ostream& operator<<(ostream&, const BSTree&);

public:
  //constructor default and destructor
  RentalManager(); 
  ~RentalManager();
  
  void readMovies(istream&); // read the movies from data
  void readInventory(istream&); // read in Item and build inventory; preconditions: variable of type ifstream& contains correctly formatted .txt file must be passed in
  void readCustomers(istream&); // read customer from data file
  void readCommands(istream&, Storage&, HashMap&); //read transactions from data file

private:
  MovieFactory movieFac; //movie factory
  TransFactory transFac; //transaction factory
  HashMap customers; //hashmap of customer's account - call object method that process customer data
  Storage catalouge; //this contains map of BSTree objects that each contain Items of specific type
};
#endif //RENTALMANAGER_H