#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cassert>
#include <stdexcept> 
#include "point.h"
#include <cmath>



class TFigure {
public:
	virtual void Print(std::ostream&) const = 0;
	virtual TPoint Center() const = 0;
	virtual double Square() const = 0;
	virtual ~TFigure(){};
};
#endif