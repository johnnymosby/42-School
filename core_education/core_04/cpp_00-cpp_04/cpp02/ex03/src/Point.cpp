#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point(): x(0), y(0) {
}

Point::Point( const Point & src ) {
  *this = src;
}

Point::Point(const float first, const float second) {
  this->x = Fixed(first);
  this->y = Fixed(second);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &             Point::operator=(Point const & other)
{
  if (this != &other)
  {
    this->x = other.x;
    this->y = other.y;
  }
  return *this;
}

std::ostream &      operator<<( std::ostream & o, Point const & i )
{
  //o << "Value = " << i.getValue();
  return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */