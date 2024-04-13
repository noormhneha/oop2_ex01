#include "Rectangle.h"

void Rectangle::nameOfShape() const {
    std::cout << "Rectangle (w: " << m_width << ", h: " << m_height << ")";
}

void Rectangle::draw() const {
    for (size_t i = 0; i < m_height; i++) {
        for (size_t j = 0; j < m_width; j++) {
            std::cout << ((i == 0 || i == m_height - 1 || j == 0 || j == m_width - 1) ? '*' : ' ');
        }
        std::cout << std::endl;
    }
}

void Rectangle::setNewSize(double factor) { m_width *= factor; m_height *= factor; }