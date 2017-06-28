#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"


class Sphere : public Shape{

public:
//Constructor
Sphere();
Sphere(glm::vec3 const& center, float radius, std::string const& name, Material const& material);

//Destructor
~Sphere();

//getter
glm::vec3 const& getCenter() const;
float getRadius() const;

float area() const override;
float volume() const override;

std::ostream& print(std::ostream& os) const override;

bool intersect(Ray const& ray, float& t) const override;

private:
glm::vec3 center_;
float radius_;

};
#endif //SPHERE_HPP