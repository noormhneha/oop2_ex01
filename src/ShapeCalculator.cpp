#include "ShapeCalculator.h"

ShapeCalculator::ShapeCalculator() : m_arg1(0), m_arg2(0) {}

// ------------------------------------------------------------------
// creating shape { cre [t|r|s] x [y] }
void ShapeCalculator::create_shape() {
    char shape_type;
    std::cin >> shape_type >> m_arg1;
    switch (shape_type) {
    case 't': // Create a Triangle shape
        m_shapes.push_back(std::make_shared<Triangle>(m_arg1));
        break;
    case 'r': // Create a Rectangle shape
        std::cin >> m_arg2;
        m_shapes.push_back(std::make_shared<Rectangle>(m_arg1, m_arg2));
        break;
    case 's': // Create a Square shape
        m_shapes.push_back(std::make_shared<Square>(m_arg1));
        break;
    default:
        std::cout << "Unknown shape type" << std::endl;
        break;
    }
}

// ------------------------------------------------------------------
// Main function to run the ShapeCalculator
void ShapeCalculator::run() {
    std::cout << "Shape list is empty" << std::endl;
    while (true) { // Main loop
        printShapesList();
        std::cout << "Enter a command (type 'help' for assistance): ";
        std::string command;
        std::cin >> command; // Read user command
        if (command == "exit") { // Exit condition
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else { // Process user command
            handle_command(command);
        }
    }
}

// ------------------------------------------------------------------
// Function to handle user commands
void ShapeCalculator::handle_command(const std::string& command) {
    if (command == "cre") {
        create_shape();
    }
    else if (command == "en" || command == "red") { // Enlarge or reduce shape
        int item; double factor;
        std::cin >> item >> factor;
        if (factor >= 1 && factor <= 10) { // Check factor validity
            // (1 / factor) * x = x / factor [for reduse]
            command == "en" ? enlargeOrReduse(item, factor) : enlargeOrReduse(item, 1 / factor);
        }
    }
    else if (command == "draw") { // Draw shape
        int item;
        std::cin >> item; // Read shape index
        draw(item);
    }
    else if (command == "stack") {  // Stack shapes
        int lstItem1, lstItem2; 
        std::cin >> lstItem1 >> lstItem2;
        stack(lstItem1, lstItem2);
    }
    else if (command == "dup") { // Duplicate shape
        int lstItem, times;
        std::cin >> lstItem >> times;
        duplicate(lstItem, times);
    }
    else if (command == "del") { // Delete shape
        // delete pattern
        int lstItem;
        std::cin >> lstItem;
        deleteItem(lstItem);
    }
    else if (command == "help") { // Show help
        help();
    }
    else {
        std::cout << "Unknown command" << std::endl;
    }
}

// ------------------------------------------------------------------
// Function to duplicate a shape
void ShapeCalculator::duplicate(int lstItem, int times) {
    if (lstItem < static_cast<int>(m_shapes.size())) {
        if (times > 0) {
            auto dup_shape = std::make_shared<DuplicatedShape>(m_shapes[lstItem], times);
            m_shapes.push_back(dup_shape); // Add duplicated shape to list
        }
        else {
            std::cerr << "Error! Duplicate failed.";
        }
    }
}

// ------------------------------------------------------------------
// Function to stack shapes
void ShapeCalculator::stack(int lstItem1, int lstItem2) {
    if (lstItem1 <  static_cast<int>(m_shapes.size()) && lstItem2 < static_cast<int>(m_shapes.size())) {
        auto stacked_shape = std::make_shared<StackedShape>(m_shapes[lstItem1], m_shapes[lstItem2]);
        m_shapes.push_back(stacked_shape);
    }
}


// ------------------------------------------------------------------
// Function to delete a shape
void ShapeCalculator::deleteItem(int lstItem) {
    if (lstItem < static_cast<int>(m_shapes.size())) { m_shapes.erase(m_shapes.begin() + lstItem); }
}

// ------------------------------------------------------------------
// Function to draw a shape
void ShapeCalculator::draw(int lstItem){
    if (lstItem < static_cast<int>(m_shapes.size())) { m_shapes[lstItem]->draw(1); std::cout << std::endl; }
}

// ------------------------------------------------------------------
// Function to enlarge or reduce a shape
void ShapeCalculator::enlargeOrReduse(int lstItem, double factor) {
    if (lstItem < static_cast<int>(m_shapes.size())) {
        m_shapes[lstItem]->setNewSize(factor);
        if (m_shapes[lstItem].use_count() > 1) {
            for (auto& shape : m_shapes) { // Iterate through shapes
                modifyNestedShapes(shape, m_shapes[lstItem], factor); // Modify nested shapes
            }
        }
    }
}

// ------------------------------------------------------------------
// Function to modify sizes of nested shapes
void ShapeCalculator::modifyNestedShapes(const std::shared_ptr<Shape>& currentShape, std::shared_ptr<Shape> targetShape, double factor) {
    // Check if shape is a StackedShape
    if (auto stackedShapePtr = std::dynamic_pointer_cast<StackedShape>(currentShape)) {
        // Check if targetShape is above in stack
        if (stackedShapePtr->getAboveShape().get() == targetShape.get()) {
            stackedShapePtr->setSizeAbove(factor);
        }
        // Check if targetShape is below in stack
        else if (stackedShapePtr->getBelowShape().get() == targetShape.get()) {
            stackedShapePtr->setSizeBelow(factor);
        }
        else {
            // Recursively modify nested shapes
            modifyNestedShapes(stackedShapePtr->getAboveShape(), targetShape, factor);
            modifyNestedShapes(stackedShapePtr->getBelowShape(), targetShape, factor);
        }
    }
    // Check if shape is a DuplicatedShape
    else if (auto duplicatedShapePtr = std::dynamic_pointer_cast<DuplicatedShape>(currentShape)) {
        // Check if targetShape is the duplicated shape
        if (duplicatedShapePtr->getOriginalShape().get() == targetShape.get()) {
            duplicatedShapePtr->setSize(factor);
        }
        else {
            // Recursively modify nested shape
            modifyNestedShapes(duplicatedShapePtr->getShape(), targetShape, factor);
        }
    }
}

// ------------------------------------------------------------------
// Function to print the list of available shapes
void ShapeCalculator::printShapesList() const {
    if (!m_shapes.empty()) {
        std::cout << "List of the available shapes:" << std::endl;
        for (size_t i = 0; i < m_shapes.size(); ++i) {
            std::cout << i << ". \t";
            m_shapes[i]->nameOfShape();
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

// ------------------------------------------------------------------
// Function to display help information
void ShapeCalculator::help() {
    std::ifstream file("helper.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Error: Unable to open file 'helper.txt'" << std::endl;
    }
}