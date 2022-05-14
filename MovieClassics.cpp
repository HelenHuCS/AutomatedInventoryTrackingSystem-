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
// This MovieClassics class handles creation of MovieClassics objects as well as getting the 
// information for the movie. 
// ------------------------------------------------------------------------------------------------
// Assumptions:
// MovieClassics values are valid inputs in regards to type. You can however send in X or Y 
// instead of C
// ------------------------------ MovieClassics.cpp -----------------------------------------------

#include "MovieClassics.h"

//=================================================================================================
//!    DESCRIPTION:   default MovieClassics constructor. Initializes variables to empty or empty 
//!                   equivalent
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
MovieClassics::MovieClassics()
{
    // create with default blank values
    genre = "";
    director = "";
    title = "";
    majorActor = "";
    stock = 0;
    year = 0;
    month = 0;
}

//=================================================================================================
//!    DESCRIPTION:   MovieClassics constructor from given inputs
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
MovieClassics::MovieClassics(string inGenre, string inDirector, string inTitle, string inMajorActor,
    int inStock, int inYear, int inMonth)
{
    // create from input value
    genre = inGenre;
    director = inDirector;
    title = inTitle;
    majorActor = inMajorActor;
    stock = inStock;
    year = inYear;
    month = inMonth; 
}

//=================================================================================================
//!    DESCRIPTION:   Default desconstructor for MovieClassics class. 
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        N/A
//=================================================================================================
MovieClassics::~MovieClassics()
{
    genre = "";
    director = "";
    title = "";
    majorActor = "";
    stock = 0;
    year = 0;
    month = 0;
}

//=================================================================================================
//!    DESCRIPTION:   Returns the classics movie's major actor first and last name as a string
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        majorActor - first and last name of major actor as single string
//=================================================================================================
string MovieClassics::getMajorActor()
{
    return majorActor;
}

//=================================================================================================
//!    DESCRIPTION:   Returns the classics movie's month
//!
//!    INPUTS:        N/A
//!
//!    OUTPUT:        month - month as int of the classics movie
//=================================================================================================
int MovieClassics::getMonth()
{
    return month;
}

//=================================================================================================
//!    DESCRIPTION:   Comparator operator to compare one MovieClassics object against another. 
//!                   Compares by release date and then major actor
//!
//!    INPUTS:        rhs - MovieClassics on the right hand side of the argument
//!
//!    OUTPUT:        bool - true if left is less than right side, false otherwise
//=================================================================================================
bool MovieClassics::operator<(const MovieClassics& rhs) const
{
    if (!genre.compare(rhs.genre) && !genre.compare("C")) // we are classics movie
    {
        if (year < rhs.year) // if year is earlier, automatically less
        {
            return true;
        } else if (year > rhs.year) // lhs > rhs, then return flase
        {
            return false;
        } else // years are equal, check the months
        {
            if (month < rhs.month) // lhs month < rhs month
            {
                return true;
            } else if (month > rhs.month) // lhs > rhs, return false
            {
                return false;
            } else // months are also equal, compare major actor name
            {
                if (majorActor.compare(rhs.majorActor) < 0) // check 
                {
                    return true;
                } else 
                {
                    return false;
                }
            }
        }
    } else // Illegal comparing of classics to other movie
    {
        return false;
    }
}

//=================================================================================================
//!    DESCRIPTION:   Equivalency operator to check if one MovieClassics Object is the exact same 
//!                   as another
//!
//!    INPUTS:        rhs - Movie on the right hand side of the argument
//!
//!    OUTPUT:        bool - true if both MoviesClassics are the same, false otherwise
//=================================================================================================
bool MovieClassics::operator==(const MovieClassics &rhs) const
{
  if ((genre == rhs.genre) && 
    (director == rhs.director) && 
    (title == rhs.title) && 
    (stock == rhs.stock) && 
    (year == rhs.year) && 
    (majorActor == rhs.majorActor) && 
    (month == rhs.month))
  {
    return true;
  } else
  {
    return false;
  }
}

//=================================================================================================
//!    DESCRIPTION:   ostream output for a  movieClassics object
//!
//!    INPUTS:        output  - ostream output 
//!                   inMovie - MovieClassics to print
//!
//!    OUTPUT:        N/A
//=================================================================================================
ostream& operator<<(ostream& output, const MovieClassics& inMovie) 
{
  if (!inMovie.genre.compare("C")) // classics movie
  {
    output << inMovie.genre << ", " << inMovie.stock << ", " << inMovie.director << ", " 
      << inMovie.title << ", " << inMovie.majorActor << " " << inMovie.month << " " 
      << inMovie.year;
  } else // invalid movie
  {
    output << "Invalid action" << endl;
  }
  
	return output;
}