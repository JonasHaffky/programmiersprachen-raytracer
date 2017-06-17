#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HP

#include <shape.hpp>
#include <glm/vec3.hpp>

class Box : public Shape {
public:

	Box();
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum);
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum, string name);
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum, string name, Color color);

	float area() const;
	float volume()const;

	glm::vec3 getMin() const;
	glm::vec3 getMax() const;

private:
	glm::vec3 min;
	glm::vec3 max;
};
#endif // !BUW_SPHERE_HPP