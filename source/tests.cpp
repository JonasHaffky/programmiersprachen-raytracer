#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
