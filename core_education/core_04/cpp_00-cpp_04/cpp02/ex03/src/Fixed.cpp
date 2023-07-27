#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(): raw_bits(0) {
  if (TO_PRINT == true)
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int val) {
  if (TO_PRINT == true)
    std::cout << "Int constructor called\n";
  this->raw_bits = val << 8;
}

Fixed::Fixed(const float val) {
  if (TO_PRINT == true)
    std::cout << "Float constructor called\n";
  this->raw_bits = roundf(val * (1 << this->kNFractionalBits));
}

Fixed::Fixed(const Fixed & src) {
  if (TO_PRINT == true)
    std::cout << "Copy constructor called\n";
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
  if (TO_PRINT == true)
    std::cout << "Destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &         Fixed::operator=(Fixed const & other) {
  if (TO_PRINT == true)
    std::cout << "Copy assignment operator called\n";
  if (this != &other ) {
    this->raw_bits = other.getRawBits();
  }
  return *this;
}

std::ostream &  operator<<(std::ostream &os, const Fixed & other) {
  os << other.toFloat();
  return os;
}

bool            Fixed::operator>(Fixed const & other) const {
  return this->raw_bits > other.getRawBits();
}

bool            Fixed::operator<(Fixed const & other) const {
  return this->raw_bits < other.getRawBits();
}

bool            Fixed::operator>=(Fixed const & other) const {
  return this->raw_bits >= other.getRawBits();
}

bool            Fixed::operator<=(Fixed const & other) const {
  return this->raw_bits <= other.getRawBits();
}

bool            Fixed::operator==(Fixed const & other) const {
  return this->raw_bits == other.getRawBits();
}

bool            Fixed::operator!=(Fixed const & other) const {
  return this->raw_bits != other.getRawBits();
}

Fixed           Fixed::operator+(Fixed const & other) const {
  Fixed to_return;
  to_return.setRawBits(this->getRawBits() + other.getRawBits());
  return to_return;
}

Fixed           Fixed::operator-(Fixed const & other) const {
  Fixed to_return;
  to_return.setRawBits(this->getRawBits() - other.getRawBits());
  return to_return;
}

Fixed           Fixed::operator*(Fixed const & other) const {
  long long  a = this->getRawBits();
  long long  b = other.getRawBits();
  long long  c = (a * b) >> this->kNFractionalBits;
  Fixed   to_return;
  to_return.setRawBits(int(c));
  return to_return;
}

Fixed           Fixed::operator/(Fixed const & other) const {
  long long  a = this->getRawBits();
  long long  b = other.getRawBits();
  long long  c = (a << this->kNFractionalBits) / b;
  Fixed   to_return;
  to_return.setRawBits(int(c));
  return to_return;
}

Fixed &         Fixed::operator++() {
  this->raw_bits++;
  return *this;
}
Fixed           Fixed::operator++(int) {
  Fixed tmp(*this);
  ++(*this);
  return tmp;
}


Fixed &         Fixed::operator--() {
  this->raw_bits--;
  return *this;
}
Fixed           Fixed::operator--(int) {
  Fixed tmp(*this);
  --(*this);
  return tmp;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void      Fixed::setRawBits(int const raw) {
  if (TO_PRINT == true)
    std::cout << "setRawBits member function called\n";
  this->raw_bits = raw;
}

float     Fixed::toFloat(void) const {
  return float(this->raw_bits) / (1 << this->kNFractionalBits);
}

int       Fixed::toInt(void) const {
  return this->raw_bits >> this->kNFractionalBits;
}

Fixed const &Fixed::max(const Fixed & a, const Fixed & b) {
  return (a > b ? a : b);
}

Fixed const &Fixed::min(const Fixed & a, const Fixed & b) {
  return (a < b ? a : b);
}
Fixed &Fixed::max(Fixed & a, Fixed & b) {
  return (a > b ? a : b);
}
Fixed &Fixed::min(Fixed & a, Fixed & b) {
  return (a < b ? a : b);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int       Fixed::getRawBits(void) const {
  if (TO_PRINT == true)
    std::cout << "getRawBits member function called\n";
  return this->raw_bits;
}

/* ************************************************************************** */