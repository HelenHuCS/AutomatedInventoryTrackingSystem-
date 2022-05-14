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
// This class contains the actions for the inventory tracking system at the movie rental store.
// The class keeps a database for the inventory of the movies as well as an additional database
// for the movie rental store’s customers. The actions allow one to update the stock of each
// movie as well as to output the movie inventory. There are also actions to add transaction
// history to the customer’s information.
// ------------------------------------------------------------------------------------------------
// Assumptions:
// Assume input data is formatted correctly, but codes might be invalid; For instance, the input 
// file “data4movies.txt” might have an invalid entry: “Z” code, when processing the movie list. 
// The line with invalid entry “Z” code should be discarded and print an error message to notify 
// the user for incorrect data or incorrect command. 
// Assume the input of “data4customers.txt” is formatted correctly and no need for handling any 
// exception. Assume the input of “data4commands.txt”  is formatted correctly, but need to handle 
// an invalid action code. For instance, if there is any invalid action code(‘X’ doesn’t exist),
// invalid video code(no such a type called ‘Y’), incorrect customer ID(couldn’t be found) or 
// invalid movie(couldn’t be found), discard the line and notify users with an error message.
// If there is any incorrect command, the program needs to handle the exception. For example, a
// command that makes the stock of a movie item in the inventory go below 0, a return command when
// a movie hasn’t been borrowed yet, and so on.
// ------------------------------ StoreManagerDriver.cpp ------------------------------------------

#include <iostream>
#include "StoreManager.h"

using namespace std;

// g++ HashTable.cpp CustomerHistory.cpp CustomerInfo.cpp Movie.cpp MovieClassics.cpp StoreManager.cpp StoreManagerDriver.cpp
// Test for StoreManager

int main() {

  StoreManager G;

  G.buildCustomerDatabase("data4customers.txt");
  cout << "customerDatabase built" << endl;
  cout << endl;

  G.buildMovieLibrary("data4movies.txt");
  cout << "movie library built" << endl;
  cout << endl;

  G.processCommands("data4commands.txt");
  G.processCommands("data4commands2.txt");
  cout << "commands processed" << endl;
  
  return 0;
}