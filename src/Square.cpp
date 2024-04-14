#include "Square.h"

void Square::nameOfShape() const {
    std::cout << "  Square(" << m_side << ")";
}

void Square::draw(double size) const {
    for (size_t i = 0; i < m_side; i++) {
        for (size_t count = 0; count < size; count++) {
            for (size_t j = 0; j < m_side; j++) {
                std::cout << ((i == 0 || i == m_side - 1 || j == 0 || j == m_side - 1) ? '*' : ' ');
            }
        }
        std::cout << std::endl;
    }
}

void Square::setNewSize(double factor) { m_side *= factor; }

