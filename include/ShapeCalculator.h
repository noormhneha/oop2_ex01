#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>

#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "DuplicateShape.h"
#include "StackedShape.h"

class ShapeCalculator {
public:
    ShapeCalculator() : m_arg1(0), m_arg2(0) {};
    void run();
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

private:
    std::vector<std::shared_ptr<Shape>> m_shapes;
    int m_arg1;
    int m_arg2;
};