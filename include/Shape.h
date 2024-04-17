#pragma once

#include <iostream>

class Shape {
public:
    // Pure virtual functions
    virtual std::shared_ptr<Shape> clone() const = 0;
    virtual void draw(double) const = 0;
    virtual void nameOfShape() const = 0;
    virtual void setNewSize(double) = 0;

    // Virtual destructor
    virtual ~Shape() {}
};