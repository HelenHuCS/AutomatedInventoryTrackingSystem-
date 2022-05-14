// ------------------------------ Assignment 4 ----------------------------------------------------
// Tyson Heo
// Helen Hu
// Kevin Huang
// CSS 502A
// Assignment 4: Implementation
// Creation Date: 3/01/2021
// Date of Last Modification: 3/17/2021
//
// Purpose:
// This header file summarizes the functions and variables in the Movieclassics class 
// ------------------------------------------------------------------------------------------------
// Assumptions:
// MovieClassics values are valid inputs in regards to type. You can however send in X or Y 
// instead of C
// ------------------------------ MovieClassics.h -------------------------------------------------

#ifndef MOVIECLASSICS_H
#define MOVIECLASSICS_H
#include <iostream>
#include <string>
#include "Movie.h"

using namespace std;

// Inherits from Movie class
class MovieClassics : public Movie
{
  // Output operator
  friend ostream & operator<<(ostream &, const MovieClassics & inMovie);

public:
  // Default blank constructor for classics movie class.
  MovieClassics();    
  // Constructor for classic movie class from given inputs                     
  MovieClassics(string inGenre, string inDirector, string inTitle, string inMajorActor,
      int inStock, int inYear, int inMonth);      
  // Default destructor for classic movie class
  ~MovieClassics();         
  // Returns the major actor of a movie object as a string                          
  string getMajorActor();                             
  // Returns the month of a movie object as an int
  int getMonth();       
  // Less than comparator function. compares by release date then major actor
  bool operator<(const MovieClassics& rhs) const;
  // equivalency comparator function. Compares one Movie object to another
  bool operator==(const MovieClassics &rhs) const;

private:
  // Major actor that was in the movie
  string majorActor;  
  // Along with the year, month is also included for classical movies
  int month;          
};
#endif // ifndef MOVIECLASSICS_H