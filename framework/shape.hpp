#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

class Shape{
    
    public:
    /*
        Color const& getcolor() const;
        std::string const& getname() const;    
        */    
        virtual float area() const = 0; 
        virtual float volume() const = 0;




    private: /*
        Color color_;
        std::string name_;
*/
};
#endif