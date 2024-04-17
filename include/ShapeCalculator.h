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
    ShapeCalculator(); // constructor
    void run();

private:
    void printShapesList() const; // the shape in the list
    // --------------
    // cammands
    void handle_command(const std::string&);
    void create_shape(); // create
    void enlargeOrReduse(int, double); // enlarging or redusing (en || red)
    void duplicate(int, int); // duplicate
    void stack(int, int); // stack
    void deleteItem(int); // deleter
    void draw(int); // draw
    static void help() ; // help

    // ------------
    // recursion
    void modifyNestedShapes(const std::shared_ptr<Shape>&, std::shared_ptr<Shape>, double);

    std::vector<std::shared_ptr<Shape>> m_shapes;
    int m_arg1;
    int m_arg2;
};