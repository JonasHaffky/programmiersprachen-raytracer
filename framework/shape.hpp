#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include "ray.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>
#include <string>

class Shape{

public:
//Constructor
Shape();
Shape(std::string const& name, Color const& color);

//Destructor
virtual ~Shape();

//pure virtual: muss man überschreiben
virtual float area() const = 0;
virtual float volume() const = 0;

//non-virtual: nicht überschreiben
//getter
std::string getName() const;
Color getColor() const;

//virtual: kann man überschreiben
virtual std::ostream& print(std::ostream& os) const;

bool intersect (Ray const& ray, float& t ) = 0;

protected:
//protected, damit die abgeleiteten Klassen darauf zugreifen können
std::string name_;
Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif //SHAPE_HPP