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
// This class stores the customer history and deletes customer history.
// ------------------------------------------------------------------------------------------------
// Assumptions:
// N/A
// ------------------------------ CustomerHistory.h ---------------------------------------------
 
#ifndef CUSTOMERHISTORY_H
#define CUSTOMERHISTORY_H
#include <iostream>
using namespace std;

//CustomerHistory class
class CustomerHistory
{
public:
  //Constructor for CustomerHistory
  CustomerHistory(string cmd);
  //Destructor for CustomerHistory
  ~CustomerHistory();
  // Get value 
  string getValue(); 
  //CustomerHistory pointer
  CustomerHistory * next;

private:
  string value;
};
#endif 