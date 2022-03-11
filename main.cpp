/**
 * Driver for starting movie store tests.
 * This driver opens the text files data4movies, data4customers, data4
 */
#include "Drama.h"
#include "RentalManager.h"
#include <fstream>
#include <iostream>
using namespace std;

// forward declaration, implementation in store_test.cpp
void testAll();

// Test for reading data4Movies
int testReadingData4Movies() {
  RentalManager myManager;

  ifstream inFile1("data4movies.txt");
  cerr << "reading data4movies" << endl;
  if (!inFile1) {
    cout << "File could not be opened." << endl;
    return 1;
    cerr << " file not open" << endl;
  }
  cerr << " Reading " << endl;
  myManager.readInventory(inFile1);
  cerr << "finish reading" << endl;

  inFile1.close();
  return 0;
}

// Test for reading data4Customers
int testReadingData4Customers() {
  RentalManager myManager;

  ifstream inFile2("data4customers.txt");
  cerr << "reading data4customers" << endl;
  if (!inFile2) {
    cout << "File could not be opened." << endl;
    return 1;
    cerr << " file not open" << endl;
  }
  cerr << " Reading " << endl;
  myManager.readCustomer(inFile2);
  cerr << "finish reading" << endl;

  inFile2.close();
  return 0;
}

// Test for reading data4Commands
int testReadingData4Commands() {
  RentalManager myManager;

  ifstream inFile3("data4commands.txt");
  cerr << "reading data4commands" << endl;
  if (!inFile3) {
    cout << "File could not be opened." << endl;
    return 1;
    cerr << " file not open" << endl;
  }
  cerr << " Reading " << endl;

  myManager.readCommands(inFile3);
  cerr << "finish reading" << endl;

  inFile3.close();
  return 0;
}

int main() {
  // testReadingData4Movies();
  // testReadingData4Customers();
  // testReadingData4Commands();

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
  myManager.readCustomer(inFile2);
  myManager.readCommands(inFile3);

  inFile1.close();
  inFile2.close();
  inFile3.close();

  testAll();

  cout << "Done." << endl;
};
// End of main
