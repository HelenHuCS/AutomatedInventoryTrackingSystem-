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
// HashTable can be used to store data for retrieving using key-value pairs: database
// for customers.
// ------------------------------------------------------------------------------------------------
// Assumptions:
// Assumes that the customer id that is passed in is valid.
// Assumes that the CustomerInfo that is passed in is valid.
// Assumes that there will be no duplicate CustomerInfo.
// ------------------------------ HashTable.h --------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "CustomerInfo.h"

using namespace std;

// Global constant for the max number of customers
const int MAXCUSTOMERS = 103;

class HashTable
{
  public:
    // Constructor
	  HashTable();
    // Insert one CustomerInfo into the HashTable
    bool insertIntoTable(CustomerInfo customer);
    // Returns true if HashTable contains a CustomerInfo
    bool contains(int id);
    // Returns a CustomerInfo from the HashTable
	  CustomerInfo* retrieveCustomer(int id);	

  private:
    // database for the customers
    CustomerInfo customerDatabase[MAXCUSTOMERS];
    // generates the key from the customerId
    int generateKey(int customerId);
};

#endif