#pragma once

#include "Shape.h"

class DuplicatedShape : public Shape {
public:
    DuplicatedShape(std::shared_ptr<Shape>, int);
    DuplicatedShape(const DuplicatedShape&);
    std::shared_ptr<Shape> clone() const override;
    void nameOfShape() const override;
    void draw(double) const override;
    void setNewSize(double) override;

    std::shared_ptr<Shape> getShape() const;
    void setSize(double);

private:
    std::shared_ptr<Shape> m_originalShape;
    int m_times;

    std::shared_ptr<Shape> m_firstOriginalShape;

};