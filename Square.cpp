#include "Square.h"
#include <iostream>
#include <cmath>

Square::Square() : Rectangle("red", new Point2D[N_VERTICES]{
    Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)
}) {}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for a square");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for a square");
    }
    Rectangle::set_vertices(vertices);
}

void Square::print() const {
    std::cout << "Square color: " << get_color() << ", vertices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << vs[i] << " ";
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    square.print();
    return out;
}

bool Square::check(Point2D* vertices) {
    double side1 = Point2D::distance(vertices[0], vertices[1]);
    double side2 = Point2D::distance(vertices[1], vertices[2]);
    double side3 = Point2D::distance(vertices[2], vertices[3]);
    double side4 = Point2D::distance(vertices[3], vertices[0]);
    return (side1 == side2) && (side2 == side3) && (side3 == side4);
}

