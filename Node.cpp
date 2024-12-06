/**
* 
* Mohit Kumar
* Arpan Rakeshbhai
* 12/04/2024
* 
* 
* Node.cpp : Implements the Node struct, which provides the basic structure for a doubly
* linked list. This file includes the constructor to initialize a node with a key 
* and default `prev` and `next` pointers, as well as a destructor for cleanup.
* 
* 12/03/2024 - Created by Mohit Kumar and Arpan Rakeshbhai
* 
* 
*/

#include "Node.hpp"
#include <iostream>


/*  Node Constructor

Initializes a Node with the given key value. Sets the `prev` and `next` pointers
to nullptr by default, indicating that the node is not linked to any other nodes.

*/
Node::Node(int keyValue) : key(keyValue), prev(nullptr), next(nullptr) {}



// Node Destructor

Node::~Node() {
    // Destructor logic if any additional cleanup is needed.
    // In this case, there is no dynamically allocated memory to clean up.
    // If extended in the future, ensure proper cleanup.
}
