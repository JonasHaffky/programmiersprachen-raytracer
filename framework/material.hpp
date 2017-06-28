#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"
#include <iostream>

struct Material{

Material():
    name{},
    ka{0.0f,0.0f,0.0f},
    ks{0.0f,0.0f,0.0f},
    kd{0.0f,0.0f,0.0f},
    m{0.0f}
    {}

Material(std::string const& name, Color const& ka, Color const& ks, Color const& kd, float m):
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
float m;

};
#endif //RAY_HPP