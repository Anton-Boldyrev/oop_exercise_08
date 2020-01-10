#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class TRectangle : public TFigure {
private:
	TPoint a, b, c, d;
public:
	void Print(std::ostream& os) const override;
	TPoint Center() const override;
	double Square() const override;
	TRectangle();
	TRectangle(TPoint p1, TPoint p2, TPoint p3, TPoint p4);
	TRectangle(std::istream& is);
};


#endif // RECTANGLE_H


