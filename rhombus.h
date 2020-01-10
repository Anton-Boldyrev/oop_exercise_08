#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <iostream>

class TRhombus : public TFigure{
private:
	TPoint a, b, c, d;
public:
	double Square() const override;
	TPoint Center() const override;
	void Print(std::ostream&) const override;
	TRhombus();
	TRhombus(const TPoint p1, const TPoint p2, const TPoint p3, const TPoint p4);
	TRhombus(std::istream& is);
};


#endif