#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
# include <glm/glm.hpp>
# include <glm/gtx/intersect.hpp> 

//Aufgabe 5.2
//Konstruktoren Tests, implizieren getter
TEST_CASE("Box Default Constructor", "[5.2]"){
  std::cout << "---------------------------------------\n";
  std::cout<< "5.2 geht los:" << std::endl;
  Box box{};
  REQUIRE(box.getMin().x == -1);
  REQUIRE(box.getMin().y == -1);
  REQUIRE(box.getMin().z == -1);
  REQUIRE(box.getMax().x == 1);
  REQUIRE(box.getMax().y == 1);
  REQUIRE(box.getMax().z == 1);
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Box Constructor", "[5.2]"){
  std::cout << "---------------------------------------\n";
  Box box{ "box", Color{0.0, 0.0, 0.0}, glm::vec3{-1,-2,0}, glm::vec3{1,1,4},};
  REQUIRE(box.getMin().x == -1);
  REQUIRE(box.getMin().y == -2);
  REQUIRE(box.getMin().z == -0);
  REQUIRE(box.getMax().x == 1);
  REQUIRE(box.getMax().y == 1);
  REQUIRE(box.getMax().z == 4);
  REQUIRE(box.getName() == "box");
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Sphere Default Constructor", "[5.2]"){
  std::cout << "---------------------------------------\n";
  Sphere sphere{};
  REQUIRE(sphere.getCenter().x == 0.0);
  REQUIRE(sphere.getCenter().y == 0.0);
  REQUIRE(sphere.getCenter().z == 0.0);
  REQUIRE(sphere.getRadius() == 1.0);
  REQUIRE(sphere.getName() == "");
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Sphere Constructor", "[5.2]"){
  std::cout << "---------------------------------------\n";
  Sphere sphere{"Coole Kugel", Color{0.0, 0.0, 0.0}, glm::vec3{-1,2,0}, 5.0,};
  REQUIRE(sphere.getCenter().x == -1.0);
  REQUIRE(sphere.getCenter().y == 2.0);
  REQUIRE(sphere.getCenter().z == 0.0);
  REQUIRE(sphere.getRadius() == 5.0);
  REQUIRE(sphere.getName() == "Coole Kugel");
  REQUIRE(sphere.getColor().r == 0.0);
  REQUIRE(sphere.getColor().g == 0.0);
  REQUIRE(sphere.getColor().b == 0.0);
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Box Area", "[5.2]"){
  std::cout << "---------------------------------------\n";
  Box box{};
  REQUIRE(box.area() == 24);

  Box box2{"box", Color{0.0, 0.0, 0.0}, glm::vec3{-1,-2,0}, glm::vec3{1,1,4}};
  //REQUIRE(box2.area() == 24);
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Box Volume", "[5.2]"){
  std::cout << "---------------------------------------\n";
  Box box{};
  REQUIRE(box.volume() == 8);

  Box box2{"box", Color{0.0, 0.0, 0.0}, glm::vec3{-1,-2,0}, glm::vec3{1,1,4}};
  //REQUIRE(box2.volume() == 8);
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Sphere Area", "[5.2]"){
  std::cout << "---------------------------------------\n";
  Sphere sphere{};
  REQUIRE(sphere.area() == Approx(12.56637f));

  Sphere sphere2{"Coole Kugel", Color{0.0, 0.0, 0.0}, glm::vec3{-1,2,0}, 5.0};
  //REQUIRE(sphere2.area() == Approx(12.56637f));
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Sphere Volume", "[5.2]"){
  std::cout << "---------------------------------------\n";
  Sphere sphere{};
  REQUIRE(sphere.volume() == Approx(4.18879f));

  Sphere sphere2{"Coole Kugel", Color{0.0, 0.0, 0.0}, glm::vec3{-1,2,0}, 5.0};
  //REQUIRE(sphere2.volume() == Approx(4.18879f));
  std::cout << "---------------------------------------\n";
}


//Aufgabe 5.5
TEST_CASE("Print Box", "[5.5]"){
  std::cout << "---------------------------------------\n";
  std::cout<< "5.5 geht los:" << std::endl;
  Box box2{"box", Color{0.0, 0.0, 0.0}, glm::vec3{-1,-2,0}, glm::vec3{1,1,4}};
  std::cout << box2;
  std::cout << "---------------------------------------\n";
}


TEST_CASE("Print Sphere", "[5.5]"){
  std::cout << "---------------------------------------\n";
  Sphere sphere2{"Coole Kugel", Color{0.0, 0.0, 0.0}, glm::vec3{-1,2,0}, 5.0};
  std::cout << sphere2;
  std::cout << "---------------------------------------\n";
}


//Aufgabe 5.6
TEST_CASE("intersectRaySphere", "[5.6]"){
  std::cout << "---------------------------------------\n";
  std::cout<< "5.6 geht los:" << std::endl;
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
  REQUIRE(distance == Approx(4.0));
  std::cout << "---------------------------------------\n";
}

TEST_CASE("Sphere method intersect", "[5.6]"){
  std::cout << "---------------------------------------\n";

  glm::vec3 ray_origin{0.0 ,0.0 ,-2.0};
  glm::vec3 ray_direction{0.0 ,0.0 ,2.5};

  glm::vec3 sphere_center{0.0 ,0.0 ,4.0};
  float sphere_radius{1.0};
  float distance{0.0};

  Ray ray{ray_origin, ray_direction};
  Sphere sphere{"Beautiful Sphere", Color{0.0, 0.0, 0.0}, sphere_center, sphere_radius};

  sphere.intersect(ray, distance);
  REQUIRE(distance == Approx(5.0));
  std::cout << "---------------------------------------\n";
}



//Aufgabe 5.8
TEST_CASE("Destructor", "[5.8]"){
  std::cout << "---------------------------------------\n";
  std::cout<< "5.8 geht los:" << std::endl;
  std::cout<<"Box Objekt anlegen:" << std::endl;
  Shape* s = new Box;
  std::cout << "Box wieder loeschen:" << std::endl;
  delete s;

  std::cout << "---------------------------------------\n";
  std::cout<< "das gleiche mit sphere:" << std::endl;
  std::cout<<"Sphere Objekt anlegen:" << std::endl;
  Shape* s2 = new Sphere;
  std::cout << "Sphere wieder loeschen:" << std::endl;
  delete s2;
  std::cout << "---------------------------------------\n";
}




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

