#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Point ab = Point(a.getX() - b.getX(), a.getY() - b.getY());
  Point ap = Point(a.getX() - point.getX(), a.getY() - point.getY());
  Point bc = Point(b.getX() - c.getX(), b.getY() - c.getY());
  Point bp = Point(b.getX() - point.getX(), b.getY() - point.getY());
  Point ca = Point(c.getX() - a.getX(), c.getY() - a.getY());
  Point cp = Point(c.getX() - point.getX(), c.getY() - point.getY());

  Fixed ab_x_ap = ab.getX() * ap.getY() - ab.getY() * ap.getX();
  Fixed bc_x_bp = bc.getX() * bp.getY() - bc.getY() * bp.getX();
  Fixed ca_x_cp = ca.getX() * cp.getY() - ca.getY() * cp.getX();

  if ((ab_x_ap > 0 && bc_x_bp > 0 && ca_x_cp > 0)
      || (ab_x_ap < 0 && bc_x_bp < 0 && ca_x_cp < 0)) {
    return true;
  }
  else {
    return false;
  }
}
