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
// This header file summarizes the functions and variables in the Movie class 
// ------------------------------------------------------------------------------------------------
// Assumptions:
// Movie values are valid inputs in regards to type. You can however send in X or Y instead of C
// ------------------------------ Movie.h ---------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

using namespace std;

class Movie
{
  // output operator
  friend ostream & operator<<(ostream &, const Movie &);

public:
  // default blank constructor for movie class. Initializes everything to be empty
  Movie();                                                                            
  // constructor for movie class. Initializes everything to defaults
  Movie(string inGenre, string inDirector, string inTitle, int inStock, int inYear);  
  // default destructor for movie class.
  virtual ~Movie();                                                                   
  // returns the genre of the movie object as a string        
  string getGenre();                                                                  
  // returns the director of the movie object as a string
  string getDirector();                                                               
  // returns the title of the movie object as a string
  string getTitle();                                                                  
  // returns the stock of the movie object as an int
  int getStock();                                                                     
  // increments the stock of a movie object
  void addStock();                                                                    
  // decrements the stock of a movie object
  void removeStock();                                                                 
  // returns the year of the movie object as an int
  int getYear();                      
  // less than comparator function. compares by title and then year for comedy 
  // and director then title for drama 
  bool operator<(const Movie& rhs) const;  
  // equivalency comparator function. Compares one Movie object to another
  bool operator==(const Movie& rhs) const;

private:
  // intentionally left blank

protected:
  // genre of the movie
  string genre;    
  // person who directed the movie 
  string director;  
  // name of the movie
  string title;   
  // number of movies still in stock 
  int stock;    
  // year the movie was released    
  int year;         
};
#endif // ifndef MOVIE_H