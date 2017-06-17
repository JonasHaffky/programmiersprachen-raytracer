#define _USE_MATH_DEFINES
#include <sphere.hpp>
#include <cmath>
#include <glm/vec3.hpp>


Sphere::Sphere(): 
	center{glm::vec3{1.0f}},
    radius{1.0f}
{}

Sphere::Sphere(glm::vec3 const& centerP, float rad):
	center {centerP},
	radius {rad} 
	{}

Sphere::Sphere(glm::vec3 const& centerP, float rad, string name) :
	Shape{ name },
	center{ centerP },
	radius{ rad }
{}

Sphere::Sphere(glm::vec3 const& centerP, float rad, string name, Color color) :
	Shape{name, color},
	center {centerP},
	radius {rad}
	{}

float Sphere::area()const {
	return (4 * M_PI*(radius*radius));
}

float Sphere::volume()const {
	float c = 4.0f / 3.0f;
	return (M_PI*(radius*radius*radius)*c);
}

glm::vec3 Sphere::getCenter() const {
	return center;
}

float Sphere::getRadius() const {
	return radius;
}