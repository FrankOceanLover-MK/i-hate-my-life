#include "HashNode.hpp"

HashNode::HashNode(int value) : Node(value), cacheNode(nullptr) {
    // Initialization of HashNode
}

HashNode::HashNode(int value, Node* newCacheNode) : Node(value), cacheNode(newCacheNode) {
    // Initialization of HashNode
}

