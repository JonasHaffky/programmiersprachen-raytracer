#ifndef BUW_CYLINDER_HPP
#define BUW_CYLINDER_HPP
#include "shape.hpp"
#include "ray.hpp"
#include <algorithm>
#include <cmath>
 
/* * Leaf */
class Cylinder : public Shape {
public:
    Cylinder();
    Cylinder(glm::vec3 const& bottom_center, double radius, double height);
    Cylinder(std::string const& name, Material const& mat, glm::vec3 const& bottom_center,double radius, double height);
    ~Cylinder() override;
 
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;
    glm::vec3 getBottom_center() const;
    bool inside(glm::vec3 const& point)const;
 
private:
    glm::vec3 bottom_center_;
    double radius_;
    double height_;
 
};
#endif // BUW_CYLINDER_HPP