#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"
#include <iostream>

struct Material{

Material():
    name{},
    ka{},
    ks{},
    kd{},
    m{}
    {}

Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float& m):
    name{name},
    ka{ka},
    ks{ks},
    kd{kd},
    m{m}
    {}

friend std::ostream& operator<<(std::ostream& os, Material const& ma)
  {
    os << "(" << ma.name << "," << ma.ka << "," << ma.ks << "," << ma.kd << "," << ma.m << ")\n";
    return os;
  }

std::string name;
Color ka;
Color kd;
Color ks;
float m

};
#endif //RAY_HPP