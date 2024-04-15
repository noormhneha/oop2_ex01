#include "StackedShape.h"

//std::shared_ptr<Shape> StackedShape::m_firstAboveShape = nullptr;
//std::shared_ptr<Shape> StackedShape::m_firstBelowShape = nullptr;

StackedShape::StackedShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2)
    : m_aboveShape(shape1),m_belowShape(shape2) {

    //m_firstAboveShape = shape1;
    //m_firstBelowShape = shape2;
}

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

//void StackedShape::containsSameShape(std::shared_ptr<Shape> pShape, double factor) {
//    // pShape and m_firstAboveShape point to the same object
//    if (compareAbove(pShape)) {
//        //m_aboveShape->setNewSize(factor);
//        (*m_firstAboveShape).setNewSize(factor);
//
//    }
//    // pShape and m_firstBelowShape point to the same object
//    else if (compareBelow(pShape)) {
//        //m_belowShape->setNewSize(factor);
//        (*m_firstBelowShape).setNewSize(factor);
//
//    }
//}
//
//bool StackedShape::compareAbove(std::shared_ptr<Shape> shape) {
//    return (m_firstAboveShape.get() == shape.get()) &&
//            m_firstAboveShape.use_count() > 1;
//}
//
//bool StackedShape::compareBelow(std::shared_ptr<Shape> shape) {
//    return (m_firstBelowShape.get() == shape.get()) && 
//            m_firstBelowShape.use_count() > 1;
//}
