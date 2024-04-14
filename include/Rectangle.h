#pragma once

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : m_width(w), m_height(h) {}
    void nameOfShape() const override;
    void draw(double) const override;

    void setNewSize(double) override;
private:
    int m_width, m_height;
};