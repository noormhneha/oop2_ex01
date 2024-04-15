#pragma once

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int, int);
    Rectangle(const Rectangle&);
    std::shared_ptr<Shape> clone() const override;
    void nameOfShape() const override;
    void draw(double) const override;
    void setNewSize(double) override;

private:
    int m_width, m_height;
};