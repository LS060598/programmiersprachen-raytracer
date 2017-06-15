#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include "shape.hpp"
#include <string>
#include <cmath>

class Box: public Shape{
public:
	Box();
	Box(glm::vec3 min, glm::vec3 max);
	/*
	Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);
	*/
	~Box();
	glm::vec3 const& getMin() const;
	glm::vec3 const& getMax() const;
	float area() const /*override*/;
	float volume() const /*override*/;
	/*
	std::ostream & print (std::ostream & os) const override;
*/

private:
	glm::vec3 min;
	glm::vec3 max;
};


#endif

