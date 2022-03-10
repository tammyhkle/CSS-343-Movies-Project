/**
 * @file Movie.h
 * @author Le, Tammy
 * @brief Movie class - Movie are children classes of Item
 * @date 2022-02-26
 **/
#ifndef MOVIE_H
#define MOVIE_H

#include "Item.h"
#include <iostream>
#include <string>
using namespace std;

class Movie : public Item {
  // ostream operator used to print
  friend ostream &operator<<(ostream &out, const Movie &movie);

public:
  // default constructor
  Movie();
  // destructor
  virtual ~Movie();

  // return item type as char
  virtual char getItemType() const = 0;

  /* return genre of movie as char:
   * F - Comedy, D - Drama, C- Classics
   */
  virtual char getGenre() const = 0;

  /* won't be created in Item.cpp & Movie.cpp,
   *but appear in children classes
   *Item & Movie ==> abstract classes
   *create() function can be used after the types of Movie
   */
  Item *create() const = 0;

  // setting item
  void setItem(istream &data) = 0;

  // assignment operator
  //virtual Item &operator=(Item &other);
  
  // // compare operators to sort items in BSTree
   //virtual bool operator==(Item &other);
  // virtual  bool operator!=(Item &other);
  // virtual bool operator<(Item &other);
  // virtual bool operator>(Item &other);
  //print
  void print(ostream &output) const;

protected:
  string title_;
  char genre_;
  int yearReleased_;
};

#endif // MOVIE_H