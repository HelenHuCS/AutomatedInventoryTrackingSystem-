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
// This driver file tests the Movie class' functions and its functionality. 
// ------------------------------------------------------------------------------------------------
// Assumptions:
// N/A
// ------------------------------ MovieDriver.cpp -------------------------------------------------

#include "Movie.h"

using namespace std;

// g++ Movie.cpp MovieDriver.cpp
int main()
{
  // input movies
  // F, 10, Woody Allen, Annie Hall, 1977
  // F, 10, Joel Coen, Annie Hall, 1950
  // F, 10, John Landis, National Lampoon's Animal House, 1978
  // F, 10, Nora Ephron, You've Got Mail, 1998
  // D, 10, Barry Levinson, Good Morning Vietnam, 1988
  // D, 10, Barry Levinson, Good Will Hunting, 2000
  // D, 10, Clint Eastwood, Unforgiven, 1992
  // D, 10, Barry Levinson, Dogfight, 1991

  // Test constructor
  // Movie(string inGenre, string inDirector, string inTitle, int inStock, int inYear);
  // comedy: title then year
  // drama: director then title
  Movie movie1("F", "Woody Allen",    "Annie Hall",                      10, 1977);
  Movie movie2("F", "Joel Coen",      "Annie Hall",                      10, 1950);
  Movie movie3("F", "John Landis",    "National Lampoon's Animal House", 10, 1978);
  Movie movie4("F", "Nora Ephron",    "You've Got Mail",                 10, 1998);
  Movie movie5("D", "Barry Levinson", "Good Morning Vietnam",            10, 1988);
  Movie movie6("D", "Barry Levinson", "Good Will Hunting",               10, 2000);
  Movie movie7("D", "Clint Eastwood", "Unforgiven",                      10, 1992);
  Movie movie8("D", "Barry Levinson", "Dogfight",                        10, 1991);

  // Test getGenre();  
  cout << "director (expected: Woody Allen): "    << movie1.getDirector() << endl;
  cout << "director (expected: Joel Coen): "      << movie2.getDirector() << endl;
  cout << "director (expected: John Landis): "    << movie3.getDirector() << endl;
  cout << "director (expected: Nora Ephron): "    << movie4.getDirector() << endl;
  cout << "director (expected: Barry Levinson): " << movie5.getDirector() << endl;
  cout << "director (expected: Barry Levinson): " << movie6.getDirector() << endl;
  cout << "director (expected: Clint Eastwood): " << movie7.getDirector() << endl;
  cout << "director (expected: Nancy Savoca): "   << movie8.getDirector() << endl;
  cout << endl;

  // Test getTitle
  cout << "title (expected: Angie Hall): "                      << movie1.getTitle() << endl;
  cout << "title (expected: Annie Hall): "                      << movie2.getTitle() << endl;
  cout << "title (expected: National Lampoon's Animal House): " << movie3.getTitle() << endl;
  cout << "title (expected: You've Got Mail): "                 << movie4.getTitle() << endl;
  cout << "title (expected: Good Morning Vietname): "           << movie5.getTitle() << endl;
  cout << "title (expected: Good Will Hunting): "               << movie6.getTitle() << endl;
  cout << "title (expected: Unforgiven): "                      << movie7.getTitle() << endl;
  cout << "title (expected: Dogfight): "                        << movie8.getTitle() << endl;
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
  
  cout << "stock(expect 10): " << movie5.getStock() << endl;
  movie5.addStock();
  cout << "stock(expect 11): " << movie5.getStock() << endl;
  movie5.removeStock();
  cout << "stock(expect 10): " << movie5.getStock() << endl;
  
  cout << "stock(expect 10): " << movie6.getStock() << endl;
  movie6.addStock();
  cout << "stock(expect 11): " << movie6.getStock() << endl;
  movie6.removeStock();
  cout << "stock(expect 10): " << movie6.getStock() << endl;
  
  cout << "stock(expect 10): " << movie1.getStock() << endl;
  movie1.addStock();
  cout << "stock(expect 11): " << movie1.getStock() << endl;
  movie1.removeStock();
  cout << "stock(expect 10): " << movie1.getStock() << endl;
  
  cout << "stock(expect 10): " << movie8.getStock() << endl;
  movie8.addStock();
  cout << "stock(expect 11): " << movie8.getStock() << endl;
  movie8.removeStock();
  cout << "stock(expect 10): " << movie8.getStock() << endl;
  cout << endl;

  // Test getYear
  cout << "year(expected: 1977): " << movie1.getYear() << endl;
  cout << "year(expected: 1950): " << movie2.getYear() << endl;
  cout << "year(expected: 1978): " << movie3.getYear() << endl;
  cout << "year(expected: 1998): " << movie4.getYear() << endl;
  cout << "year(expected: 1988): " << movie5.getYear() << endl;
  cout << "year(expected: 2000): " << movie6.getYear() << endl;
  cout << "year(expected: 1992): " << movie7.getYear() << endl;
  cout << "year(expected: 1991): " << movie8.getYear() << endl;
  cout << endl;

  // Test < operator
  // comedy: title then year
  // drama: director then title
  cout << "movie1 < movie2? (expect false): " << (movie1 < movie2) << endl;
  cout << "movie1 < movie3? (expect true): "  << (movie1 < movie3) << endl;
  cout << "movie1 < movie4? (expect true): "  << (movie1 < movie4) << endl;
  cout << "movie1 < movie5? (expect false): " << (movie1 < movie5) << endl;
  cout << "movie1 < movie6? (expect false): " << (movie1 < movie6) << endl;
  cout << "movie1 < movie7? (expect false): " << (movie1 < movie7) << endl;
  cout << "movie1 < movie8? (expect false): " << (movie1 < movie8) << endl;

  cout << "movie5 < movie1? (expect false): " << (movie5 < movie1) << endl;
  cout << "movie5 < movie2? (expect false): " << (movie5 < movie2) << endl;
  cout << "movie5 < movie3? (expect false): " << (movie5 < movie3) << endl;
  cout << "movie5 < movie4? (expect false): " << (movie5 < movie4) << endl;
  cout << "movie5 < movie6? (expect true): "  << (movie5 < movie6) << endl;
  cout << "movie5 < movie7? (expect true): "  << (movie5 < movie7) << endl;
  cout << "movie5 < movie8? (expect false): " << (movie5 < movie8) << endl;

  // Test << operator
  cout << "movie1: " << movie1 << endl;
  cout << "movie2: " << movie2 << endl;
  cout << "movie3: " << movie3 << endl;
  cout << "movie4: " << movie4 << endl;
  cout << "movie5: " << movie5 << endl;
  cout << "movie6: " << movie6 << endl;
  cout << "movie7: " << movie7 << endl;
  cout << "movie8: " << movie8 << endl;
  return 0;
}