#include <box.hpp>
#include <glm/vec3.hpp>

Box::Box() {
	min{glm::vec3{-1.0f,-1.0f,-1.0f}},
    max{glm::vec3{1.0f,1.0f,1.0f}}
}

Box::Box(glm::vec3 const& minimum, glm::vec3 const& maximum):
	min{minimum},
	max{maximum}
	{}

Box::Box(glm::vec3 const& minimum, glm::vec3 const& maximum, string name) :
	Shape{name},
	min{minimum},
	max{maximum}
{}


Box::Box(glm::vec3 const& minimum, glm::vec3 const& maximum, string name, Color color) :
	Shape{name, color},
	min{minimum},
	max{maximum}
	{}

float Box::area()const {
	float x = max.x - min.x;
	float y = max.y - min.y;
	float z = max.z - min.z;
	return (2 * x*z) + (2 * y*z) + (2 * x*y);
}

float Box :: volume()const {
	float x = max.x - min.x;
	float y = max.y - min.y;
	float z = max.z - min.z;
	
	return x*y*z;
}

glm::vec3 Box::getMin() const {
	return min;
}

glm::vec3 Box::getMax() const {
	return max;
}