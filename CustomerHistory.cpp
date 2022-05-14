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
// ------------------------------ CustomerHistory.cpp ---------------------------------------------
#include "CustomerHistory.h" 

//================================================================================================
//!    DESCRIPTION:   Adds a cmd to the customer's history
//!
//!    INPUTS:        string cmd
//!
//!    OUTPUT:        N/A
//=================================================================================================
CustomerHistory::CustomerHistory(string cmd)
{
  this->value = cmd;
  next = NULL;
}
//=================================================================================================
//!    DESCRIPTION:  Destructor for CustomerHistory class
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
CustomerHistory:: ~CustomerHistory()
{
  
}

string CustomerHistory:: getValue()
{
  return this->value;
}

