#pragma once

#include "Shape.h"

class Square : public Shape {
public:
    Square(int);
    Square(const Square&);
    std::shared_ptr<Shape> clone() const override;
    void nameOfShape() const override;
    void draw(double) const override;
    void setNewSize(double) override;

private:
    int m_side;
};