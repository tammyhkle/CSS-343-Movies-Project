/**
 * @file Drama.h
 * @author Le, Tammy
 * @brief Drama class - sorting by Director, then Title of movie
 * Notes:
 * Drama = "D"
 * Output format: D, stock, director, title, yearReleased (same format as
 *Comedy)
 * @date 2022-02-26
 **/
#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

class Drama : public Movie {

public:
  // default constructor
  Drama();
  // destructor
  ~Drama();

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
      override; //// oop, setting partial (unique to only drama)

  // print
  void print(ostream &output) const override;

private:
  string director;
};

#endif // DRAMA_H