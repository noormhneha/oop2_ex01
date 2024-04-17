#pragma once

#include "Shape.h"

class Square : public Shape {
public:
    Square(int);                                    // Constructor
    Square(const Square&);                          // Copy constructor
    std::shared_ptr<Shape> clone() const override;  // Clone function
    void nameOfShape() const override;              // Function to get the name
    void draw(double) const override;               // Function to draw 
    void setNewSize(double) override;               // Function to set a new size

private:
    int m_side;
};