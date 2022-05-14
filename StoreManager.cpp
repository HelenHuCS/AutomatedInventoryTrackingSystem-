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
// ------------------------------ StoreManager.cpp ------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include "StoreManager.h"

using namespace std;

//=================================================================================================
//!    DESCRIPTION:   StoreManager constructor initializes with an empty movie libaries and 
//!                   an empty customer database
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
StoreManager::StoreManager()
{

}

//=================================================================================================
//!    DESCRIPTION:   StoreManager deconstructor
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
StoreManager:: ~StoreManager()
{
  
}

//=================================================================================================
//!    DESCRIPTION:   Reads from an input text file and creates a movie list
//!
//!    INPUTS:        inputFile - name of the text file with movies
//!
//!    OUTPUT:        N/A
//=================================================================================================
void StoreManager::buildMovieLibrary(string inputFile)
{
  ifstream infile(inputFile);
  if (!infile)
	{
		cout << "File could not be opened." << endl;
		return;
	}

  while (infile.peek() != EOF)
  {
    // grab genre
    string fromLineGenre = "";
    getline(infile, fromLineGenre, ',');
    
    if (!fromLineGenre.compare("F")) // comedy movie
    {
      string fromLineStock = "";// grab stock
      getline(infile, fromLineStock, ','); 
      if (fromLineStock[0] == ' ') // remove starting space
      {
        fromLineStock = fromLineStock.substr(1);
      }

      // grab director
      string fromLineDirector = "";
      getline(infile, fromLineDirector, ',');
      if (fromLineDirector[0] == ' ') // remove starting space
      {
        fromLineDirector = fromLineDirector.substr(1);
      }

      // grab title
      string fromLineTitle = "";
      getline(infile, fromLineTitle, ',');
      if (fromLineTitle[0] == ' ') // remove starting space
      {
        fromLineTitle = fromLineTitle.substr(1);
      }

      // grab year
      string fromLineYear = "";
      getline(infile, fromLineYear, '\n');
      if (fromLineYear[0] == ' ') // remove starting space
      {
        fromLineYear = fromLineYear.substr(1);
      }

      // create movie object and insert into library
      Movie comedyMovie(fromLineGenre, fromLineDirector, fromLineTitle, stoi(fromLineStock), 
        stoi(fromLineYear));
      comedyLibrary.push_back(comedyMovie);
    } else if (!fromLineGenre.compare("D")) // drama movie
    {
   
      // grab stock
      string fromLineStock = "";
      getline(infile, fromLineStock, ',');
      if (fromLineStock[0] == ' ') // remove starting space
      {
        fromLineStock = fromLineStock.substr(1);
      }

      // grab director
      string fromLineDirector = "";
      getline(infile, fromLineDirector, ',');
      if (fromLineDirector[0] == ' ') // remove starting space
      {
        fromLineDirector = fromLineDirector.substr(1);
      }

      // grab title
      string fromLineTitle = "";
      getline(infile, fromLineTitle, ',');
      if (fromLineTitle[0] == ' ') // remove starting space
      {
        fromLineTitle = fromLineTitle.substr(1);
      }

      // grab year
      string fromLineYear = "";
      getline(infile, fromLineYear, '\n');
      if (fromLineYear[0] == ' ') // remove starting space
      {
        fromLineYear = fromLineYear.substr(1);
      }

      // create drama movie object and add to drama library
      Movie dramaMovie(fromLineGenre, fromLineDirector, fromLineTitle, stoi(fromLineStock), 
        stoi(fromLineYear));
      dramaLibrary.push_back(dramaMovie);
    } else if (!fromLineGenre.compare("C")) // classics movie
    {
      // grab stock
      string fromLineStock = "";
      getline(infile, fromLineStock, ',');
      if (fromLineStock[0] == ' ') // remove starting space
      {
        fromLineStock = fromLineStock.substr(1);
      }

      // grab director
      string fromLineDirector = "";
      getline(infile, fromLineDirector, ',');
      if (fromLineDirector[0] == ' ') // remove starting space
      {
        fromLineDirector = fromLineDirector.substr(1);
      }

      // grab title
      string fromLineTitle = "";
      getline(infile, fromLineTitle, ',');
      if (fromLineTitle[0] == ' ') // remove starting space
      {
        fromLineTitle = fromLineTitle.substr(1);
      }

      // grab first name
      string fromLineFirstName = "";
      getline(infile, fromLineFirstName, ' '); // skip over space before first name
      getline(infile, fromLineFirstName, ' ');
      if (fromLineFirstName[0] == ' ') // remove starting space
      {
        fromLineFirstName = fromLineFirstName.substr(1);
      }

      // grab last name
      string fromLineLastName = "";
      getline(infile, fromLineLastName, ' ');
      if (fromLineLastName[0] == ' ') // remove starting space
      {
        fromLineLastName = fromLineLastName.substr(1);
      }

      // grab month
      string fromLineMonth = "";
      getline(infile, fromLineMonth, ' ');
      if (fromLineMonth[0] == ' ') // remove starting space
      {
        fromLineMonth = fromLineMonth.substr(1);
      }

      // grab year
      string fromLineYear = "";
      getline(infile, fromLineYear, '\n');
       if (fromLineYear[0] == ' ') // remove starting space
      {
        fromLineYear = fromLineYear.substr(1);
      }

      // combine names to make full name
      string fullName = fromLineFirstName + " " + fromLineLastName;

      // create classics movie object and add to classics library
      MovieClassics classicsMovie(fromLineGenre, fromLineDirector, fromLineTitle, fullName, 
        stoi(fromLineStock), stoi(fromLineYear), stoi(fromLineMonth));
      classicsLibrary.push_back(classicsMovie);
    } else // no match 
    {
      string line = "";
      getline(infile, line); // grab and discard line
    }
  }

  // sort the libraries
  comedyLibrary.sort();
  comedyLibrary.unique();
  dramaLibrary.sort();
  dramaLibrary.unique();
  classicsLibrary.sort();
  classicsLibrary.unique();
}    

//=================================================================================================
//!    DESCRIPTION:   Reads from an input text file and creates customer hash table
//!
//!    INPUTS:        inputFile - name of the text file with customers
//!
//!    OUTPUT:        N/A
//=================================================================================================
void StoreManager::buildCustomerDatabase(string inputFile)
{
	ifstream infile(inputFile);
	if (!infile)
	{
		cout << "File could not be opened." << endl;
		return;
	}

  // parse text file for information to build customerInfo objects
  string tmp = "";
  while (getline(infile, tmp, ' '))
  {
    int id = stoi(tmp);
    getline(infile, tmp, ' ');
    string lastName = tmp;
    getline(infile, tmp, '\n');
    string firstName = tmp;
    CustomerInfo temp(id, firstName, lastName);
    customerDatabase.insertIntoTable(temp);
  }
}

//=================================================================================================
//!    DESCRIPTION:   Read from an input text file and processes commands
//!
//!    INPUTS:        inputFile - name of the text file with commands
//!
//!    OUTPUT:        N/A
//=================================================================================================
void StoreManager::processCommands(string inputFile)
{
  ifstream infile(inputFile);
	if (!infile)
	{
		cout << "File could not be opened." << endl;
		return;
	}

  // parse text file for commands
  string action = "";
  while (getline(infile, action))
  {
    if (action.at(0) == 'B') {
      borrow(action);
    } else if (action.at(0) == 'R') {
      ret(action);
    } else if (action.at(0) == 'I') {
      inventory();
    } else if (action.at(0) == 'H') {
      history(stoi(action.substr(2, 4)));
    } else {
      cout << action.at(0) << " is not a valid command." << endl;;
    }
  }
}    

//=================================================================================================
//!    DESCRIPTION:   It decreases the stock of a certain movie and adds transaction to the cutomer's 
//!                   history. It will check if the parameters are valid and if the stock is not 
//!                   below 0. 
//!                   It will output error messages for incorrect data and/or incorrect command.
//!
//!    INPUTS:        movieData - one line of command from the commmands text file
//!
//!    OUTPUT:        N/A
//=================================================================================================
void StoreManager::borrow(string movieData)
{
  int id = stoi(movieData.substr(2,4));
  int year,month;
  string title,majorActor,director;
  list<Movie>::iterator iterm;
  list<MovieClassics>::iterator iterc;

  // Check media type is DVD
  if (movieData.at(7) != 'D'){
    cout << movieData.at(7) << " is an invalid media type" << endl;
    return;
  }

  // Check if customer exists in database
  CustomerInfo* customer = customerDatabase.retrieveCustomer(id);
  if (customer == NULL)
  {
    cout << "Customer id: " << id << "is not in customer database" << endl;
    return;
  }
  
  // Check if media type is supported
  char type = movieData.at(9);
  // If not C, D, or F, genre type is invalid
  if ((type != 'C') && (type != 'D') && (type != 'F'))
  {
    cout << type << " is an invalid movie type" << endl;
    return;
  }
  else if (type == 'C')
  {
    // Grab movie information
    month      = stoi(movieData.substr(11,movieData.find(' ',11)-11));
    year       = stoi(movieData.substr(movieData.find(' ',11)+1,4));
    majorActor = movieData.substr(movieData.find(' ',11)+6);
    iterc      = classicsLibrary.begin();

    // Loop until we find correct entry or hit the end of the library
    while ((iterc != classicsLibrary.end()) && ((iterc->getMonth() != month) ||
      (iterc->getYear() != year) || (iterc->getMajorActor().compare(majorActor.substr
      (0, iterc->getMajorActor().length())) != 0 ))) 
    {
      iterc++;
    }

    // Movie does not exist in the library
    if (iterc == classicsLibrary.end()){
      cout << "Invalid classic movie" << movieData << endl;
      return;
    }
    
    // Movie has no more stock
    if (iterc->getStock() <= 0){
      cout << "no more stock: " << iterc->getStock() << endl;
      return;
    }
    
    // Movie was found and has enough stock.
    // Decrement stock and add transaction to customer history
    iterc->removeStock();
    customer->addToHistory(movieData);
  }
  else if (type == 'F')
  {
    // Grab movie information
    title = movieData.substr(11,movieData.find(',',11)-11);
    year  = stoi(movieData.substr(movieData.find(',',11)+2));
    iterm = comedyLibrary.begin();
    
    // Loop until we find correct entry or hit end of the library
    while ((iterm != comedyLibrary.end()) && ((iterm->getYear() != year) ||
      (iterm->getTitle() != title.substr(0, iterm->getTitle().length()))))
    {
      iterm++;  
    } 
    
    // Movie does not exist in the library
    if (iterm == comedyLibrary.end())
    {
      cout << "Invalid comedy movie: " << movieData << endl;
      return;
    }
    
    // Movie has no more stock
    if (iterm->getStock() <= 0)
    {
      cout << "no more stock: " << iterm->getStock() << endl;
      return;
    }
    
    // Movie was found and has enough stock.
    // Decrement stock and add transaction to customer history
    iterm->removeStock();
    customer->addToHistory(movieData);
  }
  else if (type == 'D')
  {
    // Grab movie information
    director = movieData.substr(11,movieData.find(',',11)-11);
    title    = movieData.substr(movieData.find(',',11)+2);
    iterm    = dramaLibrary.begin();

    // Loop until we find correct entry or hit end of the library
    while ((iterm != dramaLibrary.end()) && ((iterm->getDirector() != director) ||
      (iterm->getTitle() != title.substr(0, iterm->getTitle().length())) ))
    {
      iterm++;
    } 

    // Movie does not exist in the library
    if (iterm == dramaLibrary.end())
    {
      cout << "Invalid drama movie: " << movieData << endl;
      return;
    }
    
    // Movie has no more stock
    if (iterm->getStock() <= 0)
    {
      cout << "no more stock: " << iterm->getStock() << endl;
      return;
    }

    // Movie was found and has enough stock.
    // Decrement stock and add transaction to the customer history
    iterm->removeStock();
    customer->addToHistory(movieData);
  }
}

//=================================================================================================
//!    DESCRIPTION:   It increases the stock of a certain movie and adds transaction to the customer
//!                   history. It will check if the parameters are valid and if the movie has been 
//!                   borrowed. It will output error messages for incorrect data and/or incorrect 
//!                   command.
//!
//!    INPUTS:        movieData - one line of command from the commmands text file
//!
//!    OUTPUT:        N/A
//=================================================================================================
void StoreManager::ret(string movieData)
{
  int id = stoi(movieData.substr(2,4));
  int year,month;
  string title,majorActor,director;
  list<Movie>::iterator iterm;
  list<MovieClassics>::iterator iterc;

  // Check media type is DVD
  if (movieData.at(7) != 'D'){
    cout << movieData.at(7) << " is an invalid media type" << endl;
    return;
  }

  // Check if customer exists in database
  CustomerInfo* customer = customerDatabase.retrieveCustomer(id);
  if (customer == NULL)
  {
    cout << "Customer id: " << id << "is not in customer database" << endl;
    return;
  }
  
  char type = movieData.at(9);
  // if not C, D, or F, genre type is invalid
  if ((type != 'C') && (type != 'D') && (type != 'F'))
  {
    cout << type << " is an invalid movie type" << endl;
    return;
  }
  else if (type == 'C')
  {
    month      = stoi(movieData.substr(11,movieData.find(' ',11)-11));
    year       = stoi(movieData.substr(movieData.find(' ',11)+1,4));
    majorActor = movieData.substr(movieData.find(' ',11)+6);
    iterc      = classicsLibrary.begin();

    // Loop until we find correct entry or hit end of the library
    while ((iterc != classicsLibrary.end()) && ((iterc->getMonth() != month) ||
      (iterc->getYear() != year) || (iterc->getMajorActor().compare(majorActor.substr
      (0, iterc->getMajorActor().length())) != 0))) 
    {
      iterc++;
    }

    // Movie does not exist in the library
    if (iterc == classicsLibrary.end())
    {
      cout << "Invalid classic movie" << movieData << endl;
      return;
    }

    CustomerInfo* temp = customerDatabase.retrieveCustomer(id);
    CustomerHistory* p = temp->getHistory();
    int borrowed = 0;
    int returned = 0;
    while (p != nullptr)
    {
      string movieHistoryData = p->getValue();
      // Only compare classics movie against classics movie
      if (movieHistoryData.at(9) == 'C')
      {
        int movieHistoryMonth = stoi(movieHistoryData.substr(11,movieHistoryData.find(' ',11)-11));
        int movieHistoryYear = stoi(movieHistoryData.substr(movieHistoryData.find(' ',11)+1,4));
        string movieHistoryMajorActor = movieHistoryData.substr(movieHistoryData.find(' ',11)+6);

        // Command B and movie matches, increment borrowed counter
        if ((movieHistoryData.at(0) == 'B') && (movieHistoryMonth == month) &&
          (movieHistoryYear == year) && !iterc->getMajorActor().compare(movieHistoryMajorActor.substr(0, iterc->getMajorActor().length())))
        {
          borrowed++;
        }
        
        // Command R and movie matches, increment returned counter
        if ((movieHistoryData.at(0) == 'R') && (movieHistoryMonth == month) &&
          (movieHistoryYear == year) && !iterc->getMajorActor().compare(movieHistoryMajorActor.substr(0, iterc->getMajorActor().length())))
        {
          returned++;
        }
      }

      p = p->next;
    }
    
    // Initialize the counter to check if the movie has been borrowed before returning
    int result = borrowed - returned;
    // If the counter is >= 1, add the movie to stock and add the transaction to customer history
    // Otherwise, delete the command and print error message
    if (result >= 1) 
    {
      iterc->addStock();
      customer->addToHistory(movieData);
    } else 
    {
      cout << "Classics movie was not returned(" << borrowed << " "  << returned << "): " << movieData << endl;
      return;
    }
  }
  else if (type == 'F')
  {
    title = movieData.substr(11,movieData.find(',',11)-11);
    year  = stoi(movieData.substr(movieData.find(',',11)+2));
    iterm = comedyLibrary.begin();
    
    // Loop until we find correct entry or hit end of the library    
    while ((iterm != comedyLibrary.end()) && ((iterm->getYear() != year) ||
      (iterm->getTitle() != title.substr(0, iterm->getTitle().length()))))
    {
      iterm++;  
    } 
    
    // Movie does not exist in the library
    if (iterm == comedyLibrary.end())
    {
      cout << "Invalid comedy movie: " << movieData << endl;
      return;
    }
    
    CustomerInfo* temp = customerDatabase.retrieveCustomer(id);
    CustomerHistory* p = temp->getHistory();
    int borrowed = 0;
    int returned = 0;
    while (p != nullptr)
    {
      string movieHistoryData  = p->getValue();
      if (movieHistoryData.at(9) == 'F') 
      {
        string movieHistoryTitle = movieData.substr(11,movieData.find(',',11)-11);
        int movieHistoryYear     = stoi(movieData.substr(movieData.find(',',11)+2));

        // Command B and movie matches, increment borrowed counter
        if ((movieHistoryData.at(0) == 'B') && (movieHistoryYear == year) &&
          !movieHistoryTitle.compare(title))
        {
          borrowed++;
        }
      
        // Command R and movie matches, increment returned counter
        if ((movieHistoryData.at(0) == 'R') && (movieHistoryYear == year) &&
          !movieHistoryTitle.compare(title))
        {
          returned++;
        }
      }
      p = p->next;
    }
    // Initialize the counter to check if the movie has been borrowed before returning
    int result = borrowed - returned;
    // If the counter is >= 1, add the movie to stock and add the transaction to customer history
    // Otherwise, delete the command and print error message
    if (result >= 1) 
    {
      iterm->addStock();
      customer->addToHistory(movieData);
    } else 
    {
      cout << "Comedy movie was not returned: " << movieData << endl;
      return;
    }
  }
  else if (type == 'D')
  {
    director = movieData.substr(11,movieData.find(',',11)-11);
    title    = movieData.substr(movieData.find(',',11)+2);
    iterm    = dramaLibrary.begin();
    
    // Loop until we find correct entry or hit end of the library 
    while ((iterm != dramaLibrary.end()) && ((iterm->getDirector().compare(director) != 0) 
      ||(iterm->getTitle().compare(title.substr(0, iterm->getTitle().length())) != 0)))
    {
      iterm++;
    }

    // Movie does not exist in the library  
    if (iterm == dramaLibrary.end())
    {
      cout << "Invalid drama movie: " << movieData << endl;
      return;
    }

    CustomerInfo* temp = customerDatabase.retrieveCustomer(id);
    CustomerHistory* p = temp->getHistory();
    int borrowed = 0;
    int returned = 0;
    while (p != nullptr)
    {
      string movieHistoryData  = p->getValue();
      if (movieHistoryData.at(9) == 'D')
      {
        string movieHistoryDirector = movieData.substr(11,movieData.find(',',11)-11);
        string movieHistoryTitle    = movieData.substr(movieData.find(',',11)+2);

        // Command B and movie matches, increment borrowed counter
        if ((movieHistoryData.at(0) == 'B') && (!movieHistoryDirector.compare(director)) &&
         !iterm->getTitle().compare(movieHistoryTitle.substr(0, iterm->getTitle().length())))
        {
          borrowed++;
        }
        
        // Command R and movie matches, increment returned counter
        if ((movieHistoryData.at(0) == 'R') && (!movieHistoryDirector.compare(director)) &&
         !iterm->getTitle().compare(movieHistoryTitle.substr(0, iterm->getTitle().length())))
        {
          returned++;
        }
      }
      
      p = p->next;
    }
    
    // Initialize the counter to check if the movie has been borrowed before returning
    int result = borrowed - returned;
    // If the counter is >= 1, add the movie to stock and add the transaction to customer history
    // Otherwise, delete the command and print error message
    if (result >= 1) 
    {
      iterm->addStock();
      customer->addToHistory(movieData);
    } else 
    {
      cout << "Drama movie was not returned: " << movieData << endl;
      return;
    }
  }
}

//=================================================================================================
//!    DESCRIPTION:   Inventory displays all the movies in the library
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        Prints out all comedy, drama, and classics movies with one line per movie 
//=================================================================================================
void StoreManager::inventory()
{
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "------------------------------------Printing Inventory--------------------------" << endl;
  cout << "--------------------------------------------------------------------------------" << endl;

  cout << "(Genre, Stock, Director, Title, Year)"<< endl;
  // Print inventory for comedy movies
  for (list<Movie>::iterator it=comedyLibrary.begin(); it != comedyLibrary.end(); ++it)
  {
    cout << *it << endl;
  }

  cout << endl;
  cout << "(Genre, Stock, Director, Title, Year)"<< endl;
  // Print inventory for drama movies
  for (list<Movie>::iterator it=dramaLibrary.begin(); it != dramaLibrary.end(); ++it)
  {
    cout << *it << endl;
  }

  cout << endl;
  cout << "(Genre, Stock, Director, Title, Major Actor, Month, Year)"<< endl;
  // Print inventory for classics movies
  for (list<MovieClassics>::iterator it1=classicsLibrary.begin(); it1 != classicsLibrary.end();
     ++it1)
  {
    // Set initial information
    string currTitle    = it1->getTitle();
    string currDirector = it1->getDirector();
    int currSum         = it1->getStock();
    int runningSum      = 0;
    int duplicateCount  = 0;

    // From current location, check if there are any more duplicates.
    // Iterate as long as it's not at the end of the classicsLibrary and title and director match 
    for (list<MovieClassics>::iterator it2 = it1; (it2 != classicsLibrary.end() &&
      (it2->getTitle() == currTitle) && (it2->getDirector() == currDirector)); ++it2)
    {
        runningSum += it2->getStock();
        duplicateCount++;
    }

    // print differs depending on if duplicate found or not
    if (runningSum == currSum) // no duplicates found
    {
      cout << *it1 << endl;
    } else // duplicate found
    {
      cout << it1->getGenre() << ", " << runningSum << ", " << it1->getDirector() 
        << ", " << it1->getTitle() << endl;
      for (int i = 0; i < duplicateCount; i++)
      {
        cout << "    " << *it1 << endl;
        ++it1; // move iterator forward for how many duplicates there were
      }
    }
  }
}

//=================================================================================================
//!    DESCRIPTION:   History displays the transction history of the customer
//!
//!    INPUTS:        customerId - unique id number of customer
//!
//!    OUTPUT:        Prints out transactions from most recent to oldest
//=================================================================================================
void StoreManager::history(int customerId)
{
  // If customer is in customer database, call displayHistory
  // Otherwise, print error message
  if (customerDatabase.contains(customerId))
  {
    CustomerInfo *temp = customerDatabase.retrieveCustomer(customerId);
      cout << "--------------------------------------------------------------------------------" << endl;
      cout << "----------------------------Printing ";
      cout << temp->getFirstName() << " " << temp->getLastName() << "'s " << "history---------------------" << endl;
      cout << "--------------------------------------------------------------------------------" << endl;
    temp->displayHistory();
    cout << endl;
  } else 
  {
    cout << customerId << " is not a valid customer ID." << endl;
  }
}