// main.cpp (Programmiersprachen Aufgabenblatt 5)

#define CATCH_CONFIG_RUNNER
#define GLM_FORCE_RADIANS
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "camera.hpp"
#include "lightsource.hpp"
#include "scene.hpp"
#include "glm/gtc/matrix_transform.hpp"

/* ------------------ Aufgabe 5.2 ------------------ */

TEST_CASE("Sphere: gets member ctr_ (center)", "[aufgabe5.2]") {
  Sphere s1 {}; // default constructor test
  REQUIRE(0.0f == s1.center().x);
  REQUIRE(0.0f == s1.center().y);
  REQUIRE(0.0f == s1.center().z);

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(0.4f == s2.center().x);
  REQUIRE(2.3f == s2.center().y);
  REQUIRE(1.2f == s2.center().z);

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  REQUIRE(6.9f == s3.center().x);
  REQUIRE(4.2f == s3.center().y);
  REQUIRE(-1.2f == s3.center().z);
}

TEST_CASE("Sphere: gets member rad_ (radius)", "[aufgabe5.2]") {
  Sphere s1 {}; // default constructor test
  REQUIRE(0.0f == s1.radius());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  REQUIRE(-4.3f == s2.radius());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  REQUIRE(4.3f == s3.radius());
}

TEST_CASE("Sphere: sets member ctr_ (center)", "[aufgabe5.2]") {
  Sphere s1 {}; 
  s1.center({1.0f, 1.0f, 1.0f});
  REQUIRE(1.0f == s1.center().x);
  REQUIRE(1.0f == s1.center().y);
  REQUIRE(1.0f == s1.center().z);

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  s2.center({3.4f, 4.2f, -1.0f});
  REQUIRE(3.4f == s2.center().x);
  REQUIRE(4.2f == s2.center().y);
  REQUIRE(-1.0f == s2.center().z);

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  s3.center({9.1f, -6.9f, -10.2f});
  REQUIRE(9.1f == s3.center().x);
  REQUIRE(-6.9f == s3.center().y);
  REQUIRE(-10.2f == s3.center().z);
}

TEST_CASE("Sphere: sets member rad_ (radius)", "[aufgabe5.2]") {
  Sphere s1 {}; 
  s1.radius(4.2f);
  REQUIRE(4.2f == s1.radius());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  s2.radius(-6.29f);
  REQUIRE(-6.29f == s2.radius());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  s3.radius(2.811f);
  REQUIRE(2.811f == s3.radius());
}

TEST_CASE("Sphere: gets area of sphere object", "[aufgabe5.2]") {
  Sphere s1 {};
  REQUIRE(0.0f == s1.area());
  
  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(Approx(232.3522f) == s2.area());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(Approx(598.2849f) == s3.area());

  Sphere s4 {{6.9f, 4.2f, -1.2f}, 1.25f};
  REQUIRE(Approx(19.635f) == s4.area());

  auto s5 = std::make_shared<Sphere>(Sphere{{6.9f, 4.2f, -1.2f}, 1.25f});
  std::shared_ptr<Shape> shape = s5;
  REQUIRE(Approx(19.635f) == shape -> area());
}

TEST_CASE("Sphere: gets volume of sphere object", "[aufgabe5.2]") {
  Sphere s1 {};
  REQUIRE(0.0f == s1.volume());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(Approx(333.0381f) == s2.volume());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(Approx(1376.0553f) == s3.volume());

  Sphere s4 {{6.9f, 4.2f, -1.2f}, 1.25f};
  REQUIRE(Approx(8.18123f) == s4.volume());

  auto s5 = std::make_shared<Sphere>(Sphere{{6.9f, 4.2f, -1.2f}, 1.25f});
  std::shared_ptr<Shape> shape = s5;
  REQUIRE(Approx(8.18123f) == shape -> volume());

}

TEST_CASE("Box: gets member min_ (minimum)", "[aufgabe5.2]") {
  Box b1 {}; // test default constructor 
  REQUIRE(0.0f == b1.minimum().x);
  REQUIRE(0.0f == b1.minimum().y);
  REQUIRE(0.0f == b1.minimum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(0.0f == b2.minimum().x);
  REQUIRE(2.3f == b2.minimum().y);
  REQUIRE(1.2f == b2.minimum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-9.0f == b3.minimum().x);
  REQUIRE(-4.3f == b3.minimum().y);
  REQUIRE(-2.2f == b3.minimum().z);
}

TEST_CASE("Box: gets member max_ (maximum)", "[aufgabe5.2]") {
  Box b1 {}; // test default constructor 
  REQUIRE(0.0f == b1.maximum().x);
  REQUIRE(0.0f == b1.maximum().y);
  REQUIRE(0.0f == b1.maximum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(1.0f == b2.maximum().x);
  REQUIRE(2.5f == b2.maximum().y);
  REQUIRE(4.1f == b2.maximum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-1.0f == b3.maximum().x);
  REQUIRE(1.5f == b3.maximum().y);
  REQUIRE(5.6f == b3.maximum().z);
}

TEST_CASE("Box: sets member min_ (minimum)", "[aufgabe5.2]"){
  Box b1 {};
  b1.minimum({1.0f, 1.0f, 1.0f});
  REQUIRE(1.0f == b1.minimum().x);
  REQUIRE(1.0f == b1.minimum().y);
  REQUIRE(1.0f == b1.minimum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  b2.minimum({-3.5f, 2.4f, -11.3f});
  REQUIRE(-3.5f == b2.minimum().x);
  REQUIRE(2.4f == b2.minimum().y);
  REQUIRE(-11.3f == b2.minimum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  b3.minimum({-2.2f, 12.3f, -0.9f});
  REQUIRE(-2.2f == b3.minimum().x);
  REQUIRE(12.3f == b3.minimum().y);
  REQUIRE(-0.9f == b3.minimum().z);
}

TEST_CASE("Box: sets member max_ (maximum)", "[aufgabe5.2]"){
  Box b1 {};
  b1.maximum({1.0f, 1.0f, 1.0f});
  REQUIRE(1.0f == b1.maximum().x);
  REQUIRE(1.0f == b1.maximum().y);
  REQUIRE(1.0f == b1.maximum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  b2.maximum({-3.5f, 2.4f, -11.3f});
  REQUIRE(-3.5f == b2.maximum().x);
  REQUIRE(2.4f == b2.maximum().y);
  REQUIRE(-11.3f == b2.maximum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  b3.maximum({-2.2f, 12.3f, -0.9f});
  REQUIRE(-2.2f == b3.maximum().x);
  REQUIRE(12.3f == b3.maximum().y);
  REQUIRE(-0.9f == b3.maximum().z);
}

TEST_CASE("Box: gets area of box object", "[aufgabe5.2]") {
  Box b1 {};
  REQUIRE(0.0f == b1.area());

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(Approx(7.36f) == b2.area());

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(Approx(308.08f) == b3.area());

  Box b4 {{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}};
  REQUIRE(Approx(34.78f) == b4.area());

  auto b5 = std::make_shared<Box>(Box{{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}});
  std::shared_ptr<Shape> box = b5;
  REQUIRE(Approx(34.78f) == box -> area());
  
}

TEST_CASE("Box: gets volume of box object", "[aufgabe5.2]") {
  Box b1 {};
  REQUIRE(0.0f == b1.volume());

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(Approx(0.58f) == b2.volume());

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(Approx(361.92f) == b3.volume());

  Box b4 {{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}};
  REQUIRE(Approx(6.67f) == b4.volume());

  auto b5 = std::make_shared<Box>(Box{{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}});
  std::shared_ptr<Shape> box = b5;
  REQUIRE(Approx(6.67f) == box -> volume());
} 

/* ------------------ Aufgabe 5.3 ------------------ */

TEST_CASE("Box: constructor tests", "[aufgabe5.3]") {
  Box b1 {};
  REQUIRE(0.0f == b1.minimum().x);
  REQUIRE(0.0f == b1.minimum().y);
  REQUIRE(0.0f == b1.minimum().z);

  REQUIRE(0.0f == b1.maximum().x);
  REQUIRE(0.0f == b1.maximum().y);
  REQUIRE(0.0f == b1.maximum().z);

  REQUIRE("Box" == b1.name());

  REQUIRE("Material" == b1.material().name_);
  REQUIRE(0.0f == b1.material().ambient().r);
  REQUIRE(0.0f == b1.material().ambient().g);
  REQUIRE(0.0f == b1.material().ambient().b);
  REQUIRE(0.0f == b1.material().diffuse().r);
  REQUIRE(0.0f == b1.material().diffuse().g);
  REQUIRE(0.0f == b1.material().diffuse().b);
  REQUIRE(0.0f == b1.material().specular().r);
  REQUIRE(0.0f == b1.material().specular().g);
  REQUIRE(0.0f == b1.material().specular().b);
  REQUIRE(0.0f == b1.material().m_);


  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(0.0f == b2.minimum().x);
  REQUIRE(2.3f == b2.minimum().y);
  REQUIRE(1.2f == b2.minimum().z);

  REQUIRE(1.0f == b2.maximum().x);
  REQUIRE(2.5f == b2.maximum().y);
  REQUIRE(4.1f == b2.maximum().z);

  REQUIRE("Box" == b2.name());

  REQUIRE("Material" == b2.material().name_);
  REQUIRE(0.0f == b2.material().ambient().r);
  REQUIRE(0.0f == b2.material().ambient().g);
  REQUIRE(0.0f == b2.material().ambient().b);
  REQUIRE(0.0f == b2.material().diffuse().r);
  REQUIRE(0.0f == b2.material().diffuse().g);
  REQUIRE(0.0f == b2.material().diffuse().b);
  REQUIRE(0.0f == b2.material().specular().r);
  REQUIRE(0.0f == b2.material().specular().g);
  REQUIRE(0.0f == b2.material().specular().b);
  REQUIRE(0.0f == b2.material().m_);


  Box b3 {"Box 3", {"Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-9.0f == b3.minimum().x);
  REQUIRE(-4.3f == b3.minimum().y);
  REQUIRE(-2.2f == b3.minimum().z);

  REQUIRE(-1.0f == b3.maximum().x);
  REQUIRE(1.5f == b3.maximum().y);
  REQUIRE(5.6f == b3.maximum().z);

  REQUIRE("Box 3" == b3.name());

  REQUIRE("Eisen" == b3.material().name_);
  REQUIRE(1.0f == b3.material().ambient().r);
  REQUIRE(2.2f == b3.material().ambient().g);
  REQUIRE(4.2f == b3.material().ambient().b);
  REQUIRE(3.3f == b3.material().diffuse().r);
  REQUIRE(4.4f == b3.material().diffuse().g);
  REQUIRE(5.5f == b3.material().diffuse().b);
  REQUIRE(3.1f == b3.material().specular().r);
  REQUIRE(5.0f == b3.material().specular().g);
  REQUIRE(0.1f == b3.material().specular().b);
  REQUIRE(3.2f == b3.material().m_);

} 

TEST_CASE("Sphere: constructor tests", "[aufgabe5.3]") {
  Sphere s1 {};
  REQUIRE(0.0f == s1.center().x);
  REQUIRE(0.0f == s1.center().y);
  REQUIRE(0.0f == s1.center().z);

  REQUIRE(0.0f == s1.radius());

  REQUIRE("Sphere" == s1.name());

  REQUIRE("Material" == s1.material().name_);
  REQUIRE(0.0f == s1.material().ambient().r);
  REQUIRE(0.0f == s1.material().ambient().g);
  REQUIRE(0.0f == s1.material().ambient().b);
  REQUIRE(0.0f == s1.material().diffuse().r);
  REQUIRE(0.0f == s1.material().diffuse().g);
  REQUIRE(0.0f == s1.material().diffuse().b);
  REQUIRE(0.0f == s1.material().specular().r);
  REQUIRE(0.0f == s1.material().specular().g);
  REQUIRE(0.0f == s1.material().specular().b);
  REQUIRE(0.0f == s1.material().m_);
  
  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(0.4f == s2.center().x);
  REQUIRE(2.3f == s2.center().y);
  REQUIRE(1.2f == s2.center().z);
  
  REQUIRE(4.3f == s2.radius());

  REQUIRE("Sphere" == s2.name());

  REQUIRE("Material" == s2.material().name_);
  REQUIRE(0.0f == s2.material().ambient().r);
  REQUIRE(0.0f == s2.material().ambient().g);
  REQUIRE(0.0f == s2.material().ambient().b);
  REQUIRE(0.0f == s2.material().diffuse().r);
  REQUIRE(0.0f == s2.material().diffuse().g);
  REQUIRE(0.0f == s2.material().diffuse().b);
  REQUIRE(0.0f == s2.material().specular().r);
  REQUIRE(0.0f == s2.material().specular().g);
  REQUIRE(0.0f == s2.material().specular().b);
  REQUIRE(0.0f == s2.material().m_);


  Sphere s3 {"Sphere 3", {"Aluminium", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(6.9f == s3.center().x);
  REQUIRE(4.2f == s3.center().y);
  REQUIRE(-1.2f == s3.center().z);

  REQUIRE(-6.9f == s3.radius());

  REQUIRE("Sphere 3" == s3.name());

  REQUIRE("Aluminium" == s3.material().name_);
  REQUIRE(1.0f == s3.material().ambient().r);
  REQUIRE(2.2f == s3.material().ambient().g);
  REQUIRE(4.2f == s3.material().ambient().b);
  REQUIRE(3.3f == s3.material().diffuse().r);
  REQUIRE(4.4f == s3.material().diffuse().g);
  REQUIRE(5.5f == s3.material().diffuse().b);
  REQUIRE(3.1f == s3.material().specular().r);
  REQUIRE(5.0f == s3.material().specular().g);
  REQUIRE(0.1f == s3.material().specular().b);
  REQUIRE(3.2f == s3.material().m_);
} 

/* ------------------ Aufgabe 5.5 ------------------ */

TEST_CASE("Shape: print method", "[aufgabe5.5]") {
  Sphere s1 {{0.4f, 2.3f, 1.2f}, 4.3f};
  std::cout << s1 << std::endl;

  Sphere s2 {"Kugel", {"Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {6.9f, 4.2f, -1.2f}, -6.9f};
  std::cout << s2 << std::endl;

  Box b1 {};
  std::cout << b1 << std::endl;

  auto b2 = std::make_shared<Box>(Box{"Schachtel", {}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}});
  b2 -> print(std::cout);
  std::cout << std::endl;
} 

/* ------------------ Aufgabe 5.6 ------------------ */

TEST_CASE("intersectRaySphere", "[aufgabe5.6]") {
  // Ray
  glm::vec3 ray_origin1{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized !
  // you can use : 
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction1{0.0f, 0.0f, 1.0f};

  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};

  float distance{0.0f};
  auto result = glm::intersectRaySphere(
    ray_origin1, ray_direction1,
    sphere_center,
    sphere_radius * sphere_radius, // squared radius !!!
    distance);

  REQUIRE(distance == Approx(4.0f));
  distance = 0;

  Material m1{};
  Sphere s2{"Himmelsphaemre",m1,{0.0f,0.0f,5.0f},1.0f};
  Ray r2{{0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 4.0f}};
  OptiHit dieter = s2.intersect(r2);
  glm::vec3 tom{0.0f,0.0f,-1.0f};
  glm::vec3 tim{0.0f,0.0f,4.0f};

  REQUIRE(dieter.hit_ == true);
  REQUIRE(dieter.distance_ == Approx(4.0f));
  //REQUIRE(dieter.closest_shape_ == s2);
  REQUIRE(dieter.normalen_vec_ == tom);
  REQUIRE(dieter.surface_pt_ == tim);

} 

/* ------------------ Aufgabe 5.7 ------------------ */

TEST_CASE("static and dynamic variables", "[aufgabe5.7]") {
  /* Allgemein: 
  STATISCH: zur Uebersetzungszeit festgelegt oder gebunden, kann zur Lauftzeit nicht
  veraendert werden (Bsp: Java, C++). 
  - Variablen werden mit Typ versehen, typabhängige Fehlererkennung, schnellere Ausfuehrung als dynamisch typisierte Sprachen
  DYNAMISCH: nicht festgelegt bis zur Laufzeit des Programms. Erlaubt veraenderungen
  waehrend des Programmablaufs (Bsp: Scheme, Javascript).
  - Variablen sind nur Namen, Typen sind mit Weten verbunden, keine Deklarationen, deshalb groessere Flexibilitaet*/

  Color red(255, 0, 0); 
  Material mat("Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f);
  glm::vec3 position(0, 0, 0); 

  // Adresse eines Sphere-Objektes wird an eine Zeigervariable vom Typ Sphere zugewiesen
  std::shared_ptr<Sphere> s1 = // statische Klasse
    std::make_shared<Sphere>("sphere0", mat, position, 1.2); // dynamische Klasse 
    // statische und dynamische Klasse sind identisch

  // Adresse eines Sphere-Objektes wird an eine Zeigervariable vom Typ der Basisklasse Shape zugewiesen
  std::shared_ptr<Shape> s2 = // statische Klasse
    std::make_shared<Sphere>("sphere1", mat, position, 1.2); // dynamische Klasse
    // statische und dynamische Klasse unterscheiden sich
    

  /* Im Kontext der Vererbung erlauben statisch typisierte OO-Sprachen, dass die dynamische Klasse
   eine von der statischen Klasse abgeleitete Klasse sein kann. 
   Die dynamische Klasse bestimmt bei virtuellen Funktionen, welche Methode ausgefuehrt wird. */

  std::cout << std::endl;
  s1 -> print(std::cout); 
  std::cout << std::endl;
  s2 -> print(std::cout);
  std::cout << std::endl;
} 

/* ------------------ Aufgabe 5.8 ------------------ */

TEST_CASE("Destructor: virtual vs. non-virtual", "[aufgabe5.8]") {
  // Color red(255, 0, 0); 
  Material mat("Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f);
  glm::vec3 position(0, 0, 0);

  Sphere* s0 = new Sphere("sphere0", mat, position, 1.2); 
  Shape* s1 = new Sphere("sphere1", mat, position, 1.2); // s ist polymorph

  std::cout << std::endl;
  s0 -> print(std::cout); 
  std::cout << std::endl;
  s1 -> print(std::cout);
  std::cout << std::endl;

  delete s0; 
  delete s1; 

  /* virtual: ruft erst den Unterklassen-Destruktor (Sphere), dann den Basisklasse (Shape) für beide Beispiele
     non-virtual: Sphere0: ruft zuerst den Destruktor der Klasse Sphere, dann den der Klasse (Shape)
     Sphere1: Ruft nur den Destruktor der Klasse Shape 
     => kommt zu Resource Leak, bei dem die erworbenen Ressourcen nicht mehr vom Programm freigegeben werden

     Ist der Destruktor nicht als virtual deklariert kommt es zu "undefinied behaviour", was zu bugs fuehren kann. 
     Virtual Destructors sind immer dann nuetzlich, wenn eine Klasse polymorph verwendet wird (bzw. mindestens eine 
     virtuelle Funktion vorhanden ist)
     http://stackoverflow.com/questions/461203/when-to-use-virtual-destructors */
} 

/* ------------------ Aufgabe 6.3 ------------------ */

// TEST_CASE("Box: intersect checks whether or not a ray hits a box", "[aufgabe6.3]") {

//   Ray r1 {};
//   Ray r2 {{1.0f, 1.0f, 1.0f}, {1.0f, 2.0f, 3.0f}};
//   Ray r3 {{2.3f, 4.2f, 6.9f}, {6.9f, 4.2f, 2.3f}};
//   Ray r4 {{0.0f, 0.0f, 0.0f}, {3.0f, 3.0f, 3.0f}};

//   Box boss {"He da Boss", {"Lebkuchen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {0.0f, 0.0f, 0.0f}, {3.0f, 3.0f, 3.0f}};
//   float distance = 0.0f;
  
//   REQUIRE(boss.intersect(r1) == false);
//   REQUIRE(distance == 0.0f);

//   REQUIRE(boss.intersect(r2) == true);
//   REQUIRE(distance == Approx(1.24722f));
//   distance = 0.0f;

//   REQUIRE(boss.intersect(r3) == false);
//   REQUIRE(distance == 0.0f);

//   REQUIRE(boss.intersect(r4) == true);
//   REQUIRE(distance == 0.0f);

//   Ray r5 {{-1.0f, -1.0f, -1.0f}, {1.0f, 2.0f, 3.0f}};
//   Ray r6 {{-6.0f, -7.0f, -8.0f}, {-6.9f, -4.2f, -2.3f}};
//   Ray r7 {{-7.0f, -5.0f, -7.0f}, {10.0f, 11.0f, 12.0f}};

//   Box billy {"Strangest Boy in Town", {"Nutellaglas", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {-3.0f, -5.5f, -1.2f}, {5.2f, 4.6f, 6.9f}};

//   REQUIRE(billy.intersect(r1) == false);
//   REQUIRE(distance == 0.0f);

//   REQUIRE(billy.intersect(r5) == true);
//   REQUIRE(distance == Approx(0.24944f));
//   distance = 0.0f;

//   REQUIRE(billy.intersect(r6) == false);
//   REQUIRE(distance == 0.0f);

//   REQUIRE(billy.intersect(r7) == true);
//   REQUIRE(distance == 9.23407f);
//   distance = 0.0f;

//   Ray r8 {{-9.2f, -11.0f, -12.2f}, {9.0f, 4.0f, 6.0f}};
//   Ray r9 {{-7.3f, -6.8f, -8.4f}, {-6.8f, -4.4f, -2.7f}};
//   Ray r10 {{-10.0f, -15.0f, -16.2f}, {10.6f, 12.5f, 9.3f}};

//   Box butch {"Don't mess with Her", {"Titan", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {-9.0f, -10.5f, -11.2f}, {-1.2f, -2.6f, -1.9f}};

//   REQUIRE(butch.intersect(r1) == false);
//   REQUIRE(distance == 0.0f);

//   REQUIRE(butch.intersect(r8) == true);
//   REQUIRE(distance == Approx(1.92209f));
//   distance = 0.0f;

//   REQUIRE(butch.intersect(r9) == true);
//   REQUIRE(distance == Approx(2.13439f));

//   REQUIRE(butch.intersect(r10) == true);
//   REQUIRE(distance == Approx(10.13125f));

// } 

TEST_CASE("Box intersect","[aufgabe 6.3]"){
  Material mat1{"Plüsch", {0.22f,0.33f,0.44f},
  {0.55f,0.66f,0.77f}, {0.88f,0.99f,0.11f},
  3.45f};
  // Ray
  Ray ronald{{0.5f,0.0f,1.0f}, {0.0f,1.0f,0.0f}};
  Ray donald{{0.5f,4.0f,2.5f}, {0.0f,-1.0f,0.0f}};
  Ray tonald{{0.0f,0.5f,0.0f}, {0.0f,1.0f,0.0f}};
  Ray zonald{{0.5f,0.0f,0.0f}, {0.0f,1.0f,3.0f}};
  Ray nonald{{0.5f,0.0f,0.0f}, {0.0f,1.0f,4.0f}};
  // Box
  Box b{"Bixi-Box",mat1,{0.0f,1.0f,0.0f},{1.0f,2.0f,3.0f}};
  //OptiHit
  OptiHit hit{};

  hit = b.intersect(ronald);
  REQUIRE(hit.hit_ == true);
  REQUIRE(hit.distance_ == 1.0f);
  REQUIRE(hit.normalen_vec_.x == 0.0f);
  REQUIRE(hit.normalen_vec_.y == -1.0f);
  REQUIRE(hit.normalen_vec_.z == 0.0f);
  REQUIRE(hit.surface_pt_.x == 0.5f);
  REQUIRE(hit.surface_pt_.y == 1.0f);
  REQUIRE(hit.surface_pt_.z == 1.0f);
  
  hit = b.intersect(donald);
  REQUIRE(hit.hit_ == true);
  REQUIRE(hit.distance_ == 2.0f);
  REQUIRE(hit.normalen_vec_.x == 0.0f);
  REQUIRE(hit.normalen_vec_.y == 1.0f);
  REQUIRE(hit.normalen_vec_.z == 0.0f);
  REQUIRE(hit.surface_pt_.x == 0.5f);
  REQUIRE(hit.surface_pt_.y == 2.0f);
  REQUIRE(hit.surface_pt_.z == 2.5f);
  
  hit = b.intersect(tonald);
  REQUIRE(hit.hit_ == true);
  REQUIRE(hit.distance_ == 0.5f);
  REQUIRE(hit.normalen_vec_.x == -1.0f);
  REQUIRE(hit.normalen_vec_.y == 0.0f);
  REQUIRE(hit.normalen_vec_.z == 0.0f);
  REQUIRE(hit.surface_pt_.x == 0.0f);
  REQUIRE(hit.surface_pt_.y == 1.0f);
  REQUIRE(hit.surface_pt_.z == 0.0f);
  
  hit = b.intersect(zonald);
  REQUIRE(hit.hit_ == false); //true
  REQUIRE(hit.distance_ == INFINITY); //10.0f
  REQUIRE(hit.normalen_vec_.x == 0.0f);
  REQUIRE(hit.normalen_vec_.y == 0.0f); //-1.0f
  REQUIRE(hit.normalen_vec_.z == 0.0f);
  REQUIRE(hit.surface_pt_.x == 0.0f); //0.5f
  REQUIRE(hit.surface_pt_.y == 0.0f); //1.0f
  REQUIRE(hit.surface_pt_.z == 0.0f); //3.0f
  
  hit = b.intersect(nonald);
  REQUIRE(hit.hit_ == false);
  REQUIRE(hit.distance_ == INFINITY);
  REQUIRE(hit.normalen_vec_.x == 0.0f);
  REQUIRE(hit.normalen_vec_.y == 0.0f);
  REQUIRE(hit.normalen_vec_.z == 0.0f);
  REQUIRE(hit.surface_pt_.x == 0.0f);
  REQUIRE(hit.surface_pt_.y == 0.0f);
  REQUIRE(hit.surface_pt_.z == 0.0f);

}

/* ------------------ Aufgabe 7.1 ------------------ */

TEST_CASE("Camera: prints camera (every member)", "[aufgabe7.1]") {

  Camera camera {};
  camera.print(std::cout);

  Camera pamela {"Pamela", 90.0};
  pamela.print(std::cout);

}

TEST_CASE("LightSource: prints light (every member)", "[aufgabe7.1]") {

  LightSource light {};
  light.print(std::cout);

  LightSource lucifer {"Lucifer", {0.5f, 0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.4f, 0.1f, 0.1f}};
  lucifer.print(std::cout);

}

/* ------------------ Aufgabe 7.2 ------------------ */

TEST_CASE("Composite: Adding and removing shapes out of the composite", "[aufgabe7.2]") {
  typedef std::shared_ptr<Shape> shape_ptr;
  typedef glm::vec3 vec;

  shape_ptr b1 = std::make_shared<Box>();
  REQUIRE(0.0f == b1 -> area());

  vec min2, max2;
  min2.x = 1.0f;
  min2.y = 2.3f;
  min2.z = 4.1f;
  max2.x = 0.0f;
  max2.y = 2.5f;
  max2.z = 1.2f;

  shape_ptr b2 = std::make_shared<Box>(min2, max2);
  REQUIRE(Approx(7.36f) == b2 -> area());

  shape_ptr s1 = std::make_shared<Sphere>();
  REQUIRE(0.0f == s1 -> area());
  
  vec ctr2;
  ctr2.x = 0.4f;
  ctr2.y = 2.3f;
  ctr2.z = 1.2f;

  shape_ptr s2 = std::make_shared<Sphere>(ctr2, 4.3f);
  REQUIRE(Approx(232.3522f) == s2 -> area());

  Composite comp {};
  comp.addShape(b1);
  comp.addShape(s1);
  comp.addShape(b2);
  comp.addShape(s2);

  comp.print(std::cout); // testing the print function

  comp.removeShape(b1);
  comp.removeShape(b2);
  comp.removeShape(s2);

  comp.print(std::cout);

}

TEST_CASE("Composite: gets area of every shape in the composite and prints it", "[aufgabe7.2]") {
  typedef std::shared_ptr<Shape> shape_ptr;
  typedef glm::vec3 vec;

  shape_ptr b1 = std::make_shared<Box>();
  REQUIRE(0.0f == b1 -> area());

  vec min2, max2;
  min2.x = 1.0f;
  min2.y = 2.3f;
  min2.z = 4.1f;
  max2.x = 0.0f;
  max2.y = 2.5f;
  max2.z = 1.2f;

  shape_ptr b2 = std::make_shared<Box>(min2, max2);
  REQUIRE(Approx(7.36f) == b2 -> area());

  shape_ptr s1 = std::make_shared<Sphere>();
  REQUIRE(0.0f == s1 -> area());
  
  vec ctr2;
  ctr2.x = 0.4f;
  ctr2.y = 2.3f;
  ctr2.z = 1.2f;

  shape_ptr s2 = std::make_shared<Sphere>(ctr2, 4.3f);
  REQUIRE(Approx(232.3522f) == s2 -> area());

  Composite comp {};
  comp.addShape(b1);
  comp.addShape(s1);
  comp.addShape(b2);
  comp.addShape(s2);

  comp.area();

}

TEST_CASE("Composite: gets volume of every shape in the composite and prints it", "[aufgabe7.2]") {
  typedef std::shared_ptr<Shape> shape_ptr;
  typedef glm::vec3 vec;

  shape_ptr b1 = std::make_shared<Box>();
  REQUIRE(0.0f == b1 -> volume());

  vec min2, max2;
  min2.x = 1.0f;
  min2.y = 2.3f;
  min2.z = 4.1f;
  max2.x = 0.0f;
  max2.y = 2.5f;
  max2.z = 1.2f;

  shape_ptr b2 = std::make_shared<Box>(min2, max2);
  REQUIRE(Approx(0.58f) == b2 -> volume());

  shape_ptr s1 = std::make_shared<Sphere>();
  REQUIRE(0.0f == s1 -> volume());
  
  vec ctr2;
  ctr2.x = 0.4f;
  ctr2.y = 2.3f;
  ctr2.z = 1.2f;

  shape_ptr s2 = std::make_shared<Sphere>(ctr2, 4.3f);
  REQUIRE(Approx(333.0381f) == s2 -> volume());

  Composite comp {};
  comp.addShape(b1);
  comp.addShape(s1);
  comp.addShape(b2);
  comp.addShape(s2);

  comp.volume();
}

TEST_CASE("Composite: intersect() checks which hit point is nearest to the ray origin", "[aufgabe7.2]") {
  typedef std::shared_ptr<Shape> shape_ptr;

  shape_ptr s1 = std::make_shared<Sphere>(Sphere {{0.0f, 0.0f, -4.0f}, 5.2});
  shape_ptr s2 = std::make_shared<Sphere>(Sphere {{4.0f, 0.0f, -5.0f}, 2.1});
  shape_ptr s3 = std::make_shared<Sphere>(Sphere {{1.0f, 0.3f, 2.0f}, 1.9});
  shape_ptr s4 = std::make_shared<Sphere>(Sphere {{0.0f, 0.0f, -3.0f}, 2.2});
  shape_ptr s5 = std::make_shared<Sphere>(Sphere {{0.0f, 0.0f, -2.9f}, 2.2});

  Composite comp {};
  comp.addShape(s1);
  comp.addShape(s2);
  comp.addShape(s3);
  comp.addShape(s4);

  Ray ray {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, -1.0f}};
  OptiHit hit1 = s1 -> intersect(ray);
  OptiHit hit2 = s2 -> intersect(ray);
  OptiHit hit4 = s4 -> intersect(ray);
  OptiHit hit5 = s5 -> intersect(ray);
  OptiHit hitComp = comp.intersect(ray);
  REQUIRE(hit4.distance_ == hitComp.distance_);
  REQUIRE(hit2.hit_ != hitComp.hit_);
  REQUIRE(hit2.distance_ > hitComp.distance_);
  REQUIRE(hit1.hit_ == hitComp.hit_);
  REQUIRE(hit1.distance_ > hitComp.distance_);
  REQUIRE(hit5.distance_ < hitComp.distance_);

}

/* ------------------ Aufgabe 7.6 ------------------ */

TEST_CASE("Shape: set worldTransformInv_", "[aufgabe7.6]") {

	// /!\ glm::mat4 [column][line], [Spalte][Zeile]

	auto s1 = std::make_shared<Sphere>();
	glm::mat4 mat {1.0f, 1.0f, 1.0f, 1.0f,
				   0.0f, 0.0f, 0.0f, 0.0f,
				   1.0f, 1.0f, 1.0f, 1.0f,
				   0.0f, 0.0f, 0.0f, 0.0f};
	s1 -> world_transformation(mat);
	REQUIRE(s1 -> world_transformation()[0].w == mat[0].w);
	REQUIRE(s1 -> world_transformation()[0].x == mat[0].x);
	REQUIRE(s1 -> world_transformation()[0].y == mat[0].y);
	REQUIRE(s1 -> world_transformation()[0].z == mat[0].z);
	REQUIRE(s1 -> world_transformation()[1].w == mat[1].w);
	REQUIRE(s1 -> world_transformation()[1].x == mat[1].x);
	REQUIRE(s1 -> world_transformation()[1].y == mat[1].y);
	REQUIRE(s1 -> world_transformation()[1].z == mat[1].z);
	REQUIRE(s1 -> world_transformation()[2].w == mat[2].w);
	REQUIRE(s1 -> world_transformation()[2].x == mat[2].x);
	REQUIRE(s1 -> world_transformation()[2].y == mat[2].y);
	REQUIRE(s1 -> world_transformation()[2].z == mat[2].z);
	REQUIRE(s1 -> world_transformation()[3].w == mat[3].w);
	REQUIRE(s1 -> world_transformation()[3].x == mat[3].x);
	REQUIRE(s1 -> world_transformation()[3].y == mat[3].y);
	REQUIRE(s1 -> world_transformation()[3].z == mat[3].z);

	// there's no inverse matrix to "mat"

	auto b1 = std::make_shared<Box>();
	glm::mat4 pat {1.4f, 1.0f, 1.0f, 1.0f,
				   0.0f, 0.5f, 0.0f, 0.0f,
				   1.0f, 1.0f, 1.6f, 1.0f,
				   0.0f, 0.0f, 0.0f, 0.7f};
    b1 -> world_transformation(pat);
    REQUIRE(b1 -> world_transformation()[0].w == pat[0].w);
    REQUIRE(b1 -> world_transformation()[0].x == pat[0].x);
    REQUIRE(b1 -> world_transformation()[0].y == pat[0].y);
    REQUIRE(b1 -> world_transformation()[0].z == pat[0].z);
    REQUIRE(b1 -> world_transformation()[1].w == pat[1].w);
    REQUIRE(b1 -> world_transformation()[1].x == pat[1].x);
    REQUIRE(b1 -> world_transformation()[1].y == pat[1].y);
    REQUIRE(b1 -> world_transformation()[1].z == pat[1].z);
    REQUIRE(b1 -> world_transformation()[2].w == pat[2].w);
    REQUIRE(b1 -> world_transformation()[2].x == pat[2].x);
    REQUIRE(b1 -> world_transformation()[2].y == pat[2].y);
    REQUIRE(b1 -> world_transformation()[2].z == pat[2].z);
    REQUIRE(b1 -> world_transformation()[3].w == pat[3].w);
    REQUIRE(b1 -> world_transformation()[3].x == pat[3].x);
    REQUIRE(b1 -> world_transformation()[3].y == pat[3].y);
    REQUIRE(b1 -> world_transformation()[3].z == pat[3].z);

    glm::mat4 patInv = glm::inverse(pat);
    REQUIRE(b1 -> world_transformation_inv()[0].w == patInv[0].w);
    REQUIRE(b1 -> world_transformation_inv()[0].x == patInv[0].x);
    REQUIRE(b1 -> world_transformation_inv()[0].y == patInv[0].y);
    REQUIRE(b1 -> world_transformation_inv()[0].z == patInv[0].z);
    REQUIRE(b1 -> world_transformation_inv()[1].w == patInv[1].w);
    REQUIRE(b1 -> world_transformation_inv()[1].x == patInv[1].x);
    REQUIRE(b1 -> world_transformation_inv()[1].y == patInv[1].y);
    REQUIRE(b1 -> world_transformation_inv()[1].z == patInv[1].z);
    REQUIRE(b1 -> world_transformation_inv()[2].w == patInv[2].w);
    REQUIRE(b1 -> world_transformation_inv()[2].x == patInv[2].x);
    REQUIRE(b1 -> world_transformation_inv()[2].y == patInv[2].y);
    REQUIRE(b1 -> world_transformation_inv()[2].z == patInv[2].z);
    REQUIRE(b1 -> world_transformation_inv()[3].w == patInv[3].w);
    REQUIRE(b1 -> world_transformation_inv()[3].x == patInv[3].x);
    REQUIRE(b1 -> world_transformation_inv()[3].y == patInv[3].y);
    REQUIRE(b1 -> world_transformation_inv()[3].z == patInv[3].z);

}

TEST_CASE("Shape: Translation", "[aufgabe7.6]") {

		// test lambda uses glm::translate()
	auto translateLambda = [](glm::vec3 const& v, std::shared_ptr<Shape> const& s) {
		auto transMat = glm::translate(s -> world_transformation(), v);
		s -> world_transformation(transMat * s -> world_transformation());
	};

	auto s1 = std::make_shared<Sphere>();
	auto s2 = std::make_shared<Sphere>();
	s1 -> translate(glm::vec3 {2.0f, 1.0f, 2.0f});
	translateLambda(glm::vec3 {2.0f, 1.0f, 2.0f}, s2);

	REQUIRE(s1 -> world_transformation()[0].w == s2 -> world_transformation()[0].w);
	REQUIRE(s1 -> world_transformation()[0].x == s2 -> world_transformation()[0].x);
	REQUIRE(s1 -> world_transformation()[0].y == s2 -> world_transformation()[0].y);
	REQUIRE(s1 -> world_transformation()[0].z == s2 -> world_transformation()[0].z);
	REQUIRE(s1 -> world_transformation()[1].w == s2 -> world_transformation()[1].w);
	REQUIRE(s1 -> world_transformation()[1].x == s2 -> world_transformation()[1].x);
	REQUIRE(s1 -> world_transformation()[1].y == s2 -> world_transformation()[1].y);
	REQUIRE(s1 -> world_transformation()[1].z == s2 -> world_transformation()[1].z);
	REQUIRE(s1 -> world_transformation()[2].w == s2 -> world_transformation()[2].w);
	REQUIRE(s1 -> world_transformation()[2].x == s2 -> world_transformation()[2].x);
	REQUIRE(s1 -> world_transformation()[2].y == s2 -> world_transformation()[2].y);
	REQUIRE(s1 -> world_transformation()[2].z == s2 -> world_transformation()[2].z);
	REQUIRE(s1 -> world_transformation()[3].w == s2 -> world_transformation()[3].w);
	REQUIRE(s1 -> world_transformation()[3].x == s2 -> world_transformation()[3].x);
	REQUIRE(s1 -> world_transformation()[3].y == s2 -> world_transformation()[3].y);
	REQUIRE(s1 -> world_transformation()[3].z == s2 -> world_transformation()[3].z);

	auto b1 = std::make_shared<Box>();
	auto b2 = std::make_shared<Box>();
	b1 -> translate(glm::vec3 {2.0f, 1.0f, 2.0f});
	translateLambda(glm::vec3 {2.0f, 1.0f, 2.0f}, b2);

	REQUIRE(b1 -> world_transformation()[0].w == b2 -> world_transformation()[0].w);
	REQUIRE(b1 -> world_transformation()[0].x == b2 -> world_transformation()[0].x);
	REQUIRE(b1 -> world_transformation()[0].y == b2 -> world_transformation()[0].y);
	REQUIRE(b1 -> world_transformation()[0].z == b2 -> world_transformation()[0].z);
	REQUIRE(b1 -> world_transformation()[1].w == b2 -> world_transformation()[1].w);
	REQUIRE(b1 -> world_transformation()[1].x == b2 -> world_transformation()[1].x);
	REQUIRE(b1 -> world_transformation()[1].y == b2 -> world_transformation()[1].y);
	REQUIRE(b1 -> world_transformation()[1].z == b2 -> world_transformation()[1].z);
	REQUIRE(b1 -> world_transformation()[2].w == b2 -> world_transformation()[2].w);
	REQUIRE(b1 -> world_transformation()[2].x == b2 -> world_transformation()[2].x);
	REQUIRE(b1 -> world_transformation()[2].y == b2 -> world_transformation()[2].y);
	REQUIRE(b1 -> world_transformation()[2].z == b2 -> world_transformation()[2].z);
	REQUIRE(b1 -> world_transformation()[3].w == b2 -> world_transformation()[3].w);
	REQUIRE(b1 -> world_transformation()[3].x == b2 -> world_transformation()[3].x);
	REQUIRE(b1 -> world_transformation()[3].y == b2 -> world_transformation()[3].y);
	REQUIRE(b1 -> world_transformation()[3].z == b2 -> world_transformation()[3].z);
}

TEST_CASE("Shape: Scaling", "[aufgabe7.6]") {

		// test lambda uses glm::scale()
	auto scaleLambda = [](glm::vec3 const& v, std::shared_ptr<Shape> const& s) {
		auto scaleMat = glm::scale(s -> world_transformation(), v);
		s -> world_transformation(scaleMat * s -> world_transformation());
	};

	auto s1 = std::make_shared<Sphere>();
	auto s2 = std::make_shared<Sphere>();
	s1 -> scale(glm::vec3 {2.0f, 2.0f, 2.0f});
	scaleLambda(glm::vec3 {2.0f, 2.0f, 2.0f}, s2);

	REQUIRE(s1 -> world_transformation()[0].w == s2 -> world_transformation()[0].w);
	REQUIRE(s1 -> world_transformation()[0].x == s2 -> world_transformation()[0].x);
	REQUIRE(s1 -> world_transformation()[0].y == s2 -> world_transformation()[0].y);
	REQUIRE(s1 -> world_transformation()[0].z == s2 -> world_transformation()[0].z);
	REQUIRE(s1 -> world_transformation()[1].w == s2 -> world_transformation()[1].w);
	REQUIRE(s1 -> world_transformation()[1].x == s2 -> world_transformation()[1].x);
	REQUIRE(s1 -> world_transformation()[1].y == s2 -> world_transformation()[1].y);
	REQUIRE(s1 -> world_transformation()[1].z == s2 -> world_transformation()[1].z);
	REQUIRE(s1 -> world_transformation()[2].w == s2 -> world_transformation()[2].w);
	REQUIRE(s1 -> world_transformation()[2].x == s2 -> world_transformation()[2].x);
	REQUIRE(s1 -> world_transformation()[2].y == s2 -> world_transformation()[2].y);
	REQUIRE(s1 -> world_transformation()[2].z == s2 -> world_transformation()[2].z);
	REQUIRE(s1 -> world_transformation()[3].w == s2 -> world_transformation()[3].w);
	REQUIRE(s1 -> world_transformation()[3].x == s2 -> world_transformation()[3].x);
	REQUIRE(s1 -> world_transformation()[3].y == s2 -> world_transformation()[3].y);
	REQUIRE(s1 -> world_transformation()[3].z == s2 -> world_transformation()[3].z);


	auto b1 = std::make_shared<Box>();
	auto b2 = std::make_shared<Box>();
	b1 -> scale(glm::vec3 {2.0f, 2.0f, 2.0f});
	scaleLambda(glm::vec3 {2.0f, 2.0f, 2.0f}, b2);

	REQUIRE(b1 -> world_transformation()[0].w == b2 -> world_transformation()[0].w);
	REQUIRE(b1 -> world_transformation()[0].x == b2 -> world_transformation()[0].x);
	REQUIRE(b1 -> world_transformation()[0].y == b2 -> world_transformation()[0].y);
	REQUIRE(b1 -> world_transformation()[0].z == b2 -> world_transformation()[0].z);
	REQUIRE(b1 -> world_transformation()[1].w == b2 -> world_transformation()[1].w);
	REQUIRE(b1 -> world_transformation()[1].x == b2 -> world_transformation()[1].x);
	REQUIRE(b1 -> world_transformation()[1].y == b2 -> world_transformation()[1].y);
	REQUIRE(b1 -> world_transformation()[1].z == b2 -> world_transformation()[1].z);
	REQUIRE(b1 -> world_transformation()[2].w == b2 -> world_transformation()[2].w);
	REQUIRE(b1 -> world_transformation()[2].x == b2 -> world_transformation()[2].x);
	REQUIRE(b1 -> world_transformation()[2].y == b2 -> world_transformation()[2].y);
	REQUIRE(b1 -> world_transformation()[2].z == b2 -> world_transformation()[2].z);
	REQUIRE(b1 -> world_transformation()[3].w == b2 -> world_transformation()[3].w);
	REQUIRE(b1 -> world_transformation()[3].x == b2 -> world_transformation()[3].x);
	REQUIRE(b1 -> world_transformation()[3].y == b2 -> world_transformation()[3].y);
	REQUIRE(b1 -> world_transformation()[3].z == b2 -> world_transformation()[3].z);
} 

TEST_CASE("Shape: RotationX", "[aufgabe7.6]") {
	
		// test lambda uses glm::rotate()
	auto rotateLambda = [](glm::vec3 const& v, float phi, std::shared_ptr<Shape> const& s) {
		auto rotateMat = glm::rotate(s -> world_transformation(), phi, v);
		s -> world_transformation(rotateMat * s -> world_transformation());
	};

	auto s1 = std::make_shared<Sphere>();
	auto s2 = std::make_shared<Sphere>();
	s1 -> rotateX(45.0f);
	rotateLambda(glm::vec3 {1.0f, 0.0f, 0.0f}, 45.0f, s2);

	REQUIRE(s1 -> world_transformation()[0].w == s2 -> world_transformation()[0].w);
	REQUIRE(s1 -> world_transformation()[0].x == s2 -> world_transformation()[0].x);
	REQUIRE(s1 -> world_transformation()[0].y == s2 -> world_transformation()[0].y);
	REQUIRE(s1 -> world_transformation()[0].z == s2 -> world_transformation()[0].z);
	REQUIRE(s1 -> world_transformation()[1].w == s2 -> world_transformation()[1].w);
	REQUIRE(s1 -> world_transformation()[1].x == s2 -> world_transformation()[1].x);
	REQUIRE(s1 -> world_transformation()[1].y == s2 -> world_transformation()[1].y);
	REQUIRE(s1 -> world_transformation()[1].z == s2 -> world_transformation()[1].z);
	REQUIRE(s1 -> world_transformation()[2].w == s2 -> world_transformation()[2].w);
	REQUIRE(s1 -> world_transformation()[2].x == s2 -> world_transformation()[2].x);
	REQUIRE(s1 -> world_transformation()[2].y == s2 -> world_transformation()[2].y);
	REQUIRE(s1 -> world_transformation()[2].z == s2 -> world_transformation()[2].z);
	REQUIRE(s1 -> world_transformation()[3].w == s2 -> world_transformation()[3].w);
	REQUIRE(s1 -> world_transformation()[3].x == s2 -> world_transformation()[3].x);
	REQUIRE(s1 -> world_transformation()[3].y == s2 -> world_transformation()[3].y);
	REQUIRE(s1 -> world_transformation()[3].z == s2 -> world_transformation()[3].z);

	auto b1 = std::make_shared<Box>();
	auto b2 = std::make_shared<Box>();
	b1 -> rotateX(70.0f);
	rotateLambda(glm::vec3 {1.0f, 0.0f, 0.0f}, 70.0f, b2);

	REQUIRE(b1 -> world_transformation()[0].w == b2 -> world_transformation()[0].w);
	REQUIRE(b1 -> world_transformation()[0].x == b2 -> world_transformation()[0].x);
	REQUIRE(b1 -> world_transformation()[0].y == b2 -> world_transformation()[0].y);
	REQUIRE(b1 -> world_transformation()[0].z == b2 -> world_transformation()[0].z);
	REQUIRE(b1 -> world_transformation()[1].w == b2 -> world_transformation()[1].w);
	REQUIRE(b1 -> world_transformation()[1].x == b2 -> world_transformation()[1].x);
	REQUIRE(b1 -> world_transformation()[1].y == b2 -> world_transformation()[1].y);
	REQUIRE(b1 -> world_transformation()[1].z == b2 -> world_transformation()[1].z);
	REQUIRE(b1 -> world_transformation()[2].w == b2 -> world_transformation()[2].w);
	REQUIRE(b1 -> world_transformation()[2].x == b2 -> world_transformation()[2].x);
	REQUIRE(b1 -> world_transformation()[2].y == b2 -> world_transformation()[2].y);
	REQUIRE(b1 -> world_transformation()[2].z == b2 -> world_transformation()[2].z);
	REQUIRE(b1 -> world_transformation()[3].w == b2 -> world_transformation()[3].w);
	REQUIRE(b1 -> world_transformation()[3].x == b2 -> world_transformation()[3].x);
	REQUIRE(b1 -> world_transformation()[3].y == b2 -> world_transformation()[3].y);
	REQUIRE(b1 -> world_transformation()[3].z == b2 -> world_transformation()[3].z);

}

TEST_CASE("Shape: RotationY", "[aufgabe7.6]") {
	
		// test lambda uses glm::rotate()
	auto rotateLambda = [](glm::vec3 const& v, float phi, std::shared_ptr<Shape> const& s) {
		auto rotateMat = glm::rotate(s -> world_transformation(), phi, v);
		s -> world_transformation(rotateMat * s -> world_transformation());
	};

	auto s1 = std::make_shared<Sphere>();
	auto s2 = std::make_shared<Sphere>();
	s1 -> rotateY(35.0f);
	rotateLambda(glm::vec3 {0.0f, 1.0f, 0.0f}, 35.0f, s2);

	REQUIRE(s1 -> world_transformation()[0].w == s2 -> world_transformation()[0].w);
	REQUIRE(s1 -> world_transformation()[0].x == s2 -> world_transformation()[0].x);
	REQUIRE(s1 -> world_transformation()[0].y == s2 -> world_transformation()[0].y);
	REQUIRE(s1 -> world_transformation()[0].z == s2 -> world_transformation()[0].z);
	REQUIRE(s1 -> world_transformation()[1].w == s2 -> world_transformation()[1].w);
	REQUIRE(s1 -> world_transformation()[1].x == s2 -> world_transformation()[1].x);
	REQUIRE(s1 -> world_transformation()[1].y == s2 -> world_transformation()[1].y);
	REQUIRE(s1 -> world_transformation()[1].z == s2 -> world_transformation()[1].z);
	REQUIRE(s1 -> world_transformation()[2].w == s2 -> world_transformation()[2].w);
	REQUIRE(s1 -> world_transformation()[2].x == s2 -> world_transformation()[2].x);
	REQUIRE(s1 -> world_transformation()[2].y == s2 -> world_transformation()[2].y);
	REQUIRE(s1 -> world_transformation()[2].z == s2 -> world_transformation()[2].z);
	REQUIRE(s1 -> world_transformation()[3].w == s2 -> world_transformation()[3].w);
	REQUIRE(s1 -> world_transformation()[3].x == s2 -> world_transformation()[3].x);
	REQUIRE(s1 -> world_transformation()[3].y == s2 -> world_transformation()[3].y);
	REQUIRE(s1 -> world_transformation()[3].z == s2 -> world_transformation()[3].z);

	auto b1 = std::make_shared<Box>();
	auto b2 = std::make_shared<Box>();
	b1 -> rotateY(12.0f);
	rotateLambda(glm::vec3 {0.0f, 1.0f, 0.0f}, 12.0f, b2);

	REQUIRE(b1 -> world_transformation()[0].w == b2 -> world_transformation()[0].w);
	REQUIRE(b1 -> world_transformation()[0].x == b2 -> world_transformation()[0].x);
	REQUIRE(b1 -> world_transformation()[0].y == b2 -> world_transformation()[0].y);
	REQUIRE(b1 -> world_transformation()[0].z == b2 -> world_transformation()[0].z);
	REQUIRE(b1 -> world_transformation()[1].w == b2 -> world_transformation()[1].w);
	REQUIRE(b1 -> world_transformation()[1].x == b2 -> world_transformation()[1].x);
	REQUIRE(b1 -> world_transformation()[1].y == b2 -> world_transformation()[1].y);
	REQUIRE(b1 -> world_transformation()[1].z == b2 -> world_transformation()[1].z);
	REQUIRE(b1 -> world_transformation()[2].w == b2 -> world_transformation()[2].w);
	REQUIRE(b1 -> world_transformation()[2].x == b2 -> world_transformation()[2].x);
	REQUIRE(b1 -> world_transformation()[2].y == b2 -> world_transformation()[2].y);
	REQUIRE(b1 -> world_transformation()[2].z == b2 -> world_transformation()[2].z);
	REQUIRE(b1 -> world_transformation()[3].w == b2 -> world_transformation()[3].w);
	REQUIRE(b1 -> world_transformation()[3].x == b2 -> world_transformation()[3].x);
	REQUIRE(b1 -> world_transformation()[3].y == b2 -> world_transformation()[3].y);
	REQUIRE(b1 -> world_transformation()[3].z == b2 -> world_transformation()[3].z);

}

TEST_CASE("Shape: RotationZ", "[aufgabe7.6]") {
	
		// test lambda uses glm::rotate()
	auto rotateLambda = [](glm::vec3 const& v, float phi, std::shared_ptr<Shape> const& s) {
		auto rotateMat = glm::rotate(s -> world_transformation(), phi, v);
		s -> world_transformation(rotateMat * s -> world_transformation());
	};

	auto s1 = std::make_shared<Sphere>();
	auto s2 = std::make_shared<Sphere>();
	s1 -> rotateZ(78.0f);
	rotateLambda(glm::vec3 {0.0f, 0.0f, 1.0f}, 78.0f, s2);

	REQUIRE(s1 -> world_transformation()[0].w == s2 -> world_transformation()[0].w);
	REQUIRE(s1 -> world_transformation()[0].x == s2 -> world_transformation()[0].x);
	REQUIRE(s1 -> world_transformation()[0].y == s2 -> world_transformation()[0].y);
	REQUIRE(s1 -> world_transformation()[0].z == s2 -> world_transformation()[0].z);
	REQUIRE(s1 -> world_transformation()[1].w == s2 -> world_transformation()[1].w);
	REQUIRE(s1 -> world_transformation()[1].x == s2 -> world_transformation()[1].x);
	REQUIRE(s1 -> world_transformation()[1].y == s2 -> world_transformation()[1].y);
	REQUIRE(s1 -> world_transformation()[1].z == s2 -> world_transformation()[1].z);
	REQUIRE(s1 -> world_transformation()[2].w == s2 -> world_transformation()[2].w);
	REQUIRE(s1 -> world_transformation()[2].x == s2 -> world_transformation()[2].x);
	REQUIRE(s1 -> world_transformation()[2].y == s2 -> world_transformation()[2].y);
	REQUIRE(s1 -> world_transformation()[2].z == s2 -> world_transformation()[2].z);
	REQUIRE(s1 -> world_transformation()[3].w == s2 -> world_transformation()[3].w);
	REQUIRE(s1 -> world_transformation()[3].x == s2 -> world_transformation()[3].x);
	REQUIRE(s1 -> world_transformation()[3].y == s2 -> world_transformation()[3].y);
	REQUIRE(s1 -> world_transformation()[3].z == s2 -> world_transformation()[3].z);

	auto b1 = std::make_shared<Box>();
	auto b2 = std::make_shared<Box>();
	b1 -> rotateZ(5.0f);
	rotateLambda(glm::vec3 {0.0f, 0.0f, 1.0f}, 5.0f, b2);

	REQUIRE(b1 -> world_transformation()[0].w == b2 -> world_transformation()[0].w);
	REQUIRE(b1 -> world_transformation()[0].x == b2 -> world_transformation()[0].x);
	REQUIRE(b1 -> world_transformation()[0].y == b2 -> world_transformation()[0].y);
	REQUIRE(b1 -> world_transformation()[0].z == b2 -> world_transformation()[0].z);
	REQUIRE(b1 -> world_transformation()[1].w == b2 -> world_transformation()[1].w);
	REQUIRE(b1 -> world_transformation()[1].x == b2 -> world_transformation()[1].x);
	REQUIRE(b1 -> world_transformation()[1].y == b2 -> world_transformation()[1].y);
	REQUIRE(b1 -> world_transformation()[1].z == b2 -> world_transformation()[1].z);
	REQUIRE(b1 -> world_transformation()[2].w == b2 -> world_transformation()[2].w);
	REQUIRE(b1 -> world_transformation()[2].x == b2 -> world_transformation()[2].x);
	REQUIRE(b1 -> world_transformation()[2].y == b2 -> world_transformation()[2].y);
	REQUIRE(b1 -> world_transformation()[2].z == b2 -> world_transformation()[2].z);
	REQUIRE(b1 -> world_transformation()[3].w == b2 -> world_transformation()[3].w);
	REQUIRE(b1 -> world_transformation()[3].x == b2 -> world_transformation()[3].x);
	REQUIRE(b1 -> world_transformation()[3].y == b2 -> world_transformation()[3].y);
	REQUIRE(b1 -> world_transformation()[3].z == b2 -> world_transformation()[3].z);

}

/* ------------------ Main ------------------ */

int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}

/* ------------------------------------------ */
