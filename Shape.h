#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include <iostream>

class Shape {
protected:
    std::string color;

    void validate_color(const std::string& c);

public:
    Shape();
    Shape(const std::string& color);

    std::string get_color() const;
    void set_color(const std::string& c);

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() const = 0;

    virtual ~Shape() {}
};

#endif

