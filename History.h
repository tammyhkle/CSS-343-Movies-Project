#ifndef HISTORY_H
#define HISTORY_H
#include "Customer.h"
#include "Transaction.h"
using namespace std;

class History : public Transaction {
  public:
    History();          // constructor for class History
    virtual ~History(); // destrcutor for History
    bool setData(istream &);  // setData() method 
    virtual Transaction* create() const; // create method to create and 
                                        //return a new History object pointer
    virtual void doTransaction(Storage&, HashMap&); // displays transaction
                                                      // history of customer with
                                                      // ID equal to value of
                                                      // data member custID
private:
    int customerID; // the Customer whose history will be displayed
};

#endif //HISTORY_H
