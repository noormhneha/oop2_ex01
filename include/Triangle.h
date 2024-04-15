#pragma once

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(int);
    Triangle(const Triangle&);
    std::shared_ptr<Shape> clone() const override;
    void nameOfShape() const override;
    void draw(double) const override;
    void setNewSize(double) override;

private:
    int m_side;
};