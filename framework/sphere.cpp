
#include <iostream>
#include "sphere.hpp"
#include <cmath>
//5.2
//Constructors
Sphere::Sphere():
	Shape(),
	center_{0.0,0.0,0.0}, 
	radius_{1.0} {
		std::cout <<"sphere default constructor erstellt" << std::endl;
	}


Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& radius):
	Shape(name,color),	
	center_{center},
	radius_{radius}{
		std::cout << "sphere constructor erstellt" <<std::endl;
	}

Sphere::~Sphere(){
	std::cout <<"sphere destructor erstellt" <<std::endl;
}


//getter
glm::vec3 const& Sphere::getCenter() const{

	return center_;
}

float const& Sphere::getRadius() const{

	return radius_;
}

//Methoden
//area
float Sphere::area() const{
  return 4.0 * M_PI * radius_ * radius_;
}

//volume
float Sphere::volume() const{
  return ((4.0 * M_PI * pow(radius_, 3.0))/3.0);
}

//5.5
//überschreiben der Klasse print
std::ostream & Sphere::print(std::ostream & os) const{

	Shape::print(os);
	os<<"Center "		// glm::to_string(glm::vec3)
	<<center_.x<<", "
	<<center_.y<<", "
	<<center_.z<<"  Radius: "
	<<radius_<< ".";
}

//5.6
//intersect
bool Sphere::intersect(Ray const& ray, float& distance) const{
  return glm::intersectRaySphere(ray.origin_, ray.direction_,
          center_, radius_*radius_, distance);
}