#include "point.h"

std::istream& operator >> (std::istream& is, TPoint& p) {
	return is >> p.x >> p.y;
}

std::ostream& operator << (std::ostream& os, const TPoint& p) {
	return os << p.x << " " << p.y;
}