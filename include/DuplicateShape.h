#pragma once

#include "Shape.h"

class DuplicatedShape : public Shape {
public:
    DuplicatedShape(std::shared_ptr<Shape> original_shape, int times)
        : m_originalShape(original_shape), m_times(times) {}

    void nameOfShape() const override {
        std::cout << "  " << m_times << " * (";
        m_originalShape->nameOfShape();
        std::cout << " )" << std::endl;
    }
    void draw() const override {
        for (int i = 0; i < m_times; ++i) {
            m_originalShape->draw();
        }
    }

    void setNewSize(double factor) override {
        m_originalShape->setNewSize(factor);
    }

private:
    std::shared_ptr<Shape> m_originalShape;
    int m_times;
};