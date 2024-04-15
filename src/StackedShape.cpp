#include "StackedShape.h"

StackedShape::StackedShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2)
    : m_aboveShape(shape1)/*->clone())*/, m_belowShape(shape2)/*->clone())*/ {}

StackedShape::StackedShape(const StackedShape& other) 
    : m_aboveShape(other.m_aboveShape->clone()), m_belowShape(other.m_belowShape->clone()) {}

std::shared_ptr<Shape> StackedShape::clone() const { return std::make_shared<StackedShape>(*this); }

void StackedShape::nameOfShape() const {
    std::cout << "(";
    m_aboveShape->nameOfShape();
    std::cout << " / (";
    m_belowShape->nameOfShape();
    std::cout << ")";
}

void StackedShape::draw(double times) const {
    for (size_t i = 0; i < times; i++) {
        m_aboveShape->draw(1);
        m_belowShape->draw(1);
    }
}

void StackedShape::setNewSize(double factor) {
    auto shape1(m_aboveShape->clone());
    auto shape2(m_belowShape->clone());
    shape1->setNewSize(factor);
    shape2->setNewSize(factor);
    m_aboveShape = shape1;
    m_belowShape = shape2;
}