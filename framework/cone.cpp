#include "cone.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
 
Cone::Cone():
Shape { "cone", {}},
ccenter_{ 0.0f, 0.0f, 0.0f },
cradius_{1.0f},
cheight_{1.0f}
{}
 
Cone::Cone(glm::vec3 const & ccenter, double cradius, double cheight):
Shape { "cone", {}},
ccenter_{ ccenter },
cradius_{ cradius },
cheight_{ cheight }
{}
 
Cone::Cone(std::string const & name, Material const & mat, glm::vec3 const & ccenter, double cradius, double cheight):
    Shape{ name , mat },
    ccenter_{ ccenter },
    cradius_{ cradius },
    cheight_{ cheight }
{}
 
 
Cone::~Cone() {}
 
float Cone::area() const
{
    return (M_PI*cradius_*cradius_)+(M_PI*cradius_*getSide_hight());
}
 
float Cone::volume() const
{
    return (M_PI*cradius_*cradius_*cheight_)/3;
}
 
std::ostream & Cone::print(std::ostream & os) const
{
    Shape::print(os);
    os << "center: (" << ccenter_.x << 
        ccenter_.y << 
        ccenter_.z << ")" << ", "  "\n"
        << "radius: " << cradius_
        << "hight: " << cheight_
        << std::endl;
    return os;
}
 
glm::vec3 Cone::center() const
{
    return ccenter_;
}
 
bool Cone::inside(glm::vec3 const & point) const
{
    //TODO
    return false;
}
 
double Cone::getSide_hight() const
{
    return sqrt(pow(cheight_,2.0)+pow(cradius_,2.0));
}