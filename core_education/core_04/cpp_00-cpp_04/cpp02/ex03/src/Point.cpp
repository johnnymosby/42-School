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

Point::Point(Fixed first, Fixed second) {
  this->x = first;
  this->y = second;
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

std::ostream &      operator<<( std::ostream & os, Point const & i )
{
  os << '(' << i.getX() << ", " << i.getY() << ")\n";
  return os;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed const & Point::getX() const {
  return this->x;
}

Fixed const & Point::getY() const {
  return this->y;
}

/* ************************************************************************** */