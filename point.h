#ifndef POINT_H
#define POINT_H

#include <iostream>

struct TPoint
{
	double x, y;
};

std::istream& operator >> (std::istream& is,TPoint& p );
std::ostream& operator << (std::ostream& os,const TPoint& p);

#endif
