#include "box.hpp"

// Constructors
Box::Box():
    min_{glm:vec3(-1,-1,-1)},
    min_{glm:vec3(1,1,1)}
{}
Box::Box(float a, float b, float c, float d, float e, float f):
    min_{glm:vec3(a,b,c)},
    min_{glm:vec3(d,e,f)}
{}

// getter
glm::vec3 const& Box::getMin()const{
    return min_;
}
glm::vec3 const& Box::getMax()const{
    return max_;
}

float Box::area() const override{
    float a = max_.x-min.x;
    float b = max_.y-min.y;
    float c = max_.z-min.z;
    return float ar = 2*(a*b+b*c+a*c);
}
float Box::volume() const override{
    float a = max_.x-min.x;
    float b = max_.y-min.y;
    float c = max_.z-min.z;
    return float ar = a*b*c;
}