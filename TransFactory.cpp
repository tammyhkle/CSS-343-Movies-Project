/**
 * @file TransFactory.h
 * @author Le, Tammy
 * @brief TransFactory class - creates and returns a new transaction object
 * @date 2022-02-26
 **/
#include "TransFactory.h"
 // default constructor
  TransFactory::TransFactory()
  {
      transFac.push_back(new DisplayInventory);
      transFac.push_back(new Borrow);
      transFac.push_back(new Return);
      transFac.push_back(new History);
      //insert into transMap
      transMap.insert(make_pair('I', 0));
      transMap.insert(make_pair('B', 1));
      transMap.insert(make_pair('R', 2));
      transMap.insert(make_pair('H', 4));
  }
  // virtual destrcutor
  TransFactory::~TransFactory()
  {
      for (int i = 0; i < transFac.size(); i++)
      {
          delete transFac[i];
          transFac[i] = nullptr;
      }
  }
  // create Treansaction method
  Transaction* TransFactory::createTransaction(char transType, char genre) const
  {
      if (transMap.find(transType) == transMap.end())
      {
          return nullptr;
      }
      else
      {
          int subscript = transMap.at(transType);
          return transFac[subscript]->create();
      }
  }