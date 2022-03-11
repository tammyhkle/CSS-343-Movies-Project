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
  bool operator==(Item &item) const override;
  bool operator!=(Item &item) const override;
  bool operator<(Item &item) const override;
  bool operator>(Item &item) const override;

  // setting item
  void setItem(istream &data) override;
  void setPartialItem(istream &inFile, char itemType, char genre)
      override; //// oop, setting partial (unique to only classics)

  // print
  void print(ostream &output) const override;

private:
  string director;
  string majorActor;
  string firstName;
  string lastName;
  int yearReleased;
  int monthReleased;
};

#endif // CLASSICS_H