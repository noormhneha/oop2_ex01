#include "StackedShape.h"

StackedShape::StackedShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2)
    : m_aboveShape(shape1->clone())
    , m_belowShape(shape2->clone())
    , m_firstAboveShape(shape1)
    , m_firstBelowShape(shape2) {}

StackedShape::StackedShape(const StackedShape& other) 
    : m_aboveShape(other.m_aboveShape->clone())
    , m_belowShape(other.m_belowShape->clone())
    , m_firstAboveShape(other.m_firstAboveShape)
    , m_firstBelowShape(other.m_firstBelowShape) {}

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
    StackedShape stacked(*this);
    stacked.m_aboveShape->setNewSize(factor);
    stacked.m_belowShape->setNewSize(factor);
    this->m_aboveShape = stacked.m_aboveShape;
    this->m_belowShape = stacked.m_belowShape;
}

std::shared_ptr<Shape> StackedShape::getAboveShape() const { return m_firstAboveShape;}
std::shared_ptr<Shape> StackedShape::getBelowShape() const { return m_firstBelowShape; }
void StackedShape::setSizeAbove(double factor) { m_aboveShape->setNewSize(factor); }
void StackedShape::setSizeBelow(double factor) { m_belowShape->setNewSize(factor); }

