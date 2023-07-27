#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>

#include "Fixed.hpp"

class Point
{

  public:

    Point();
    Point(const float first, const float second);
    Point(Fixed first, Fixed second);
    Point( Point const & src );
    ~Point();

    Point &   operator=( Point const & rhs );
    Fixed const & getX() const;
    Fixed const & getY() const;

  private:
    Fixed x;
    Fixed y;

};

std::ostream &      operator<<(std::ostream & os, Point const & i);

#endif /* *********************************************************** POINT_H */