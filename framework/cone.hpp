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
    Cone(glm::vec3 const& center, double cradius, double cheight);
    Cone(std::string const& name, Material const& mat, glm::vec3 const& center, double cradius, double cheight);
    ~Cone() override;
 
    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;
    glm::vec3 center() const;
    bool inside(glm::vec3 const& point)const;
    double getSide_hight()const;
 
private:
    glm::vec3 ccenter_;
    double cradius_;
    double cheight_;
 
};
#endif // BUW_CONE_HPP