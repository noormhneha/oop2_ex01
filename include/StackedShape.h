#pragma once

#include "Shape.h"

class StackedShape : public Shape {
public:
    StackedShape(std::shared_ptr<Shape>, std::shared_ptr<Shape>);
    StackedShape(const StackedShape&);
    std::shared_ptr<Shape> clone() const override;
    void nameOfShape() const override;
    void draw(double) const override;
    void setNewSize(double) override;

    //static void containsSameShape(std::shared_ptr<Shape>, double);

    //static bool compareAbove(std::shared_ptr<Shape>);

    //static bool compareBelow(std::shared_ptr<Shape>);

private:
    std::shared_ptr<Shape> m_aboveShape;
    std::shared_ptr<Shape> m_belowShape;

    //static std::shared_ptr<Shape> m_firstAboveShape;
    //static std::shared_ptr<Shape> m_firstBelowShape;

};