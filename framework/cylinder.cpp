#include "cylinder.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
 
Cylinder::Cylinder():
Shape { "cylinder", {}},
bottom_center_{ 0.0f, 0.0f, 0.0f },
radius_{1.0f},
height_{1.0f}
{}
 
Cylinder::Cylinder(glm::vec3 const & bottom_center, double radius, double height):
Shape { "cylinder", {}},
bottom_center_{ bottom_center },
radius_{ radius },
height_{ height }
{}
 
Cylinder::Cylinder(std::string const & name, Material const & mat, glm::vec3 const & bottom_center, double radius, double height):
    Shape{ name , mat },
    bottom_center_{ bottom_center },
    radius_{ radius },
    height_{ height }
{}
 
 
Cylinder::~Cylinder() {}
 
float Cylinder::area() const 
{
    return (2*M_PI*radius_*(radius_*height_));
}
 
float Cylinder::volume() const 
{
    return (M_PI*radius_*radius_*height_);
}
 
std::ostream & Cylinder::print(std::ostream & os) const 
{
    Shape::print(os);
    os << "bottom_center: (" << bottom_center_.x << 
        bottom_center_.y << 
        bottom_center_.z << ")" << ", "  "\n"
        << "radius: " << radius_
        << "hight: " << height_
        << std::endl;
    return os;
}
 
glm::vec3 Cylinder::getBottom_center() const
{
    return bottom_center_;
}
 
bool Cylinder::inside(glm::vec3 const & point) const
{
    bool result = false;
    if (pow((point.x - bottom_center_.x), 2) + pow((point.y - bottom_center_.y), 2) <= radius_*radius_) {
        if (bottom_center_.z + height_ >= bottom_center_.z + point.z) { result = true; }
    }
    return result;
}