#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <glm/vec3.hpp>
using namespace std;

glm::vec3 vectorA(1.5f, 2.3f, 3.4f);

//
// 5.2 Tests
TEST_CASE("Spheres and Boxes", "[constructors]") {
	Sphere sp{};
	Sphere sp2{vectorA, 5.6f};
	
	REQUIRE(sp.getRadius() == 0);
	REQUIRE(sp2.getCenter().x == Approx(1.5f));
	REQUIRE(sp2.area() == Approx(394.08f));
	REQUIRE(sp2.volume() == Approx(735.62f));

	Box bx{};
	Box bx2{vectorA, { {2.5f}, {3.3f}, {4.4f} }};

	REQUIRE(bx.getMax().x == 0);
	REQUIRE(bx2.getMin().y == Approx(2.3f));
	REQUIRE(bx2.area() == Approx(6.0f));
	REQUIRE(bx2.volume() == Approx(1.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}