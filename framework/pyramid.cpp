#include "pyramid.hpp"

Pyramid::Pyramid():
Shape { "pyramid", {}},
left_corner_{ 0.0f, 0.0f, 0.0f },
edge_{1.0f},
hight_{1.0f}
{}

Pyramid::Pyramid(glm::vec3 const & left_corner, double edge, double hight):
Shape { "pyramid", {}},
left_corner_{ left_corner },
edge_{ edge },
hight_{ hight }
{}

Pyramid::Pyramid(std::string const & name, Material const & mat, glm::vec3 const & left_corner, double edge, double hight):
   Shape{ name , mat },
   left_corner_{ left_corner },
   edge_{ edge },
   hight_{ hight }
{}


Pyramid::~Pyramid() {}

float Pyramid::area() const
{
   return edge_*edge_+(2*edge_*getSide_hight());
}

float Pyramid::volume() const
{
   return (edge_*edge_*hight_)/3;
}

std::ostream & Pyramid::print(std::ostream & os) const
{
   Shape::print(os);
   os << "left corner: (" << left_corner_.x << 
       left_corner_.y << 
       left_corner_.z << ")" << ", "  "\n"
       << "edge length: " << edge_
       << "hight: " << hight_
       << std::endl;
   return os;
}

glm::vec3 Pyramid::getLeft_corner() const
{
   return left_corner_;
}

bool Pyramid::inside(glm::vec3 const & point) const
{
   //TODO
   return false;
}

double Pyramid::getSide_hight() const
{
   return sqrt(pow(hight_,2.0)+pow((edge_/2),2));
}