#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

int main(void) {

  Point a1(2.0f, 2.0f), b1(4.0f, 5.0f), c1(7.0f, 3.0f);
  Point p1(2.0f, 2.0f), p2(1.0f, 2.0f), p3(4.0f, 4.0f);

  std::cout << "Quadrant 3\n";
  std::cout << bsp(a1, b1, c1, p1) << "\n";
  std::cout << bsp(a1, b1, c1, p2) << "\n";
  std::cout << bsp(a1, b1, c1, p3) << "\n";


  Point a2(-2.0f, 2.0f), b2(-4.0f, 5.0f), c2(-7.0f, 3.0f);
  Point p4(-2.0f, 2.0f), p5(-1.0f, 2.0f), p6(-4.0f, 4.0f);

  std::cout << "Quadrant 2\n";
  std::cout << bsp(a2, b2, c2, p4) << "\n";
  std::cout << bsp(a2, b2, c2, p5) << "\n";
  std::cout << bsp(a2, b2, c2, p6) << "\n";


  Point a3(-2.0f, -2.0f), b3(-4.0f, -5.0f), c3(-7.0f, -3.0f);
  Point p7(-2.0f, -2.0f), p8(-1.0f, -2.0f), p9(-4.0f, -4.0f);

  std::cout << "Quadrant 3\n";
  std::cout << bsp(a3, b3, c3, p7) << "\n";
  std::cout << bsp(a3, b3, c3, p8) << "\n";
  std::cout << bsp(a3, b3, c3, p9) << "\n";


  Point a4(2.0f, -2.0f), b4(4.0f, -5.0f), c4(7.0f, -3.0f);
  Point p10(2.0f, -2.0f), p11(1.0f, -2.0f), p12(4.0f, -4.0f);

  std::cout << "Quadrant 4\n";
  std::cout << bsp(a4, b4, c4, p10) << "\n";
  std::cout << bsp(a4, b4, c4, p11) << "\n";
  std::cout << bsp(a4, b4, c4, p12) << "\n";

  Point a5(1.0f, 1.0f), b5(1.0f, 3.0f), c5(3.0f, 1.0f);
  Point p13(1.0f, 2.0f), p14(2.0f, 1.0f), p15(2.0f, 3.0f);

  std::cout << "Checking edges\n";
  std::cout << bsp(a5, b5, c5, p13) << "\n";
  std::cout << bsp(a5, b5, c5, p14) << "\n";
  std::cout << bsp(a5, b5, c5, p15) << "\n";


  return 0;
}
