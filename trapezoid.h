#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <cmath>

class TTrapezoid : public TFigure{
private:
	TPoint a, b, c, d;
public:
	std::string name = "trapezoid ";
	double Square() const override;
	TPoint Center() const override;
	void Print(std::ostream&) const override;
	TTrapezoid();
	TTrapezoid(const TPoint p1, const TPoint p2, const TPoint p3, const TPoint p4);
	TTrapezoid(std::istream& is);
};
#endif