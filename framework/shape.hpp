#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>
#include <string>

class Shape{

public:
//Constructor
Shape();
Shape(std::string const& name, Color const& color);

//pure virtual: muss man überschreiben
virtual float area() const = 0;
virtual float volume() const = 0;

//non-virtual: nicht überschreiben
//getter
std::string getName() const;
Color getColor() const;

//virtual: kann man überschreiben
virtual std::ostream& print(std::ostream& os) const;

protected:
//protected, damit die abgeleiteten Klassen darauf zugreifen können
std::string name_;
Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif //SHAPE_HPP