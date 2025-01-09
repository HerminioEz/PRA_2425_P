#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : Shape("red"), vs(new Point2D[N_VERTICES]) {
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for a rectangle");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

double Rectangle::area() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return width * height;
}

double Rectangle::perimeter() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2 * (width + height);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() const {
    std::cout << "Rectangle color: " << get_color() << ", vertices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << vs[i] << " ";
    }
    std::cout << std::endl;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Index out of range");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for a rectangle");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        Shape::operator=(r);
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    r.print();
    return out;
}

bool Rectangle::check(Point2D* vertices) {
    double width1 = Point2D::distance(vertices[0], vertices[1]);
    double width2 = Point2D::distance(vertices[2], vertices[3]);
    double height1 = Point2D::distance(vertices[1], vertices[2]);
    double height2 = Point2D::distance(vertices[3], vertices[0]);
    return (width1 == width2) && (height1 == height2);
}

