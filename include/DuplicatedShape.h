#pragma once

#include "Shape.h"

class DuplicatedShape : public Shape { // DuplicatedShape class inherits from Shape class
public:
    DuplicatedShape(std::shared_ptr<Shape>, int);   // Constructor
    DuplicatedShape(const DuplicatedShape&);        // Copy constructor
    std::shared_ptr<Shape> clone() const override;  // Clone function
    void nameOfShape() const override;              // Function to get the name
    void draw(double) const override;               // Function to draw
    void setNewSize(double) override;               // Function to set a new size

    std::shared_ptr<Shape> getShape() const;        // Function to get the shape
    std::shared_ptr<Shape>getOriginalShape() const; // Function to get the original shape
    void setSize(double);                           // Function to set a new size for the original shape

private:
    std::shared_ptr<Shape> m_originalShape;
    int m_times;

    std::shared_ptr<Shape> m_firstOriginalShape;

};