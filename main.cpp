/**
 * Driver for starting movie store tests. 
 * This driver opens the text files data4movies, data4customers, data4
 */

#include <iostream>
#include "RentalManager.h"

using namespace std;

// forward declaration, implementation in store_test.cpp
void testAll();

int main() {

  RentalManager myManager;

  ifstream inFile1("data4movies.txt");
  if (!inFile1) {
    cout << "File could not be opened." << endl;
    return 1;
  }
  ifstream inFile2("data4customers.txt");
  if (!inFile2) {
    cout << "File could not be opened." << endl;
    return 1;
  }
  ifstream inFile3("data4commands.txt");
  if (!inFile3) {
    cout << "File could not be opened." << endl;
    return 1;
  }

  myManager.readInventory(inFile1);
  myManager.readCustomers(inFile2);
  myManager.readTransactions(inFile3);
  
  inFile1.close();
  inFile2.close();
  inFile3.close();

  testAll();

  cout << "Done." << endl; //End of main 
};
