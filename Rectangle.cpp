#include "Rectangle.h"
#include <stdexcept>
#include <iostream>

bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    return d01 == d23 && d12 == d30;
}

Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]) {
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    if (!check(vertices)) { delete[] vs; throw std::invalid_argument("invalid vertices"); }
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.color), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];
}

Rectangle::~Rectangle() { delete[] vs; }

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) throw std::out_of_range("index");
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    if (ind < 0 || ind >= N_VERTICES) throw std::out_of_range("index");
    return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("invalid vertices");
    for (int i = 0; i < N_VERTICES; ++i) vs[i] = vertices[i];
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        color = r.color;
        for (int i = 0; i < N_VERTICES; ++i) vs[i] = r.vs[i];
    }
    return *this;
}

double Rectangle::area() const {
    double d01 = Point2D::distance(vs[0], vs[1]);
    double d12 = Point2D::distance(vs[1], vs[2]);
    return d01 * d12;
}

double Rectangle::perimeter() const {
    double d01 = Point2D::distance(vs[0], vs[1]);
    double d12 = Point2D::distance(vs[1], vs[2]);
    return 2.0 * (d01 + d12);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << "[Rectangle: color = " << color
              << "; v0 = (" << vs[0].x << "," << vs[0].y << ")"
              << "; v1 = (" << vs[1].x << "," << vs[1].y << ")"
              << "; v2 = (" << vs[2].x << "," << vs[2].y << ")"
              << "; v3 = (" << vs[3].x << "," << vs[3].y << ")]";
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    Point2D v0 = r.get_vertex(0);
    Point2D v1 = r.get_vertex(1);
    Point2D v2 = r.get_vertex(2);
    Point2D v3 = r.get_vertex(3);
    out << "[Rectangle: color = " << r.get_color()
        << "; v0 = (" << v0.x << "," << v0.y << ")"
        << "; v1 = (" << v1.x << "," << v1.y << ")"
        << "; v2 = (" << v2.x << "," << v2.y << ")"
        << "; v3 = (" << v3.x << "," << v3.y << ")]";
    return out;
}
