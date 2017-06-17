#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"
using namespace std;

class Shape {
public:

	Shape();
	Shape(string name);
	Shape(string name, Color const& color);

	virtual float area() = 0;
	virtual float volume() = 0;

	string getName() const;
	Color getColor() const;

protected:
	string name_;
	Color color_;
};

#endif