
#include "Shape.h"
#include <stdexcept>

bool Shape::valid_color(const std::string& c) {
    return c == "red" || c == "green" || c == "blue";
}

Shape::Shape() : color("red") {}

Shape::Shape(std::string c) : color(c) {
    if (!valid_color(color)) throw std::invalid_argument("invalid color");
}

std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(std::string c) {
    if (!valid_color(c)) throw std::invalid_argument("invalid color");
    color = c;
}

