/**
 * @file Classics.h
 * @author Le, Tammy
 * @brief Classics class - sorting by Release Date, then by Major Actor
 * Notes:
 * Classics = "C"
 * Output format: C, stock, director, title, majorActor, releaseDate
 * @date 2022-02-26
 **/
#ifndef CLASSICS_H
#define CLASSICS_H

#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

class Classics : public Movie {

public:
  // default constructor
  Classics();
  // destructor
  ~Classics();

  // create() function can be used after the types of Movie
  Item *create() const override;
  char getItemType() const override;
  char getGenre() const override;

  // assignment operator
  Item &operator=(Item &item) override;
  // comparison operators
  bool operator==(Item &item) override;
  bool operator!=(Item &item) override;
  bool operator<(Item &item) override;
  bool operator>(Item &item) override;
  
  // setting item
  void setItem(istream &data) override;
  void setPartialItem(istream &inFile, char itemType, char genre) override; //// oop, setting partial (unique to only classics)

  // print
  void print(ostream &output) const override;

private:
  string director_;
  string majorActor_;
  int yearReleased_;
  int monthReleased_;
};

#endif // CLASSICS_H