#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include "shape.hpp"
#include <string>
#include <cmath>
#include <glm/vec3.hpp>
#include "ray.hpp"
# include <glm/gtx/intersect.hpp> 

class Sphere: public Shape{
public:
	Sphere();
	Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& radius);
	
	~Sphere();
	glm::vec3 const& getCenter() const;
	float const& getRadius() const;
	float area() const override;
	float volume() const override;
	
	std::ostream & print (std::ostream & os) const override;
	
	bool intersect(Ray const& ray, float& distance) const;

private:
	glm::vec3 center_;
	float radius_;

};

#endif
