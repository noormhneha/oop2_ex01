#pragma once

#include <iostream>

class Shape {
public:
    virtual void draw(double) const = 0;
    //virtual void drawDupShape(double) = 0;
    virtual void nameOfShape() const = 0;
    virtual void setNewSize(double) = 0;
    virtual ~Shape() {}
};