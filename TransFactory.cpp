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
      transFac_.push_back(new DisplayInventory);
      transFac_.push_back(new Borrow);
      transFac_.push_back(new Return);
      transFac_.push_back(new History);
      //insert into transMap
      transMap_.insert(make_pair('I', 0));
      transMap_.insert(make_pair('B', 1));
      transMap_.insert(make_pair('R', 2));
      transMap_.insert(make_pair('H', 3));
  }
  // virtual destrcutor
  TransFactory::~TransFactory()
  {
      for (int i = 0; i < transFac_.size(); i++)
      {
          delete transFac_[i];
          transFac_[i] = nullptr;
      }
  }
  // create Treansaction method
  Transaction* TransFactory::createTransaction(char transType) const
  {
      if (transMap_.find(transType) == transMap_.end())
      {
          return nullptr;
      }
      else
      {
          int subscript = transMap_.at(transType);
          return transFac_[subscript]->create();
      }
  }