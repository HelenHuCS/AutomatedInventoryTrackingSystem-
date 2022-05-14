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
// This Movie class handles the creation of Movie objects as well as getting the 
// information for the movie. 
// ------------------------------------------------------------------------------------------------
// Assumptions:
// Movie values are valid inputs in regards to type. You can however send in X or Y instead of C
// ------------------------------ Movie.cpp -------------------------------------------------------
#include "Movie.h"

//=================================================================================================
//!    DESCRIPTION:   Default constructor of movie object
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
Movie::Movie()
{
  // Create with default blank values
  genre = "";
  director = "";
  title = "";
  stock = 0;
  year = 0;
}

//=================================================================================================
//!    DESCRIPTION:   Constructor for movie object from given inputs
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
Movie::Movie(string inGenre, string inDirector, string inTitle, int inStock, int inYear)
{
  // create from input values
  genre = inGenre;
  director = inDirector;
  title = inTitle;
  stock = inStock;
  year = inYear;
}

//=================================================================================================
//!    DESCRIPTION:   default destructor for Movie object
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
Movie::~Movie()
{
  // create with default blank values
  genre = "";
  director = "";
  title = "";
  stock = 0;
  year = 0;
}

//=================================================================================================
//!    DESCRIPTION:   returns the movie object's genre
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        string genre - genre of the movie
//=================================================================================================
string Movie::getGenre()
{
  return genre;
}

//=================================================================================================
//!    DESCRIPTION:   returns the movie object's director
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        string director - director of the movie
//=================================================================================================
string Movie::getDirector()
{
  return director;
}

//=================================================================================================
//!    DESCRIPTION:   returns the movie object's title
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        string title - title of the movie
//=================================================================================================
string Movie::getTitle()
{
  return title;
}

//=================================================================================================
//!    DESCRIPTION:   returns the movie object's stock amount
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        int stock - stock of the movie
//=================================================================================================
int Movie::getStock()
{
  return stock;
}

//=================================================================================================
//!    DESCRIPTION:   Increments the stock of a movie 
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
void Movie::addStock()
{
  stock++;
}

//=================================================================================================
//!    DESCRIPTION:   decrement the stock of a movie if stock is above 0
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
void Movie::removeStock()
{
  // only decrement stock if above 0
  if (stock > 0)
  {
      stock--;
  }
}

//=================================================================================================
//!    DESCRIPTION:   returns the movie object's year
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        int year - the year of the movie object
//=================================================================================================
int Movie::getYear()
{
  return year;
}

//=================================================================================================
//!    DESCRIPTION:   Comparator operator to compare one Movie object against another. 
//!                   Compares by title and then year if a comedy movie.
//!                   Compares by director and then title if a drama movie.
//!
//!    INPUTS:        rhs - Movie on the right hand side of the argument
//!
//!    OUTPUT:        bool - true if left is less than right side, false otherwise
//=================================================================================================
bool Movie::operator<(const Movie& rhs) const
{
  if (!genre.compare(rhs.genre) && !genre.compare("F")) // comparing comedy movies
  {
    if (title < rhs.title) // if title is earlier, automatically less
    {
      return true;
    } else if (title > rhs.title) // lhs > rhs, then return flase
    {
      return false;
    } else // titles are equal, check the year
    {
      if (year < rhs.year) // lhs year < rhs year
      {
          return true;
      } else if (year >= rhs.year) // lhs > rhs, return false
      {
          return false;
      }
    }
  } else if (!genre.compare(rhs.genre) && !genre.compare("D")) // comparing drama movies
  {
    if (director < rhs.director) // if director is earlier, automatically less
    {
      return true;
    } else if (director > rhs.director) // lhs > rhs, then return flase
    {
      return false;
    } else // director are equal, check the year
    {
      if (title < rhs.title) // lhs year < rhs year
      {
          return true;
      } else if (title >= rhs.title) // lhs > rhs, return false
      {
          return false;
      }
    }
  } else // comparing against a movie that is not a comedy or drama
  {
      return false;
  }
  return false;
}

//=================================================================================================
//!    DESCRIPTION:   Equivalency operator to check if one Movie Object is the exact same as another
//!
//!    INPUTS:        rhs - Movie on the right hand side of the argument
//!
//!    OUTPUT:        bool - true if both Movies are the same, false otherwise
//=================================================================================================
bool Movie::operator==(const Movie &rhs) const
{
  if ((genre == rhs.genre) && 
    (director == rhs.director) && 
    (title == rhs.title) && 
    (stock == rhs.stock) && 
    (year == rhs.year))
  {
    return true;
  } else
  {
    return false;
  }
}

//=================================================================================================
//!    DESCRIPTION:   ostream output for a  Movie object
//!
//!    INPUTS:        output  - ostream output 
//!                   inMovie - Movie to print
//!
//!    OUTPUT:        N/A
//=================================================================================================
ostream& operator<<(ostream& output, const Movie& inMovie) 
{
  if (!inMovie.genre.compare("F") || !inMovie.genre.compare("D")) // comedy or drama movie
  {
    output << inMovie.genre << ", " << inMovie.stock << ", " << inMovie.director << ", " 
      << inMovie.title << ", " << inMovie.year;
  } else // invalid movie
  {
    output << "Invalid action" << endl;
  }
  
	return output;
}