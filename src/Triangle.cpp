#include "Triangle.h"

Triangle::Triangle(int s) : m_side(s) {}
Triangle::Triangle(const Triangle& other) : m_side(other.m_side) {}

std::shared_ptr<Shape> Triangle::clone() const { return std::make_shared<Triangle>(*this); }

void Triangle::nameOfShape() const {
    std::cout << "Triangle(" << m_side << ")";
}

void Triangle::draw(double size) const {
    int spaces = m_side - 1;
    for (int i = 0; i < m_side; ++i) {
        for (size_t count = 0; count < size; count++) {
            for (int j = 0; j < spaces; ++j) {
                std::cout << " ";
            }
            for (int j = 0; j < (2 * i + 1); ++j) {
                std::cout << ((j == 0 || j == i * 2 || i == m_side - 1) ? "*" : " ");
            }
            for (int j = 0; j < spaces; ++j) {
                std::cout << " ";
            }
        }
        std::cout << std::endl; // Move to the next row
        --spaces;
    }
}

void Triangle::setNewSize(double factor) { 
    m_side *= factor; 
}