#include "sphere.hpp"
#include <cmath>

// Constructors
Sphere::Sphere():
    middle_{glm::vec3(1,1,1)},
    radius_{1}
{}
Sphere::Sphere(float a, float b, float c, float rad):
    middle_{glm::vec3(a,b,c)},
    radius_{rad}
{}

// getter
glm::vec3 Sphere::getMiddle()const{
    return middle_;
}
float Sphere::getRadius()const{
    return radius_;
}

float Sphere::area() const {
    return 4*M_PI*radius_*radius_;
}
float Sphere::volume() const {
    return 4/3*M_PI*pow(radius_,3);
}