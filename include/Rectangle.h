#pragma once

#include "Shape.h"

class Rectangle : public Shape { // Rectangle class inherits from Shape class
public:
    Rectangle(int, int);                            // Constructor 
    Rectangle(const Rectangle&);                    // Copy constructor
    std::shared_ptr<Shape> clone() const override;  // Clone function
    void nameOfShape() const override;              // Function to get the name
    void draw(double) const override;               // Function to draw
    void setNewSize(double) override;               // Function to set a new size

private:
    int m_width, m_height;
};