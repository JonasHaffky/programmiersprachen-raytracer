#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

//5.2 bzw. 5.3
//Konstruktoren Tests, implizieren getter
TEST_CASE("Box Default Constructor", "[Box]"){
  Box box{};
  REQUIRE(box.getMin().x == -1);
  REQUIRE(box.getMin().y == -1);
  REQUIRE(box.getMin().z == -1);
  REQUIRE(box.getMax().x == 1);
  REQUIRE(box.getMax().y == 1);
  REQUIRE(box.getMax().z == 1);
  REQUIRE(box.getName() == "Default Shape");
}


TEST_CASE("Box Constructor", "[Box]"){
  Box box{glm::vec3{3,-6,0}, glm::vec3{8,1,2}, "Test Box", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE(box.getMin().x == 3);
  REQUIRE(box.getMin().y == -6);
  REQUIRE(box.getMin().z == -0);
  REQUIRE(box.getMax().x == 8);
  REQUIRE(box.getMax().y == 1);
  REQUIRE(box.getMax().z == 2);
  REQUIRE(box.getName() == "Test Box");
}

TEST_CASE("Sphere Default Constructor", "[Sphere]"){
  Sphere sphere{};
  REQUIRE(sphere.getCenter().x == 0.0f);
  REQUIRE(sphere.getCenter().y == 0.0f);
  REQUIRE(sphere.getCenter().z == 0.0f);
  REQUIRE(sphere.getRadius() == 1.0f);
  REQUIRE(sphere.getName() == "Default Shape");
}

TEST_CASE("Sphere Constructor", "[Sphere]"){
  Sphere sphere{glm::vec3{5,2,-3}, 9.0f, "Test Kugel", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE(sphere.getCenter().x == 5.0f);
  REQUIRE(sphere.getCenter().y == 2.0f);
  REQUIRE(sphere.getCenter().z ==-3.0f);
  REQUIRE(sphere.getRadius() == 9.0f);
  REQUIRE(sphere.getName() == "Test Kugel");
  REQUIRE(sphere.getColor().r == 1.0f);
  REQUIRE(sphere.getColor().g == 1.0f);
  REQUIRE(sphere.getColor().b == 1.0f);

}

TEST_CASE("Box Area", "[Box]"){
  Box box{};
  REQUIRE(box.area() == 24);

  Box box2{glm::vec3{-1,-2,0}, glm::vec3{1,1,4}, "Test Box", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE(box2.area() == 52.0f);

}

TEST_CASE("Box Volume", "[Box]"){
  Box box{};
  REQUIRE(box.volume() == 8);

  Box box2{glm::vec3{-2,-4,0}, glm::vec3{2,2,8}, "Test Box", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE(box2.volume() == 192.0f);
}

TEST_CASE("Sphere Area", "[Sphere]"){
  Sphere sphere{};
  REQUIRE(sphere.area() == Approx(12.56637f));

  Sphere sphere2{glm::vec3{-1,2,0}, 5.0f, "Coole Kugel", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE(sphere2.area() == Approx(314.15926f));
}

TEST_CASE("Sphere Volume", "[Sphere]"){
  Sphere sphere{};
  REQUIRE(sphere.volume() == Approx(4.18879f));

  Sphere sphere2{glm::vec3{-1,2,0}, 5.0f, "Test Kugel", Color{1.0f, 1.0f, 1.0f}};
  REQUIRE(sphere2.volume() == Approx(523.59877f));
}

//5.5
TEST_CASE("Print Sphere", "[print]"){
  Sphere sphere2{glm::vec3{-5,2,3}, 4.0f, "Test Kugel", Color{1.0f, 1.0f, 1.0f}};
  std::cout << sphere2;
}

TEST_CASE("Print Box", "[print]"){
  Box box2{glm::vec3{-8,5,0}, glm::vec3{6,8,4}, "Test Box", Color{1.0f, 1.0f, 1.0f}};
  std::cout << box2;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}