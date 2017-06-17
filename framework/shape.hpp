#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"
#include <glm/vec3.hpp>

class Shape{
    
    public:
        //5.2
        Shape();
        Shape(std::string const& name, Color const& color);
        /*virtual*/~Shape();
    
        Color getColor() const;
        std::string getName() const; 

         //5.1  
        virtual float area() const = 0; 
        virtual float volume() const = 0;

        virtual std::ostream & print (std::ostream & os) const;
        
        



    private: 
        Color color_;
        std::string name_;

};
std::ostream & operator <<(std::ostream & os, Shape const& s);// oder vor endif???
#endif