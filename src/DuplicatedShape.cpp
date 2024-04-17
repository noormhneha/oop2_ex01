#include "DuplicatedShape.h"

DuplicatedShape::DuplicatedShape(std::shared_ptr<Shape> original_shape, int times)
        : m_originalShape(original_shape->clone()), // Cloning the original shape
          m_firstOriginalShape(original_shape),     // Storing a pointer to the original shape
          m_times(times) {}                         // Storing the number of times to duplicate

// ------------------------------------------------------------------
DuplicatedShape::DuplicatedShape(const DuplicatedShape& other)
        : m_originalShape(other.m_originalShape->clone()), // Cloning the original shape
          m_firstOriginalShape(other.m_firstOriginalShape), // Copying the pointer to the original shape
          m_times(other.m_times) {}                        // Copying the number of times to duplicate

// ------------------------------------------------------------------
// Clone function to create a copy of the DuplicatedShape object
std::shared_ptr<Shape> DuplicatedShape::clone() const { return std::make_shared<DuplicatedShape>(*this); }

// ------------------------------------------------------------------
// Function to print the name of the shape and the number of times it's duplicated
void DuplicatedShape::nameOfShape() const {
    std::cout << m_times << " * (";       // Print the duplication factor
    m_originalShape->nameOfShape();       // Print the name of the original shape
    std::cout << ")";                     // Closing parenthesis
}

// ------------------------------------------------------------------
// Function to draw the shape multiple times
void DuplicatedShape::draw(double size) const { m_originalShape->draw(m_times); }

// ------------------------------------------------------------------
// Function to set a new size for the shape
void DuplicatedShape::setNewSize(double factor) {
    DuplicatedShape duplicated(*this);                   // Create a duplicate of the current object
    duplicated.m_originalShape->setNewSize(factor);      // Set the new size for the duplicated shape
    this->m_originalShape = duplicated.m_originalShape;  // Update the original shape pointer to the new duplicated shape
}

// ------------------------------------------------------------------
// Function to get the original shape
std::shared_ptr<Shape> DuplicatedShape::getShape() const { return m_originalShape; }
std::shared_ptr<Shape> DuplicatedShape::getOriginalShape() const { return m_firstOriginalShape; }

// ------------------------------------------------------------------
// Function to set the size of the shape
void DuplicatedShape::setSize(double factor) { m_originalShape->setNewSize(factor); }