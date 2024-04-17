#pragma once

#include "Shape.h"

class Triangle : public Shape {                    /* Triangle class inherits from Shape class */
public:
    Triangle(int);                                 // Constructor to initialize a Triangle
    Triangle(const Triangle&);                     // Copy constructor
    std::shared_ptr<Shape> clone() const override; // Clone function
    void nameOfShape() const override;             // Function to get the name
    void draw(double) const override;              // Function to draw
    void setNewSize(double) override;              // Function to set a new size

private:
    int m_side; // Side length
};