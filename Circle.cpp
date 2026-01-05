
#include "Circle.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

Circle::Circle() : Shape(), center(0,0), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {
    if (radius <= 0) throw std::invalid_argument("invalid radius");
}

Point2D Circle::get_center() const { return center; }
void Circle::set_center(Point2D p) { center = p; }

double Circle::get_radius() const { return radius; }
void Circle::set_radius(double r) {
    if (r <= 0) throw std::invalid_argument("invalid radius");
    radius = r;
}

double Circle::area() const { return 3.141592 * radius * radius; }
double Circle::perimeter() const { return 2.0 * 3.141592 * radius; }

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    std::cout << "[Circle: color = " << color
              << "; center = (" << center.x << "," << center.y << ")"
              << "; radius = " << radius << "]";
}

std::ostream& operator<<(std::ostream& out, const Circle& c) {
    Point2D p = c.get_center();
    out << "[Circle: color = " << c.get_color()
        << "; center = (" << p.x << "," << p.y << ")"
        << "; radius = " << c.get_radius() << "]";
    return out;
}
