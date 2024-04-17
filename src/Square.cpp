#include "Square.h"

Square::Square(int s) : m_side(s) {}

// ------------------------------------------------------------------
Square::Square(const Square& other) : m_side(other.m_side) {}

// ------------------------------------------------------------------
// Clone function to create a copy of the Square object
std::shared_ptr<Shape> Square::clone() const { return std::make_shared<Square>(*this); }

// ------------------------------------------------------------------
// Function to print the name of the square shape
void Square::nameOfShape() const { std::cout << "Square(" << m_side << ")"; }

// ------------------------------------------------------------------
// Function to draw the square shape
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

// ------------------------------------------------------------------
// Function to set a new size for the square shape
void Square::setNewSize(double factor) { m_side *= factor; }

