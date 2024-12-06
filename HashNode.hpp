/**
*
* HashNode.hpp : This is the header file for HashNode.
*
* 09/23/24 - Created by ChatGPT
* 09/23/24 - Modified by jhui
* 11/07/24 - Modified by jhui
* 12/03/24 - Modified by Mohit Kumar
*/

#ifndef HASH_NODE
#define HASH_NODE

#include "Node.hpp"
#include <string>

/**
* HashNode
*
* This class is the node used by the HashTable.
*/
class HashNode : public Node {
private:
    Node* cacheNode;

public:

    //  HashNode Constructor
    HashNode(int value);


    /*  HashNode Constructor (Overloaded)

    Initializes a HashNode with the given key value and a pointer to an associated
    cache node. This constructor is helps with directly linking the HashNode to a 
    corresponding Node in the cache.

    Parameters:
      - value (int): Key value for the HashNode.
      - newCacheNode (Node*): Pointer to the associated cache node.
    */
    HashNode(int value, Node* newCacheNode);


    /*  getCachePointer

    Retrieves the pointer to the associated cache node stored in this HashNode.

    */
    Node* getCachePointer();




#endif // HASH_NODE
