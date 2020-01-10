#include "rhombus.h"

TRhombus::TRhombus (const TPoint p1, const TPoint p2, const TPoint p3, const TPoint p4) {
	a = p1;
	b = p2;
	c = p3;
	d = p4;
	TPoint ab, bc, cd, da;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	bc.x = c.x - b.x;
	bc.y = c.y - b.y;
	cd.x = d.x - c.x;
	cd.y = d.y - c.y;
	da.x = a.x - d.x;
	da.y = a.y - d.y;
	if (sqrt(ab.x * ab.x + ab.y * ab.y) !=  sqrt(bc.x * bc.x + bc.y * bc.y) || sqrt(bc.x * bc.x + bc.y * bc.y) != sqrt(cd.x * cd.x + cd.y * cd.y) || sqrt(cd.x * cd.x + cd.y * cd.y) != sqrt(da.x * da.x + da.y * da.y)) {
		throw std::logic_error("it's not rhombus\n");
	}
	//assert(sqrt(ab.x * ab.x + ab.y * ab.y) ==  sqrt(bc.x * bc.x + bc.y * bc.y) && sqrt(bc.x * bc.x + bc.y * bc.y) == sqrt(cd.x * cd.x + cd.y * cd.y) && sqrt(cd.x * cd.x + cd.y * cd.y) == sqrt(da.x * da.x + da.y * da.y));

}

TRhombus::TRhombus(std::istream& is) {
	is >> a >> b >> c >> d;
	TPoint ab, bc, cd, da;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	bc.x = c.x - b.x;
	bc.y = c.y - b.y;
	cd.x = d.x - c.x;
	cd.y = d.y - c.y;
	da.x = a.x - d.x;
	da.y = a.y - d.y;
	if (sqrt(ab.x * ab.x + ab.y * ab.y) !=  sqrt(bc.x * bc.x + bc.y * bc.y) || sqrt(bc.x * bc.x + bc.y * bc.y) != sqrt(cd.x * cd.x + cd.y * cd.y) || sqrt(cd.x * cd.x + cd.y * cd.y) != sqrt(da.x * da.x + da.y * da.y)) {
		throw std::logic_error("it's not rhombus\n");
	}
}

double TRhombus::Square() const {
	double ans = 0.5 * sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2)) * sqrt(pow(b.x - d.x, 2) + pow(b.y - d.y, 2));
	return fabs(ans);
}

TPoint TRhombus::Center() const {
	TPoint p;
	double x = (a.x + b.x + c.x + d.x) / 4;
	double y = (a.y + b.y + c.y + d.y) / 4;
	p.x = x;
	p.y = y;
	return p;
}

void TRhombus::Print(std::ostream& os) const {
	os << a << " " << b << " " << c << " " << d << "\n";
}

