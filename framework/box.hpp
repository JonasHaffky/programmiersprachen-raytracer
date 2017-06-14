#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

# include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape
{
public:
// Constructors
Box();
Box(float a, float b, float c, float d, float e, float f);

// getter
glm::vec3 getMin()const;
glm::vec3 getMax()const;

float area() const override;
float volume() const override;

private:
glm::vec3 min_ ;
glm::vec3 max_ ;

};

#endif // define BUW_BOX_HPP