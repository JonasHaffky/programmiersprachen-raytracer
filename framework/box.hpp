#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HP

#include <shape.hpp>
#include <glm/vec3.hpp>

class Box : public Shape {
public:

	Box();
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum);
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum, std::string const& name);
	Box(glm::vec3 const& minimum, glm::vec3 const& maximum, std::string const& name, Color const& color);

	~Box();

	float area() const;
	float volume() const;

	glm::vec3 const& getMin() const;
	glm::vec3 const& getMax() const;

	std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
};
#endif // !BUW_SPHERE_HPP