#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  // Fixed a;
  // Fixed const b(Fixed(5.05f) * Fixed(2));
  // Fixed c(6.5f);

  // std::cout << (c > a) << std::endl;
  // std::cout << (c < a) << std::endl;
  // std::cout << "a == " << a << std::endl;
  // std::cout << "b == " << a << std::endl;
  // std::cout << "c == " << c << std::endl;
  // std::cout << "a + c = " << a + c << std::endl;
  // std::cout << "a - c = " << a - c << std::endl;
  // std::cout << "a * c = " << c * Fixed(1.5f) << std::endl;
  // std::cout << "a / c = " << c / Fixed(1.5f) << std::endl;
  // std::cout << "1.0f / 3.0f = " << Fixed(1.0f) / Fixed(3.0f) << std::endl;
  // std::cout << "a: " << a << std::endl;
  // std::cout << "a++: " << a++ << std::endl;
  // std::cout << "a: " << a << std::endl;
  // std::cout << "++a: " << ++a << std::endl;
  // std::cout << "a: " << a << std::endl;
  // std::cout << "c: " << c << std::endl;
  // std::cout << "c++: " << c++ << std::endl;
  // std::cout << "c: " << c << std::endl;
  // std::cout << "++c: " << ++c << std::endl;
  // std::cout << "c: " << c << std::endl;
  // std::cout << "b: " << b << std::endl;
  // std::cout << "max(a, b):" << Fixed::max( a, b ) << std::endl;
  // std::cout << "min(a, b):" << Fixed::min( a, b ) << std::endl;
  return 0;
}
