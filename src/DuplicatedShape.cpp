#include "DuplicatedShape.h"

DuplicatedShape::DuplicatedShape(std::shared_ptr<Shape> original_shape, int times)
    : m_originalShape(original_shape->clone())
    , m_firstOriginalShape(original_shape)
    , m_times(times) {}

DuplicatedShape::DuplicatedShape(const DuplicatedShape& other)
    : m_originalShape(other.m_originalShape->clone())
    , m_firstOriginalShape(other.m_firstOriginalShape)
    , m_times(other.m_times) {}

std::shared_ptr<Shape> DuplicatedShape::clone() const { return std::make_shared<DuplicatedShape>(*this); }

void DuplicatedShape::nameOfShape() const {
    std::cout << m_times << " * (";
    m_originalShape->nameOfShape();
    std::cout << ")";
}

void DuplicatedShape::draw(double size) const { m_originalShape->draw(m_times); }

void DuplicatedShape::setNewSize(double factor) {
    DuplicatedShape duplicated(*this);
    duplicated.m_originalShape->setNewSize(factor);
    this->m_originalShape = duplicated.m_originalShape;
}

std::shared_ptr<Shape> DuplicatedShape::getShape() const { return m_originalShape; }
void DuplicatedShape::setSize(double factor) { m_originalShape->setNewSize(factor); }
