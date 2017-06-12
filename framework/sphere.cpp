/*
#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include <iostream>

//destructor
Sphere::Sphere():
	Shape(),
	center_{0.0,0.0,0.0},
	radius_{0.0},

//getter
glm::vec3 Sphere::getCenter() const{

	return center_;
}

float Sphere::getRadius() const{

	return radius_;
}

//Methoden
//area
float Sphere::area() const{

	return 4*M_PI*radius_*radius_;
}


//volume
float Sphere::volume() const{

	return (4/3)*M_PI*radius_*radius_*radius_;
}
*/