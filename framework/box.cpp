#include "box.hpp"
#include <cmath>

// Constructors
Box::Box():
    min_{glm::vec3(-1,-1,-1)},
    max_{glm::vec3(1,1,1)}
{}
Box::Box(float a, float b, float c, float d, float e, float f):
    min_{glm::vec3(a,b,c)},
    max_{glm::vec3(d,e,f)}
{}

// getter
glm::vec3 Box::getMin()const{
    return min_;
}
glm::vec3 Box::getMax()const{
    return max_;
}

float Box::area() const {
    float a = max_.x-min_.x;
    float b = max_.y-min_.y;
    float c = max_.z-min_.z;
    return fabs(2*(a*b+b*c+a*c));
}
float Box::volume() const {
    float a = max_.x-min_.x;
    float b = max_.y-min_.y;
    float c = max_.z-min_.z;
    return a*b*c;
}