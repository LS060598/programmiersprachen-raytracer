#include <iostream>
#include "box.hpp"

//5.2
//Constructor
//default constructor
    Box::Box():
		Shape(),
		min{0.0, 0.0, 0.0}, 
		max{0.0, 0.0, 0.0} {/*
			std::cout << "box default constructor erstellt" << std::endl;*/
		}


	Box::Box(std::string const& name, Color const& color, glm::vec3 const& min_, glm::vec3 const& max_):
		Shape(name,color),
		min{min_},
		max{max_} {/*
			std::cout << "box constructor erstellt" << std::endl; */
		}

	Box::~Box(){/*
		std::cout << "box destructor erstellt" << std::endl;*/
	}


//getter
	glm::vec3 const& Box::getMin() const
	{
		return min;
	}


	glm::vec3 const& Box::getMax() const
	{
		return max;
	}




//Methoden
//area
	float Box::area() const{
  		auto diff = max - min;
  		return 2*((diff.x*diff.y) + (diff.y*diff.z) + (diff.x*diff.z));
	}

//volume
	float Box::volume() const{
  		auto diff = max - min;
        return diff.x*diff.y*diff.z;
	}

//5.5
	std::ostream& Box::print(std::ostream & os) const{
		Shape::print(os);

		os<< "min "
		<<min.x<< ", "
		<<min.y<< ", "
		<<min.z<< ", " <<std::endl<< "max "
		<<max.x<< ", "
		<<max.y<< ", "
		<<max.z<< ". ";
	}
	

