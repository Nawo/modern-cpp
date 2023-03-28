#include "Shape.hpp"

std::ostream& operator<<(std::ostream& os, Color c) {
    if (c == Color::RED) {
        os << "RED";
    } else if (c == Color::BLUE) {
        os << "BLUE";
    } else if (c == Color::GREEN) {
        os << "GREEN";
    }
    return os;
}

Shape::Shape() {
}

Shape::Shape(Color c)
    : color(c) {
}

void Shape::print() const {
    std::cout << "Unknown Shape" << std::endl;
}

Shape::~Shape() {
}