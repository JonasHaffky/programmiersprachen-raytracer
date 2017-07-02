#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "material.hpp"
#include "SDFloader.hpp"
#include "scene.hpp"

Material rot{"Rot", Color{1.0f,0.0f,0.0f}, Color{1.0f,0.0f,0.0f},Color{1.0f,0.0f,0.0f}, float{0.0f}};
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
  Box box{glm::vec3{3,-6,0}, glm::vec3{8,1,2}, "Test Box", rot};
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
  Sphere sphere{glm::vec3{5,2,-3}, 9.0f, "Test Kugel", rot};
  REQUIRE(sphere.getCenter().x == 5.0f);
  REQUIRE(sphere.getCenter().y == 2.0f);
  REQUIRE(sphere.getCenter().z ==-3.0f);
  REQUIRE(sphere.getRadius() == 9.0f);
  REQUIRE(sphere.getName() == "Test Kugel");
  REQUIRE(sphere.getMaterial().name == "Rot");
  REQUIRE(sphere.getMaterial().ka.r == 1.0f);
  REQUIRE(sphere.getMaterial().ka.g == 0.0f);
  REQUIRE(sphere.getMaterial().ka.b == 0.0f);
  REQUIRE(sphere.getMaterial().ks.r == 1.0f);
  REQUIRE(sphere.getMaterial().ks.g == 0.0f);
  REQUIRE(sphere.getMaterial().ks.b == 0.0f);
  REQUIRE(sphere.getMaterial().kd.r == 1.0f);
  REQUIRE(sphere.getMaterial().kd.g == 0.0f);
  REQUIRE(sphere.getMaterial().kd.b == 0.0f);
  REQUIRE(sphere.getMaterial().m == 0.0f);

}

TEST_CASE("Box Area", "[Box]"){
  Box box{};
  REQUIRE(box.area() == 24);

  Box box2{glm::vec3{-1,-2,0}, glm::vec3{1,1,4}, "Test Box", rot};
  REQUIRE(box2.area() == 52.0f);

}

TEST_CASE("Box Volume", "[Box]"){
  Box box{};
  REQUIRE(box.volume() == 8);

  Box box2{glm::vec3{-2,-4,0}, glm::vec3{2,2,8}, "Test Box", rot};
  REQUIRE(box2.volume() == 192.0f);
}

TEST_CASE("Sphere Area", "[Sphere]"){
  Sphere sphere{};
  REQUIRE(sphere.area() == Approx(12.56637f));

  Sphere sphere2{glm::vec3{-1,2,0}, 5.0f, "Coole Kugel", rot};
  REQUIRE(sphere2.area() == Approx(314.15926f));
}

TEST_CASE("Sphere Volume", "[Sphere]"){
  Sphere sphere{};
  REQUIRE(sphere.volume() == Approx(4.18879f));

  Sphere sphere2{glm::vec3{-1,2,0}, 5.0f, "Test Kugel", rot};
  REQUIRE(sphere2.volume() == Approx(523.59877f));
}

//5.5
TEST_CASE("Print Sphere", "[print]"){
  Sphere sphere2{glm::vec3{-5,2,3}, 4.0f, "Test Kugel", rot};
  std::cout << sphere2;
}

TEST_CASE("Print Box", "[print]"){
  Box box2{glm::vec3{-8,5,0}, glm::vec3{6,8,4}, "Test Box", rot};
  std::cout << box2;
}

//5.6
TEST_CASE("intersectRaySphere", "[intersect]"){
  // Ray
  glm::vec3 ray_origin{0.0 ,0.0 ,0.0};
  // ray direction has to be normalized!
  // you can use:
  // v = glm :: normalize (some_vector)
  glm::vec3 ray_direction{0.0 ,0.0 ,1.0};
  // Sphere
  glm::vec3 sphere_center{0.0 ,0.0 ,5.0};
  float sphere_radius{1.0};
  float distance{0.0};
  auto result = glm::intersectRaySphere(
      ray_origin, ray_direction,
      sphere_center,
      sphere_radius * sphere_radius, // squared radius !!!
      distance);
  REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("Sphere intersect", "[intersect]"){

  glm::vec3 ray_origin{0.0 ,0.0 ,-2.0};
  glm::vec3 ray_direction{0.0 ,0.0 ,2.5};

  glm::vec3 sphere_center{0.0 ,0.0 ,4.0};
  float sphere_radius{1.0};
  float distance{0.0};

  Ray ray{ray_origin, ray_direction};
  Sphere sphere{sphere_center, sphere_radius, "Test Sphere", rot};

  sphere.intersect(ray, distance);
  REQUIRE(distance == Approx(5.0f));

  glm::vec3 ray2_origin{0.0 ,8.0 ,-2.0};
  glm::vec3 ray2_direction{0.0 ,0.0 ,-7.0};

  glm::vec3 sphere2_center{-1.0 ,3.0 ,4.0};
  float sphere2_radius{2.0};
  float distance2{8.0};

  Ray ray2{ray2_origin, ray2_direction};
  Sphere sphere2{sphere2_center, sphere2_radius, "Beautiful Sphere", rot};

  sphere.intersect(ray2, distance2);
  REQUIRE(distance2 == Approx(8.0f));
}

//5.8
TEST_CASE("Destructor 1", "[Destructor]"){
  std::cout << "---------------------------------------\n";
  std::cout<< "Hier beginnt Aufgabe 5.8:" << std::endl;
  std::cout<<"Box Objekt anlegen:" << std::endl;
  Shape* s = new Box;
  std::cout << "Box wieder loeschen:" << std::endl;
  delete s;

  std::cout << "---------------------------------------\n";
  std::cout<<"Sphere Objekt anlegen:" << std::endl;
  Shape* s2 = new Sphere;
  std::cout << "Sphere wieder loeschen:" << std::endl;
  delete s2;
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Destructor 2", "[5.8 Destructor]"){
  std::cout << "---------------------------------------\n";
  std::cout<< "5.8 Test 2:" << std::endl;
  glm::vec3 position{0};
  std::cout<<"Sphere Objekt anlegen:" << std::endl;
  Sphere* s1 = new Sphere{position,1.2,"sphere0",rot};
  std::cout<<"Noch ein Sphere Objekt anlegen:" << std::endl;
  Shape* s2 = new Sphere{position,1.2,"sphere1",rot};
  s1->print(std::cout);
  s2->print(std::cout);
  std::cout << "Sphere 0 wieder loeschen:" << std::endl;
  delete s1;
  std::cout << "Sphere 1 auch wieder loeschen:" << std::endl;
  delete s2;
  std::cout << "---------------------------------------\n";
}
TEST_CASE("Ray intersects Box", "[6.3 intersect]"){

  //Strahl z-Richtung
  glm::vec3 ray_origin{0.0 ,0.0 ,0.0};
  glm::vec3 ray_direction{0.0 ,0.0 ,1.0};
  Ray ray{ray_origin, ray_direction};
  float distance{0.0};

  Box box{glm::vec3{-4,-2,2}, glm::vec3{1,1,1}, "Zu schneidende Box",
          Material{}};
  REQUIRE(box.intersect(ray, distance));
  REQUIRE(distance == 1.0f);

  //Strahl y-Richtung
  glm::vec3 ray_origin2{0.0 ,0.0 ,0.0};
  glm::vec3 ray_direction2{0.0 ,1.0 ,0.0};
  Ray ray2{ray_origin2, ray_direction2};
  float distance2{0.0};

  Box box2{glm::vec3{-2,-2,-4}, glm::vec3{1,1,1}, "Zu schneidende Box",
          Material{}};

  REQUIRE(box2.intersect(ray2, distance2));
  REQUIRE(distance2 == 2);

  //Strahl in x-Richtung
  glm::vec3 ray_origin3{0.0 ,0.0 ,0.0};
  glm::vec3 ray_direction3{1.0 ,0.0 ,0.0};
  Ray ray3{ray_origin3, ray_direction3};
  float distance3{0.0};

  Box box3{glm::vec3{-1,-2,-7}, glm::vec3{2,3,4}, "Zu schneidende Box",
          Material{}};

  auto b = box3.intersect(ray3, distance3);
  std::cout << box3;

  REQUIRE(b);
  REQUIRE(distance3 == 1.0f);
}

TEST_CASE("Ray doesn't intersect Box", "[6.3 intersect]"){
  glm::vec3 ray_origin{0.0 ,0.0 ,0.0};
  glm::vec3 ray_direction{0.0 ,0.0 ,1.0};
  Ray ray{ray_origin, ray_direction};
  float distance{0.0};

  Box box{glm::vec3{-2,7,2}, glm::vec3{2,4,6}, "Nicht zu schneidende Box",
          Material{}};
  REQUIRE(!box.intersect(ray, distance));
}

TEST_CASE("SDFloader Material", "[SDFloader]"){
  std::cout<<"Hier beginnt Aufgabe 6.5:\n";

  SDFloader l{};
  l.loadMaterial("/home/jonashaffky/Dokumente/Studium/Programmiersprachen/Uebung/Uebung5/programmiersprachen-raytracer/doc/material.txt");
}

TEST_CASE("Struct Scene", "[Scene]"){
  std::cout<<"Hier beginnt Aufgabe 6.6:\n";
  
  Scene testSzene{};

  testSzene.loadScene("/home/jonashaffky/Dokumente/Studium/Programmiersprachen/Uebung/Uebung5/programmiersprachen-raytracer/doc/material.txt");
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}