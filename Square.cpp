
#include "Square.h"
#include <stdexcept>
#include <iostream>

static double d(const Point2D& a, const Point2D& b) { return Point2D::distance(a,b); }

bool Square::check(Point2D* vertices) {
    double d01 = d(vertices[0], vertices[1]);
    double d12 = d(vertices[1], vertices[2]);
    double d23 = d(vertices[2], vertices[3]);
    double d30 = d(vertices[3], vertices[0]);
    return d01 == d12 && d01 == d23 && d01 == d30;
}

Square::Square() : Rectangle() {
    Point2D verts[Rectangle::N_VERTICES] = { Point2D(-1,1), Point2D(1,1), Point2D(1,-1), Point2D(-1,-1) };
    set_vertices(verts);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) throw std::invalid_argument("invalid vertices");
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) throw std::invalid_argument("invalid vertices");
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) vs[i] = vertices[i];
}

void Square::print() {
    std::cout << "[Square: color = " << color
              << "; v0 = (" << vs[0].x << "," << vs[0].y << ")"
              << "; v1 = (" << vs[1].x << "," << vs[1].y << ")"
              << "; v2 = (" << vs[2].x << "," << vs[2].y << ")"
              << "; v3 = (" << vs[3].x << "," << vs[3].y << ")]";
}

std::ostream& operator<<(std::ostream& out, const Square& s) {
    out << "[Square: color = " << s.get_color()
        << "; v0 = (" << s.get_vertex(0).x << "," << s.get_vertex(0).y << ")"
               << "; v1 = (" << s.get_vertex(1).x << "," << s.get_vertex(1).y << ")"
        << "; v2 = (" << s.get_vertex(2).x << "," << s.get_vertex(2).y << ")"
        << "; v3 = (" << s.get_vertex(3).x << "," << s.get_vertex(3).y << ")]";
    return out;
}
