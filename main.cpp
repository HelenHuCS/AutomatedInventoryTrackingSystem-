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
// This program is to design and implement an automated inventory system for a local movie rental
// store. The system should be able to initialize an inventory of movies from a file 
// (data4movies.txt), a customer list from another file(data4customers.txt) and process commands
// from a third file(data4commands.txt). After processing the commands, the system displays the
// searching results for the movie or the customer.
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
// ------------------------------ main.cpp --------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string> 
#include "StoreManager.h"

using namespace std;

//=================================================================================================
//!    DESCRIPTION:   reads from an input text files and creates a movie list and a customer list
//!
//!    INPUTS:        customer info, movie info, and commands
//!
//!    OUTPUT:        The system displays the inventory and history commands
//=================================================================================================
int main()
{
  string file1 = "data4customers.txt";
  string file2 = "data4movies.txt";
  string file3 = "data4commands.txt";
  StoreManager Leo;
  Leo.buildCustomerDatabase(file1);
  Leo.buildMovieLibrary(file2);
  Leo.processCommands(file3);

  return 0;
}
