#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(): raw_bits(0) {
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed & src) {
	std::cout << "Copy constructor called\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
  std::cout << "Destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &       Fixed::operator=(Fixed const & other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other ) {
    this->raw_bits = other.getRawBits();
  }
  return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void      Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  this->raw_bits = raw;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int       Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return this->raw_bits;
}

/* ************************************************************************** */