#ifndef BUW_CONE_HPP
#define BUW_CONE_HPP
#include "shape.hpp"
#include "ray.hpp"
#include <algorithm>
#include <cmath>
 
/* * Leaf */
class Cone : public Shape {
public:
    Cone();
    Cone(glm::vec3 const& center, double radius, double hight);
    Cone(std::string const& name, Material const& mat, glm::vec3 const& center, double edge, double hight);
    ~Cone() override;
 
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;
    glm::vec3 center() const;
    bool inside(glm::vec3 const& point)const;
    double getSide_hight()const;
 
private:
    glm::vec3 center_;
    double radius_;
    double hight_;
 
};
#endif // BUW_CONE_HPP