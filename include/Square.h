#pragma once

#include "Shape.h"

class Square : public Shape {
public:
    Square(int s) : m_side(s) {}
    void nameOfShape() const override;
    void draw(double) const override;

    void setNewSize(double) override;
private:
    int m_side;
};