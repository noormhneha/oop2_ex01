#include "Triangle.h"

void Triangle::nameOfShape() const {
    std::cout << "  Triangle(" << m_side << ")";
}

void Triangle::draw() const {
    std::cout << "noor";
}

void Triangle::setNewSize(double factor) { m_side *= factor; }