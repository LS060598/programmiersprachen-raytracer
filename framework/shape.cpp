#include "shape.hpp"
#include <cmath>
#include <iostream>

//5.3
//Konstruktoren
Shape::Shape():
	name_{""},
    color_{0.0,0.0,0.0,} {}

Shape::Shape(std::string const&  name, Color const& color):
	name_{name},
    color_{color} {}

Shape::~Shape(){}



//getter
Color Shape::getColor() const{
	return color_;
}

std::string Shape::getName() const{
	return name_;
}

/*
//5.4
//Ausgabe von Objekten des Typs Shape
std::ostream & Shape::print(std::ostream & os) const{
	os << name_ << std::endl << color_ ; 
	return os; //gibt Name & Farbe zurueck
}

// Überladen des Stream-Operators <<
std::ostream & operator <<(std::ostream & os, Shape const& s){
	return s.print(os);
}
*/