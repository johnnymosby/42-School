#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(): raw_bits(0) {
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int val) {
  std::cout << "Int constructor called\n";
  this->raw_bits = val << 8;
}

Fixed::Fixed(const float val) {
  std::cout << "Float constructor called\n";
  this->raw_bits = roundf(val * (1 << this->kNFractionalBits));
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

Fixed &       Fixed::operator=(Fixed const & rhs) {
  std::cout << "Copy assignment operator called\n";
  if (this != &rhs ) {
    this->raw_bits = rhs.getRawBits();
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed & rhs) {
  os << rhs.toFloat();
  return os;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void      Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  this->raw_bits = raw;
}

float     Fixed::toFloat(void) const {
  return float(this->raw_bits) / (1 << this->kNFractionalBits);
}

int       Fixed::toInt(void) const {
  return this->raw_bits >> this->kNFractionalBits;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int       Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return this->raw_bits;
}

/* ************************************************************************** */