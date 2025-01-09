#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Square.h" 

class Drawing {
private:
    std::vector<Shape*> shapes;

public:
    Drawing();
    ~Drawing();

    void add_front(Shape* shape);
    void add_back(Shape* shape);
    void print_all() const;
    double get_area_all_circles() const;
    void move_squares(double incX, double incY);
    -bool contains(const Shape* shape) const;
};

#endif

