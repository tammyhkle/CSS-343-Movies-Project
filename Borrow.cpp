/**
 * @file Borrow.cpp
 * @author Le, Tammy
 * @brief Borrow class
 * @date 2022-02-26
 **/
#include "Borrow.h"
// default constructor,
Borrow::Borrow() {}
// destructor
Borrow::~Borrow() {}

/*overridden from Transaction
performs Borrow on movie and
adds Borrow details to
customer's vector of transactions
*/
void Borrow::doTransaction(Storage &, HashMap &) {}
