/**
* 
* Mohit Kumar
* Arpan Rakeshbhai
* 12/03/2024
* 
* 
* HashNode.cpp : Implements the HashNode class, which extends the Node class to include
* a pointer to a corresponding cache node. This allows HashNodes to be linked
* to nodes in a FIFO cache while maintaining key-value pairs in the hash table.
* 
* 12/03/2024 - Created by Mohit Kumar and Arpan Rakeshbhai
* 12/04/2024 - Modified by Franco Barra
* 
*/

#include "HashNode.hpp"

/*  HashNode Constructor

Initializes a HashNode with the given key value. This constructor sets up the
node without linking it to any cache data by initializing the cacheNode pointer to nullptr.

*/
HashNode::HashNode(int value) : Node(value), cacheNode(nullptr) {
    // Initialization of HashNode without associated cache node
}


/*  HashNode Constructor (Overloaded)

Initializes a HashNode with the given key value and a pointer to an associated
cache node. This constructor links the HashNode to the corresponding Node in the cache.

*/
HashNode::HashNode(int value, Node* newCacheNode) : Node(value), cacheNode(newCacheNode) {
    // Initialization of HashNode with associated cache node
}


/*  getCachePointer

Retrieves the pointer to the associated cache node stored in this HashNode.

*/
Node* HashNode::getCachePointer() {
    return cacheNode;
}
