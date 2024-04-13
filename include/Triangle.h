#pragma once

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(int s) : m_side(s) {}
    void nameOfShape() const override;
    void draw() const override;

    void setNewSize(double) override;
private:
    int m_side;
};