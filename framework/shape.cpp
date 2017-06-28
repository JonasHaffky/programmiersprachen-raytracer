#include "shape.hpp"

Shape::Shape():
  name_{"Default Shape"},
  material_{}{
	  std::cout << "Default Constructor Base class Shape\n";
	}

Shape::Shape(std::string const& name, Material const& material):
  name_{name},
  material_{material}{
	  std::cout << "Constructor Base class Shape\n";
  }

Shape::~Shape()
  {
    std::cout << "Deconstructor Base class Shape\n";
}

std::string Shape::getName() const{
    return name_;
  }

Material Shape::getMaterial() const{
    return material_;
  }

std::ostream& Shape::print(std::ostream& os) const{
    // << für color gibt es schon in color.hpp
    // Name und color werden in os gepackt
    os << "Name: " << name_ << " \nRGB: " << material_ ;
    return os;
  }

std::ostream& operator<<(std::ostream& os, Shape const& s){
    /*hier wird print aufgerufen, os per Referenz
    wird in print(os) ja verändert*/
    return s.print(os);
}