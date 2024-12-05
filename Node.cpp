#include "Node.hpp"
#include <iostream>

Node::Node(int keyValue) : key(keyValue), prev(nullptr), next(nullptr) {}

Node::~Node() {
    // Destructor logic if any additional cleanup is needed.
    // In this case, there is no dynamically allocated memory to clean up.
    // If extended in future, ensure proper cleanup.
}
