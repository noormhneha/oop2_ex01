#include "Rectangle.h"

Rectangle::Rectangle(int w, int h) : m_width(w), m_height(h) {}

// ------------------------------------------------------------------
Rectangle::Rectangle(const Rectangle& other) : m_width(other.m_width), m_height(other.m_height) {}

// ------------------------------------------------------------------
// Clone function to create a copy of the Rectangle object
std::shared_ptr<Shape> Rectangle::clone() const { return std::make_shared<Rectangle>(*this); }

// ------------------------------------------------------------------
// Function to get the name of the shape (Rectangle)
void Rectangle::nameOfShape() const { std::cout << "Rectangle (w: " << m_width << ", h: " << m_height << ")"; }

// ------------------------------------------------------------------
// Function to draw the Rectangle shape
void Rectangle::draw(double size) const {
    for (size_t i = 0; i < m_height; i++) {
        for (size_t count = 0; count < size; count++) {
            for (size_t j = 0; j < m_width; j++) {
                std::cout << ((i == 0 || i == m_height - 1 || j == 0 || j == m_width - 1) ? '*' : ' ');
            }
        }
        std::cout << std::endl;
    }
}

// ------------------------------------------------------------------
// Function to set a new size for the Rectangle
void Rectangle::setNewSize(double factor) { m_width *= factor; m_height *= factor; }