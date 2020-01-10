#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "figure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"

class Factory {
public:
	std::shared_ptr<TFigure> FigureCreate(std::istream& is) {
		std::string type;
		std::cin >> type;
		if (type == "rectangle") {
			 std::shared_ptr<TFigure> f(new TRectangle(is));
			return f;
		} else if (type == "rhombus") {
			std::shared_ptr<TFigure> f(new TRhombus(is));
			return f;
		} else if (type == "trapezoid") {
			std::shared_ptr<TFigure> f(new TTrapezoid(is));
			return f;
		} else {
			throw std::logic_error("Wrong figure\n");
		}
	}

};