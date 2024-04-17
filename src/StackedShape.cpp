#include "StackedShape.h"

StackedShape::StackedShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2)
        : m_aboveShape(shape1->clone()),        // Cloning the first shape
          m_belowShape(shape2->clone()),        // Cloning the second shape
          m_firstAboveShape(shape1),            // Storing a pointer to the first shape
          m_firstBelowShape(shape2) {}          // Storing a pointer to the second shape

// ------------------------------------------------------------------
StackedShape::StackedShape(const StackedShape& other)
        : m_aboveShape(other.m_aboveShape->clone()),   // Cloning the above shape
          m_belowShape(other.m_belowShape->clone()),   // Cloning the below shape
          m_firstAboveShape(other.m_firstAboveShape),  // Copying the pointer to the first shape
          m_firstBelowShape(other.m_firstBelowShape) {}// Copying the pointer to the second shape


// ------------------------------------------------------------------
// Clone function to create a copy of the StackedShape object
std::shared_ptr<Shape> StackedShape::clone() const { return std::make_shared<StackedShape>(*this); }

// ------------------------------------------------------------------
// Function to print the name of the stacked shape
void StackedShape::nameOfShape() const {
    std::cout << "(";                 // Opening parenthesis
    m_aboveShape->nameOfShape();      // Print the name of the above shape
    std::cout << " / (";              // Print a separator before the below shape
    m_belowShape->nameOfShape();      // Print the name of the below shape
    std::cout << ")";                 // Closing parenthesis
}

// ------------------------------------------------------------------
// Function to draw the stacked shape multiple times
void StackedShape::draw(double times) const {
    for (size_t i = 0; i < times; i++) { // Repeat the drawing based on the given times
        m_aboveShape->draw(1);           // Draw the above shape
        m_belowShape->draw(1);           // Draw the below shape
    }
}

// ------------------------------------------------------------------
// Function to set a new size for the stacked shape
void StackedShape::setNewSize(double factor) {
    StackedShape stacked(*this);               // Create a duplicate of the current object
    stacked.m_aboveShape->setNewSize(factor);  // Set the new size for the above shape
    stacked.m_belowShape->setNewSize(factor);  // Set the new size for the below shape
    this->m_aboveShape = stacked.m_aboveShape; // Update the above shape pointer to the new duplicated above shape
    this->m_belowShape = stacked.m_belowShape; // Update the below shape pointer to the new duplicated below shape
}

// ------------------------------------------------------------------
// Function to get the pointer to the shape [above|below]
std::shared_ptr<Shape> StackedShape::getAboveShape() const { return m_firstAboveShape;}
std::shared_ptr<Shape> StackedShape::getBelowShape() const { return m_firstBelowShape; }

// ------------------------------------------------------------------
// Function to set the size of the shape [above|below]
void StackedShape::setSizeAbove(double factor) { m_aboveShape->setNewSize(factor); }
void StackedShape::setSizeBelow(double factor) { m_belowShape->setNewSize(factor); }

