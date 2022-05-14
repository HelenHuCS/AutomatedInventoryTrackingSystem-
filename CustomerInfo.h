// ------------------------------ Assignment 4 --------------------------------------------------
// Tyson Heo
// Helen Hu
// Kevin Huang
// CSS 502A
// Assignment 4: Implementation
// Creation Date: 3/01/2021
// Date of Last Modification: 3/17/2021
//
// Purpose:
// This class keeps track of the customers of the movie store. The purpose of this class is to get // customer information and view the customer's transaction history.
// ------------------------------------------------------------------------------------------------
// Assumptions:
// Assume the input of “data4customers.txt” is formatted correctly and no need for handling any 
// exception. Assume the input of “data4commands.txt”  is formatted correctly, but need to handle 
// an invalid action code. For instance, if there is any invalid action code(‘X’ doesn’t exist),
// invalid video code(no such a type called ‘Y’), incorrect customer ID(couldn’t be found) or 
// invalid movie(couldn’t be found), discard the line and notify users with an error message.
// ------------------------------------CustomerInfo.h--------------------------------------------
 
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "CustomerHistory.h"
using namespace std;

class CustomerInfo
{
public:
  // Default constructor for CustomerInfo
  CustomerInfo(); 
  // Constructor that takes ID, firstName and lastName
  CustomerInfo(int customerId, string firstName, string lastName);                                      
  //Destructor for CustomerInfo
  ~CustomerInfo();
 
  // Display the customer history
  void displayHistory();
  // Check if customerID is equal
  bool operator == (const CustomerInfo& c) const;
  // Add command to customer history
  void addToHistory(string cmd); 
  // Get customer ID of a customer ID
  int getCustomerId();
  // Get the First Name of the customer
  string getFirstName();
  //  Get the Last Name of the customer
  string getLastName();
  // Gets the customer history of a customer
  CustomerHistory* getHistory();

//Data fields for CustomerInfo
private:
  int CustomerID;
  string firstName;
  string lastName;
  // A linkedlist that contains all the customer history
  // Each transaction will be a node inside the linkedlist.
 	CustomerHistory * historyHead;
};
#endif /* CUSTOMERINFO_H */