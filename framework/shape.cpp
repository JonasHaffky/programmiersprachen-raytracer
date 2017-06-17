#include <shape.hpp>

Shape::Shape() :
	color_{Color(0, 0, 0)},
	name_ {"default"}
	{}

Shape::Shape(string name) :
	color_{Color(0, 0, 0)},
	name_{ name }
{}

Shape::Shape(string name, Color const& color):
	color_{color},
	name_{name}
	{}

string Shape::getName() const {
	return name_;
}
Color Shape::getColor() const {
	return color_;
}
