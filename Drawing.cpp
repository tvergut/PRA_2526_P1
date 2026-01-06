
#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

Drawing::Drawing() : shapes(new ListArray<Shape*>) {}

Drawing::~Drawing() { delete shapes; }

void Drawing::add_front(Shape* shape) { shapes->prepend(shape); }

void Drawing::add_back(Shape* shape) { shapes->append(shape); }

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        s->print();
        std::cout << "\n";
    }
}

double Drawing::get_area_all_circles() {
    double acc = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (auto c = dynamic_cast<Circle*>(s)) acc += c->area();
    }
    return acc;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        if (auto q = dynamic_cast<Square*>(s)) q->translate(incX, incY);
    }
}

