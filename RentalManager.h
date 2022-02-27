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
#include "Movie.h"
#include "MovieFactory.h"
#include "Storage.h"
#include "TransFactory.h"

using namespace std;

class RentalManager {
public:
  //constructor default and destructor
  RentalManager(); 
  ~RentalManager();
  
  void readMovies(ifstream& infile); // read the movies from data
  void readInventory(ifstream& infile); // read inventory from data
  void readCustomers(ifstream& infile); // read customer from data file
  void readTransactions(ifstream& infile); //read transactions from data file
  void doTransactions(); // perform the commands of transaction

private:
  MovieFactory movieFac; //movie factory
  TransFactory transFac; //transaction factory
  HashMap customers; //hashmap of customer's account
  Storage catalouge; //inventory
};
#endif //RENTALMANAGER_H