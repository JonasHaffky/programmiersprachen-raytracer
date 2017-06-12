#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

# include <glm/vec3.hpp>

class Sphere : public Shape
{
public:
virtual int area() const override;
virtual int volume() const override;

private:
 
};

#endif // define BUW_BOX_HPP