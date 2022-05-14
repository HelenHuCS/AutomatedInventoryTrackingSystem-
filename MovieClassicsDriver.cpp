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
// This driver file tests the MovieClassics class' functions and its functionality. 
// ------------------------------------------------------------------------------------------------
// Assumptions:
// Movie values are valid inputs in regards to type. You can however send in X or Y instead of C
// ------------------------------ MovieclassicsDriver.cpp -----------------------------------------

#include "MovieClassics.h"

using namespace std;

// g++ Movie.cpp MovieClassics.cpp MovieClassicsDriver.cpp
int main()
{
  // input movies
  // C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
  // C, 10, George Cukor, Holiday, Cary Grant 9 1938
  // C, 10, Michael Curtiz, Casablanca, Humphrey Bogart 8 1942
  // C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939

  // Test constructor
  // MovieClassics(string inGenre, string inDirector, string inTitle, string inMajorActor, int inStock, int inYear, int inMonth); 
  MovieClassics movie1("C", "George Cukor",   "Holiday",          "Katherine Hepburn", 10, 1938, 9);
  MovieClassics movie2("C", "George Cukor",   "Holiday",          "Carly Grant",       10, 1938, 9);
  MovieClassics movie3("C", "Michael Curtiz", "Casablanca",       "Humphrey Bogart",   10, 1942, 8);
  MovieClassics movie4("C", "Victor Fleming", "The Wizard of Oz", "Judy Garland",      10, 1939, 7);

  // Test getTitle
  cout << "title (expected: Holiday): "          << movie1.getTitle() << endl;
  cout << "title (expected: Holiday): "          << movie2.getTitle() << endl;
  cout << "title (expected: Casablanca): "       << movie3.getTitle() << endl;
  cout << "title (expected: The Wizard of Oz): " << movie4.getTitle() << endl;
  cout << endl;

  // Test getStock
  // Test addStock
  // Test removeStock
  cout << "stock(expect 10): " << movie1.getStock() << endl;
  movie1.addStock();
  cout << "stock(expect 11): " << movie1.getStock() << endl;
  movie1.removeStock();
  cout << "stock(expect 10): " << movie1.getStock() << endl;
  
  cout << "stock(expect 10): " << movie2.getStock() << endl;
  movie2.addStock();
  cout << "stock(expect 11): " << movie2.getStock() << endl;
  movie2.removeStock();
  cout << "stock(expect 10): " << movie2.getStock() << endl;
  
  cout << "stock(expect 10): " << movie3.getStock() << endl;
  movie3.addStock();
  cout << "stock(expect 11): " << movie3.getStock() << endl;
  movie3.removeStock();
  cout << "stock(expect 10): " << movie3.getStock() << endl;
  
  cout << "stock(expect 10): " << movie4.getStock() << endl;
  movie4.addStock();
  cout << "stock(expect 11): " << movie4.getStock() << endl;
  movie4.removeStock();
  cout << "stock(expect 10): " << movie4.getStock() << endl;
  cout << endl;

  // Test getYear
  cout << "year(expected: 1938): " << movie1.getYear() << endl;
  cout << "year(expected: 1938): " << movie2.getYear() << endl;
  cout << "year(expected: 1942): " << movie3.getYear() << endl;
  cout << "year(expected: 1939): " << movie4.getYear() << endl;
  cout << endl;

  // Test getMajorActor function
  // string getMajorActor();  // returns the major actor of a movie object as a string
  cout << "movie1 major actor (expect: Katherine Hepburn): " << movie1.getMajorActor() << endl;
  cout << "movie2 major actor (expect: Cary Grant): "        << movie2.getMajorActor() << endl;
  cout << "movie3 major actor (expect: Humphrey Bogart): "   << movie3.getMajorActor() << endl;
  cout << "movie4 major actor (expect: Judy Garland): "      << movie4.getMajorActor() << endl;
  cout << endl;

  // Test getMonth function
  // int getMonth();  // returns the month of a movie object as an int
  cout << "movie1 month (expect: 9): " << movie1.getMonth() << endl;
  cout << "movie2 month (expect: 9): " << movie2.getMonth() << endl;
  cout << "movie3 month (expect: 8): " << movie3.getMonth() << endl;
  cout << "movie4 month (expect: 7): " << movie4.getMonth() << endl;
  cout << endl;
  
  // Test < operator
  // classics: release date, then major actor
  // movie1 = 9 1938 Katherine Hepburn 
  // movie2 = 9 1938 Cary Grant 
  // movie3 = 8 1942 Humphrey Bogart 
  // movie4 = 7 1939 Judy Garland 
  cout << "movie1 < movie2? (expect false): " << (movie1 < movie2) << endl;
  cout << "movie1 < movie3? (expect true): "  << (movie1 < movie3) << endl;
  cout << "movie1 < movie4? (expect true): "  << (movie1 < movie4) << endl;

  // Test << operator
  cout << "movie1: " << movie1 << endl;
  cout << "movie2: " << movie2 << endl;
  cout << "movie3: " << movie3 << endl;
  cout << "movie4: " << movie4 << endl;

  return 0;
}