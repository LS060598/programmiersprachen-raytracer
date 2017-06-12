/*
#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>


class Sphere : public Shape{


    public:
        glm::vec3 getCenter() const;
	    float getRadius() const;
	    double area() const override;
        double volume() const override;




    private:
    glm::vec3 center_;
    float rad_;
};
#endif
*/