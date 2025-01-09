#include <iostream>
#include "Drawing.h"
#include "Circle.h
#include "Square.h"

int main() {
    Drawing drawing;
    Circle* circle = new Circle("blue", 5.0)
    Square* square = new Square("red", new Point2D[4]{Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)});

    drawing.add_back(circle);
    drawing.add_back(square);

    std::cout << "Contains circle: " << (drawing.contains(circle) ? "Yes" : "No") << std::endl;
    std::cout << "Contains square: " << (drawing.contains(square) ? "Yes" : "No") << std::endl;

    Circle* anotherCircle = new Circle("green", 3.0);
    std::cout << "Contains anotherCircle: " << (drawing.contains(anotherCircle) ? "Yes" : "No") << std::endl;

    delete anotherCircle;
    return 0;
}

