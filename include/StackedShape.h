#pragma once

#include "Shape.h"

class StackedShape : public Shape {
public:
    StackedShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2)
        : m_shape1(shape1), m_shape2(shape2) {}

    void nameOfShape() const override {
        std::cout << "  (";
        m_shape1->nameOfShape();
        std::cout << " / ";
        m_shape2->nameOfShape();
        std::cout << " )" << std::endl;
    }
    void draw() const override {
        m_shape1->draw();
        m_shape2->draw();
    }

    void setNewSize(double factor) override {
        m_shape1->setNewSize(factor);
        m_shape2->setNewSize(factor);
    }

private:
    std::shared_ptr<Shape> m_shape1;
    std::shared_ptr<Shape> m_shape2;
};