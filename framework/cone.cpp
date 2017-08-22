#include "cone.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
 
Cone::Cone():
Shape { "cone", {}},
center_{ 0.0f, 0.0f, 0.0f },
radius_{1.0f},
hight_{1.0f}
{}
 
Cone::Cone(glm::vec3 const & center, double radius, double hight):
Shape { "cone", {}},
center_{ center },
radius_{ radius },
hight_{ hight }
{}
 
Cone::Cone(std::string const & name, Material const & mat, glm::vec3 const & center, double radius, double hight):
    Shape{ name , mat },
    center_{ center },
    radius_{ radius },
    hight_{ hight }
{}
 
 
Cone::~Cone() {}
 
float Cone::area() const
{
    return (M_PI*radius_*radius_)+(M_PI*radius_*getSide_hight());
}
 
float Cone::volume() const
{
    return (M_PI*radius_*radius_*hight_)/3;
}
 
std::ostream & Cone::print(std::ostream & os) const
{
    Shape::print(os);
    os << "center: (" << center_.x << 
        center_.y << 
        center_.z << ")" << ", "  "\n"
        << "radius: " << radius_
        << "hight: " << hight_
        << std::endl;
    return os;
}
 
glm::vec3 Cone::center() const
{
    return center_;
}
 
bool Cone::inside(glm::vec3 const & point) const
{
    //TODO
    return false;
}
 
double Cone::getSide_hight() const
{
    return sqrt(pow(hight_,2.0)+pow(radius_,2.0));
}