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
// ------------------------------ HashTable.cpp --------------------------------------------------

#include "HashTable.h"

//=================================================================================================
//!    DESCRIPTION:   Constructor that initializes HashTable with empty CustomerInfo in each array
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
HashTable::HashTable() 
{
  for (int i = 0; i < MAXCUSTOMERS; i++) 
  {
    customerDatabase[i] = CustomerInfo();
  }
}

//================================================================================================
//!    DESCRIPTION:   Generates a key and adds CustomerInfo into HashTable
//!
//!    INPUTS:        customer - CustomerInfo to be added
//!
//!    OUTPUT:        N/A
//==================================================================================================
bool HashTable::insertIntoTable(CustomerInfo customer) 
{
  if (!contains(customer.getCustomerId())) {
    int key = generateKey(customer.getCustomerId());
    while (key < MAXCUSTOMERS) {
      if (customerDatabase[key].getCustomerId() == -1) 
      {
        customerDatabase[key] = customer;
        return true;
      } else 
      {
        key++;
      }
    }
  }
  cout << "Customer is already in database."<< endl;
  return false;
}

//=================================================================================================
//!    DESCRIPTION:   Returns true if the CustomerInfo is found in the HashTable
//!
//!    INPUTS:        id - id of CustomerInfo
//!
//!    OUTPUT:        N/A
//=================================================================================================
bool HashTable::contains(int id) 
{
  int key = generateKey(id);
  while (key < MAXCUSTOMERS) 
  {
    if (customerDatabase[key].getCustomerId() == id) 
    {
      return true;
    }

    if (customerDatabase[key].getCustomerId() == -1) 
    {
      return false;
    }

    key++;
  }

  return false;
}

//=================================================================================================
//!    DESCRIPTION:   Returns a pointer to the found CustomerInfo in the HashTable
//!
//!    INPUTS:        id - id of CustomerInfo
//!
//!    OUTPUT:        N/A
//=================================================================================================
CustomerInfo* HashTable::retrieveCustomer(int id) 
{
  CustomerInfo *temp;
  if (contains(id)) 
  {
    int key = generateKey(id);
    while (key < MAXCUSTOMERS) 
    {
      if (customerDatabase[key].getCustomerId() == id) {
        temp = &customerDatabase[key];
        return temp;
      }

      key++;
    }
  }

  return temp;
}

//=================================================================================================
//!    DESCRIPTION:   Creates a key with a given customer id
//!
//!    INPUTS:        customerId - id of CustomerInfo
//!
//!    OUTPUT:        N/A
//=================================================================================================
int HashTable::generateKey(int customerId) 
{
  return (customerId % MAXCUSTOMERS);
}