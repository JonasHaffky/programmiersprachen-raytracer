#ifndef BUW_PYRAMID_HPP
#define BUW_PYRAMID_HPP
#include "shape.hpp"
#include "ray.hpp"
#include <algorithm>
#include <cmath>
 
/* * Leaf */
class Pyramid : public Shape {
public:
    Pyramid();
    Pyramid(glm::vec3 const& left_corner, double edge, double hight);
    Pyramid(std::string const& name, Material const& mat, glm::vec3 const& left_corner, double edge, double hight);
    ~Pyramid() override;
 
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;
    glm::vec3 getLeft_corner() const;
    bool inside(glm::vec3 const& point)const;
    double getSide_hight()const;
 
private:
    glm::vec3 left_corner_;
    double edge_;
    double hight_;
 
};
#endif // BUW_PYRAMID_HPP