/**
 * @file Comedy.cpp
 * @author Le, Tammy
 * @brief Comedy class - sorting by Title of movie, then yearReleased
 * Notes:
 * Comedy = "F" for funny
 * Output format: F, stock, director, title, yearReleased (same format as Drama)
 * @date 2022-02-26
 **/
#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

class Comedy : public Movie {
  //ostream operator<<
  friend ostream &operator<<(ostream &output, const Comedy &comedy);

public:
  // constructor
  Comedy();
  // destructor
  ~Comedy();

  char getItemType() const override;
  char getGenre() const override;
  // create() function can be used after the types of Movie
  Item *create() const override;
  // setting item
  void setItem(istream &data) override;
  void setPartialItem(istream &inFile, char itemType, char genre) override; //oop, setting partial

  // assignment operator
  Item &operator=(Item &item);
  // comparison operators
 // virtual comparison operator== COMEDY
  // bool operator==(Item &item) override
  // {
  //   Comedy &ptr = static_cast<Comedy &>(item);
  //   cerr << "Start: Comedy check log for title/ director EQUALS == operator " << endl;
  //   return (title_ == ptr.title_ && yearReleased_ == ptr.yearReleased_);
  // }
  // bool operator!=(Item &item) override;
  // bool operator<(Item &item) override;
  // bool operator>(Item &item) override;

  // compare operators to sort items in BSTree
  bool operator==(Item &) const;
  bool operator!=(Item &) const;
  bool operator<(Item &) const;
  bool operator>(Item &) const;

  // print
  void print(ostream &output) const override;

private:
  string director_;
};

#endif // COMEDY_H