#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "DuplicatedShape.h"
#include "StackedShape.h"

class ShapeCalculator {
public:
    ShapeCalculator();
    void run();

private:
    void printShapesList() const;

    // --------------
    void handle_command(const std::string&);

    // --------------
    void create_shape(); // cre
    void enlargeOrReduse(int, double); // enlarging or redusing (en || red)
    void duplicate(int, int);
    void stack(int, int);
    void deleteItem(int);
    void draw(int); // draw
    void help() const; // help

    // ------------

    void modifyNestedShapes(std::shared_ptr<Shape>, std::shared_ptr<Shape>, double);

    std::vector<std::shared_ptr<Shape>> m_shapes;
    int m_arg1;
    int m_arg2;
};