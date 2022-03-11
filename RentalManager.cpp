/**
 * @file RentalManager.cpp
 * @author Le, Tammy
 * @brief RentalManager class - Processes data from the Store's Inventory,
 *Customers, and Transactions/ Commands Notes: Files are read in from main
 * readMovies, readInventory, readCustomers, readCommands
 * @date 2022-02-26
 **/

#include "RentalManager.h"

// constructor default
RentalManager::RentalManager() {}
// destructor
RentalManager::~RentalManager() {}

// reads in item data and builds inventory
void RentalManager::readInventory(istream &inFile) {
  int counter = 0;
  Item *item;
  char itemType;
  char genre;
  string testLine;

  // cerr << "ReadInventory begin while loop" << endl;
  while (!inFile.eof()) {
    counter++;
    // cerr << "Count of line: " << counter;

    // cerr << "Running while loop" << endl;
    // inFile >> genre;
    getline(inFile, testLine, ',');
    // cerr << "testLine[0]: " << testLine[0] << endl;
    genre = testLine[0];

    itemType = 'D'; // D for DVD

    item = this->movieFac_.create(genre);

    // cerr << "Created new movie" << endl;

    if (item == nullptr) {
      // cerr << "Item is null" << endl;
      string invalidLine = "";
      getline(inFile, invalidLine);
      continue;
    }
    inFile.get();
    item->setItem(inFile);
    // cerr << "Adding item into catalouge bst" << endl;
    catalogueMap_.insertItem(item);
    // cerr << "Finished adding item into catalouge bst" << endl;

    if (inFile.eof()) {
      break;
    }
  }
  cout << catalogueMap_ << endl;
  // cerr << catalogueMap_ << "CatalouageMap" << endl;
}
// read in cutomer and build customer profile
void RentalManager::readCustomer(istream &inFile) {
  int counter = 0;
  int customerID = 0;

  // cerr << "readCustomer begin while loop" << endl;
  while (!inFile.eof()) {
    counter++;
    // cerr << "Count of line: " << counter << endl;
    // cerr << "Running while loop " << endl;
    inFile >> customerID;
    // cerr << "rentalmanager - Customer ID: " << customerID << endl;
    inFile.get();
    customersMap_.addCustomer(customerID, inFile);
    // cerr << "Done" << endl;
    // cerr << endl;
    inFile.get();
    if (inFile.eof()) {
      break;
    }
  }
  cout << catalogueMap_ << endl;
  // cerr << "catalogueMap" << catalogueMap_ << endl;
}
// reads in commands data and performs the command
void RentalManager::readCommands(istream &inFile) {
  int counter = 0;
  char commandType;
  // int customerID = 0;

  Transaction *command;

  while (!inFile.eof()) {
    counter++;
    // cerr << "Count of line: " << counter << endl;
    // cerr << "Run while loop " << endl;

    inFile >> commandType;
    // cerr << "Command Type (I, H, B, R): " << commandType << endl;

    // transaction factory
    // cerr << "transFac create " << endl;
    command = this->transFac_.createTransaction(commandType);
    // cerr << "Finish transFac create " << endl;
    // validate command
    if (command == nullptr) {
      string invalidLine = "";
      getline(inFile, invalidLine);
      continue;
    }
    // if else statements on the commandTypes
    if (commandType == 'I') {
      command->doTransaction(catalogueMap_, customersMap_);
    } else if (commandType == 'H') {
      // cerr << "Start of setData for History " << endl;
      command->setData(inFile);
      // cerr << "setData for History " << endl;
      // cerr << "Start of doTransaction for History " << endl;
      command->doTransaction(catalogueMap_, customersMap_);
      // cerr << "Finished doTransaction for History " << endl;
    } else if (commandType == 'B' || commandType == 'R') {
      if (command->setData(inFile)) {
        // cerr << "Starting doTransaction " << endl;
        command->doTransaction(catalogueMap_, customersMap_);
        // cerr << "Finish doTransaction " << endl;
      }
    } else {
      // cerr << "Invalid command type" << endl;
    }
    inFile.get();
    // cerr << "----------" << endl << endl;
    if (inFile.eof()) {
      break;
    }
  }
}
// operator ostream<<
// ostream &operator<<(ostream &, const BSTree &){}