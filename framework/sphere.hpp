#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

# include <glm/vec3.hpp>

class Sphere : public Shape
{
public:
// Constructors
Sphere();
Sphere(float a, float b, float c, float rad);

// getter
glm::vec3 const& getMiddle()const;
float getRadius()const;

float area() const override;
float volume() const override;

private:
glm::vec3 middle_ ;
float radius_;

};

#endif // define BUW_SPHERE_HPP