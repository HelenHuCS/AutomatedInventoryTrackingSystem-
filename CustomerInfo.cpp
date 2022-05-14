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
// This class keeps track of the customers of the movie store. The purpose of this class is to get 
// customer information and view the customer's transaction history.
// ------------------------------------------------------------------------------------------------
// Assumptions:
// Assume the input of “data4customers.txt” is formatted correctly and no need for handling any 
// exception. Assume the input of “data4commands.txt”  is formatted correctly, but need to handle 
// an invalid action code. For instance, if there is any invalid action code(‘X’ doesn’t exist),
// invalid video code(no such a type called ‘Y’), incorrect customer ID(couldn’t be found) or 
// invalid movie(couldn’t be found), discard the line and notify users with an error message.
// ----------------------------------CustomerInfo.cpp--------------------------------------------
#include "CustomerInfo.h" 

//================================================================================================
//!    DESCRIPTION:   The default Constructor for CustomerInfo
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:       Set all the valuables to default
//================================================================================================
CustomerInfo::CustomerInfo() 
{
  this->CustomerID = -1;
	this->firstName = "";
	this->lastName = "";
  historyHead = NULL;
}


//================================================================================================
//!    DESCRIPTION:   The Constructor that takes in customer ID, First Name, Last Name to create 
//!                   an object
//!
//!    INPUTS:        customer ID, First Name, Last Name 
//!
//!    OUTPUT:        N/A
//================================================================================================
CustomerInfo::CustomerInfo(int customerId, string firstName, string lastName)
{
  this->CustomerID = customerId;
	this->firstName = firstName;
	this->lastName = lastName;
  historyHead = NULL;
} //Constructor that takes ID, firstName and lastName

//================================================================================================
//!    DESCRIPTION:   Destructor for CustomerInfo
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        CustomerInfo is emptied and dynamically allocated memory as
//!                   CustomerInfo is deallocated
//================================================================================================
CustomerInfo::~CustomerInfo()
{
  CustomerHistory * current = historyHead;
  // Iterates through the whole customerHisotry to delete the pointer and make it empty
  while (current != NULL)
  {
    CustomerHistory * next = current->next;
    delete current;
    current = next;
  }
} //Destructor for CustomerInfo

//================================================================================================
//!    DESCRIPTION:   To display the transaction history of the customer
//!
//!    INPUTS:        Customer ID
//!
//!    OUTPUT:        Every history node in the linkedlist
//================================================================================================
void CustomerInfo::displayHistory()
{
  //Creates a current pointer pointing to customerHistory
  CustomerHistory * current = historyHead;
  //Iterates through the whole linkedlist and display the whole linkedlist

  if (current == NULL)
  {
    cout << "No history record for this customer" << endl;
  }
  while (current != NULL)
  {
    cout << current->getValue() <<endl;
    current = current->next;
  }
}
//================================================================================================
//!    DESCRIPTION:   To compare if the customer ID matches with the input
//!
//!    INPUTS:        Customer ID
//!
//!    OUTPUT:        Returns true if the customer ID matches with the input, vice versa
//================================================================================================
bool CustomerInfo::operator ==(const CustomerInfo& c)const
{
	if (this->CustomerID == c.CustomerID) 
  {
    return true;
  }
	return false;
}


//================================================================================================
//!    DESCRIPTION:   Adds a cmd to the customer's history
//!
//!    INPUTS:        string cmd
//!
//!    OUTPUT:        N/A
//================================================================================================
void CustomerInfo::addToHistory(string cmd)
{
    CustomerHistory * current = historyHead;
    historyHead = new CustomerHistory(cmd);
    historyHead->next = current;
}

//================================================================================================
//!    DESCRIPTION:   gets the customer ID of a customer
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        customerID as int
//================================================================================================
int CustomerInfo::getCustomerId()
{
  return CustomerID;
}

//================================================================================================
//!    DESCRIPTION:   gets the First Name of a customer
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        customerID as int
//================================================================================================
string CustomerInfo::getFirstName()
{
  return firstName;
}

//================================================================================================
//!    DESCRIPTION:   Gets the Last name of a customer
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        customerID as int
//================================================================================================
string CustomerInfo::getLastName()
{
  return lastName;  
}

//================================================================================================
//!    DESCRIPTION:   Gets the customer history of a customer
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        historyHead
//================================================================================================
CustomerHistory* CustomerInfo::getHistory() 
{
  return historyHead;
}