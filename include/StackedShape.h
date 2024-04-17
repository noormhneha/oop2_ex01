#pragma once

#include "Shape.h"

class StackedShape : public Shape { // StackedShape class inherits from Shape class
public:
    StackedShape(std::shared_ptr<Shape>, std::shared_ptr<Shape>);   // Constructor
    StackedShape(const StackedShape&);                              // Copy constructor
    std::shared_ptr<Shape> clone() const override;                  // Clone function
    void nameOfShape() const override;                              // Function to get the name
    void draw(double) const override;                               // Function to draw
    void setNewSize(double) override;                               // Function to set

    std::shared_ptr<Shape> getAboveShape() const;   // Function to get the shape abovr
    std::shared_ptr<Shape> getBelowShape() const;   // Function to get the shape below

    void setSizeAbove(double); // Function to set a new size
    void setSizeBelow(double); // Function to set a new size
private:
    std::shared_ptr<Shape> m_aboveShape;
    std::shared_ptr<Shape> m_belowShape;
       
    std::shared_ptr<Shape> m_firstAboveShape;
    std::shared_ptr<Shape> m_firstBelowShape;
};