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
    Point( Point const & src );
    ~Point();

    Point &   operator=( Point const & rhs );

  private:
    Fixed x;
    Fixed y;

};

std::ostream &      operator<<( std::ostream & o, Point const & i );

#endif /* *********************************************************** POINT_H */