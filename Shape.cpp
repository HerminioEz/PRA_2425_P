#include "Shape.h"

void Shape::validate_color(const std::string& c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Invalid color");
    }
}

Shape::Shape() : color("red") {}

Shape::Shape(const std::string& color) {
    validate_color(color);
    this->color = color;
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(const std::string& c) {
    validate_color(c);
    color = c;
}

