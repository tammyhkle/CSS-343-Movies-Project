/**
 * @file History.cpp
 * @author Le, Tammy
 * @brief History class
 * @date 2022-02-26
 **/
#include "History.h"

// constructor for class History
History::History() 
{
    Customer = nullptr;
}
// destrcutor for History
History::~History() 
{
    Customer = nullptr;
}
// setData() method
bool History::setData(Customer* customer)
{
    customer = aCustomer;
    return;
}
// create method to create and return a new History object pointer
Transaction* History::create() const
{
    return new History;
}
// displays transaction history of customer with ID equal to value of data member custID
void History::doTransaction(Storage & storage, HashMap & customerMap)
{
    //look for the customer* in the customer hashmap
    Customer = customerMap.getCustomer(customer->getCustomerID());
    cout << Customer;
    return;
}