#pragma once

#include "Shape.h"

class StackedShape : public Shape {
public:
    StackedShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2)
        : m_shape1(shape1), m_shape2(shape2) {}

    void draw() const override {
        m_shape1->draw();
        m_shape2->draw();
        std::cout << "Shapes stacked." << std::endl;
    }

private:
    std::shared_ptr<Shape> m_shape1;
    std::shared_ptr<Shape> m_shape2;
};