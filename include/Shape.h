#pragma once

#include <iostream>

class Shape {
public:
    virtual std::shared_ptr<Shape> clone() const = 0;
    virtual void draw(double) const = 0;
    virtual void nameOfShape() const = 0;
    virtual void setNewSize(double) = 0;
    virtual ~Shape() {}
};