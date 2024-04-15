#include "ShapeCalculator.h"

ShapeCalculator::ShapeCalculator() : m_arg1(0), m_arg2(0) {}

void ShapeCalculator::create_shape() {
    char shape_type;
    std::cin >> shape_type >> m_arg1;
    switch (shape_type) {
    case 't':
        m_shapes.push_back(std::make_shared<Triangle>(m_arg1));
        break;
    case 'r':
        std::cin >> m_arg2;
        m_shapes.push_back(std::make_shared<Rectangle>(m_arg1, m_arg2));
        break;
    case 's':
        m_shapes.push_back(std::make_shared<Square>(m_arg1));
        break;
    default:
        std::cout << "Unknown shape type" << std::endl;
        break;
    }
}

void ShapeCalculator::run() {
    std::cout << "Shape list is empty" << std::endl;
    while (true) {
        printShapesList();
        std::cout << "Enter a command (type 'help' for assistance): ";
        std::string command;
        std::cin >> command;
        if (command == "exit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            handle_command(command);
        }
    }
}

void ShapeCalculator::handle_command(const std::string& command) {
    if (command == "cre") {
        create_shape();
    }
    else if (command == "en" || command == "red") {
        int item; double factor;
        std::cin >> item >> factor;
        if (factor >= 1 && factor <= 10) {
            command == "en" ? enlargeOrReduse(item, factor) : enlargeOrReduse(item, 1 / factor);
            // (1 / factor) * x = x / factor 
        }
    }
    else if (command == "draw") {
        int item;
        std::cin >> item;
        draw(item);
    }
    else if (command == "stack") {
        int lstItem1, lstItem2;
        std::cin >> lstItem1 >> lstItem2;
        stack(lstItem1, lstItem2);
    }
    else if (command == "dup") {
        int lstItem, times;
        std::cin >> lstItem >> times;
        duplicate(lstItem, times);
    }
    else if (command == "del") {
        // delete pattern
        int lstItem;
        std::cin >> lstItem;
        deleteItem(lstItem);
    }
    else if (command == "help") {
        help();
    }
    else {
        std::cout << "Unknown command" << std::endl;
    }
}


void ShapeCalculator::duplicate(int lstItem, int times) {
    if (lstItem < m_shapes.size()) {
        if (times > 0) {
            auto dup_shape = std::make_shared<DuplicatedShape>(m_shapes[lstItem], times);
            m_shapes.push_back(dup_shape);
        }
        else {
            std::cerr << "Error! Duplicate failed.";
        }
    }
}

void ShapeCalculator::stack(int lstItem1, int lstItem2) {
    if (lstItem1 < m_shapes.size() && lstItem2 < m_shapes.size()) {
        auto stacked_shape = std::make_shared<StackedShape>(m_shapes[lstItem1], m_shapes[lstItem2]);
        m_shapes.push_back(stacked_shape);
    }
}

void ShapeCalculator::deleteItem(int lstItem) {
    if (lstItem < m_shapes.size()) {
        /*m_shapes[lstItem].reset();*/
        m_shapes.erase(m_shapes.begin() + lstItem);
    }
}

void ShapeCalculator::draw(int lstItem){
    if (lstItem < m_shapes.size()) { m_shapes[lstItem]->draw(1); std::cout << std::endl; }
}

void ShapeCalculator::enlargeOrReduse(int lstItem, double factor) {
    if (lstItem < m_shapes.size()) { 
        m_shapes[lstItem]->setNewSize(factor); 
        //StackedShape::containsSameShape(m_shapes[lstItem], factor);
    }
}


void ShapeCalculator::printShapesList() const {
    if (!m_shapes.empty()) {
        std::cout << "List of the availble shapes:" << std::endl;
        for (size_t i = 0; i < m_shapes.size(); ++i) {
            std::cout << i << ". \t";
            m_shapes[i]->nameOfShape();
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void ShapeCalculator::help() const {
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