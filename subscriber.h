#pragma once


#include "figure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
#include <vector>
#include <memory>


class  sub {
public:
	virtual void Print(std::vector<std::shared_ptr<TFigure>>& v) = 0;

};