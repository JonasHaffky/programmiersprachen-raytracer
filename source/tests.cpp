#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.cpp"
#include "sphere.cpp"
#include "box.cpp"

//5.2
TEST_CASE("box constructor and getter","[box]")
{ Box a{};
  Box b{{4.2f},{2.1f},{6.2f},{3.1f},{4.2f},{5.1f}};
  REQUIRE(a.getMin().x==-1.0f);
  REQUIRE(a.getMin().y==-1.0f);
  REQUIRE(a.getMin().z==-1.0f);
  REQUIRE(a.getMax().x==1.0f);
  REQUIRE(a.getMax().y==1.0f);
  REQUIRE(a.getMax().z==1.0f);
  REQUIRE(b.getMin().x==4.2f);
  REQUIRE(b.getMin().y==2.1f);
  REQUIRE(b.getMin().z==6.2f);
  REQUIRE(b.getMax().x==3.1f);
  REQUIRE(b.getMax().y==4.2f);
  REQUIRE(b.getMax().z==5.1f);
}

TEST_CASE("box area and volume","[box]")
{ Box a{};
  Box b{{4.2f},{2.1f},{6.2f},{3.1f},{4.2f},{5.1f}};
  REQUIRE(a.area()==24.0f);
  REQUIRE(a.volume()==8.0f);
  REQUIRE(b.area()==Approx(6.82f).epsilon(0.001));
  REQUIRE(a.volume()==8.0f);
}

TEST_CASE("sphere constructor and getter","[sphere]")
{ Sphere a{};
  Sphere b{{4.2f},{2.1f},{6.2f},{3.1f}};
  REQUIRE(a.getMiddle().x==1.0f);
  REQUIRE(a.getMiddle().y==1.0f);
  REQUIRE(a.getMiddle().z==1.0f);
  REQUIRE(a.getRadius()==1.0f);
  REQUIRE(b.getMiddle().x==4.2f);
  REQUIRE(b.getMiddle().y==2.1f);
  REQUIRE(b.getMiddle().z==6.2f);
  REQUIRE(b.getRadius()==3.1f);
}

TEST_CASE("sphere area and volume","[sphere]")
{ Sphere a{};
  Sphere b{{4.2f},{2.1f},{6.2f},{3.1f}};
  REQUIRE(a.area()==Approx(12.566f).epsilon(0.001));
  REQUIRE(a.volume()==Approx(3.14f).epsilon(0.001));
  REQUIRE(b.area()==Approx(120.76f).epsilon(0.001));
  REQUIRE(a.volume()==Approx(3.14f).epsilon(0.001));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
