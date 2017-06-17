#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HP

#include <shape.hpp>
#include <glm/vec3.hpp>

class Sphere : public Shape {
public:

	Sphere();
	Sphere(glm::vec3 const& center, float radius);
	Sphere(glm::vec3 const& center, float radius, string name);
	Sphere(glm::vec3 const& center, float radius, string name, Color color);

	float area()const;
	float volume()const;

	glm::vec3 getCenter() const;
	float getRadius() const;

private:
	glm::vec3 center;
	float radius;
};
#endif // !BUW_SPHERE_HPP