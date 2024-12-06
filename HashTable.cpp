/**
* 
* Mohit Kumar
* Arpan Rakeshbhai
* 12/04/2024
* 
* 
* HashTable.cpp : Implements the HashTable class, which stores key-value pairs using a fixed-size 
* array of pointers. The hash table uses separate chaining to handle collisions,
* where each bucket is a linked list of nodes. This class provides methods for
* insertion, deletion, lookup, and other common operations.
* 
* 12/03/2024 - Created by Mohit Kumar and Arpan Rakeshbhai
* 12/04/2024 - Modified by Mohit Kumar and Arpan Rakeshbhai through ChatGPT
* 12/04/2024 - Modified by Franco Barra. Helped us fix a bug with the pointers in
* remove and getItem methods by suggesting up/down casting.
* 
*/

#include "HashTable.hpp"
#include <iostream>
#include <stdexcept>

/*  HashTable Constructor

Initializes an empty hash table. Allocates an array of pointers with a size
defined by _HASH_TABLE_SIZE, and sets the number of items to 0.

*/
HashTable::HashTable() : table(new HashNode*[_HASH_TABLE_SIZE]()), numberOfItems(0) {}



/*  getTable

Returns the internal table array, which stores the buckets of the hash table.
Useful for debugging or verification.

*/
HashNode** HashTable::getTable() {
    return table;
}



/*  getSize

Returns the total number of buckets in the hash table. This is a constant value
defined by _HASH_TABLE_SIZE.

*/
int HashTable::getSize() {
    return _HASH_TABLE_SIZE;
}



/*  isEmpty

Checks whether the hash table is empty. The table is considered empty if the
number of stored items is 0.

*/
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}



/*  getNumberOfItems

Returns the number of items currently stored in the hash table.

*/
int HashTable::getNumberOfItems() {
    return numberOfItems;
}



/*  add

Adds a new HashNode to the hash table. Uses the modulus operator to determine
the bucket index based on the key. If the bucket is empty, the new node is added directly.
Otherwise, the node is appended to the linked list in the bucket. Duplicate keys are not allowed.

Returns:
  - bool: True if the node was successfully added, false if the key is a duplicate.
*/
bool HashTable::add(int searchKey, HashNode* newItem) {
    int index = searchKey % _HASH_TABLE_SIZE; // Compute bucket index

    if (!table[index]) {
        table[index] = newItem; // Add to empty bucket
        numberOfItems++;
        return true;
    }

    Node* current = table[index]; // Traverse the bucket's linked list
    while (current) {
        if (current->key == searchKey) {
            return false; // Duplicate key not allowed
        }
        if (!current->next) {
            current->next = newItem; // Append new node at the end
            numberOfItems++;
            return true;
        }
        current = current->next;
    }

    return false;
}



/*  remove

Removes a node with the specified key from the hash table. Traverses the
linked list in the corresponding bucket to find the node. Updates the
pointers of neighboring nodes to exclude the node being deleted.

Returns:
  - bool: True if the node was successfully removed, false if the key was not found.
*/
bool HashTable::remove(int searchKey) {
    int index = searchKey % _HASH_TABLE_SIZE; // Compute bucket index
    Node* current = table[index];
    Node* prev = nullptr;

    while (current) {
        if (current->key == searchKey) { // Node found
            if (prev) {
                prev->next = current->next; // Update previous node's next pointer
            } else {
                table[index] = static_cast<HashNode*>(current->next); // Update bucket head
            }
            delete current; // Free memory
            numberOfItems--;
            return true;
        }
        prev = current; // Move to next node
        current = current->next;
    }

    return false; // Key not found
}



/*  clear

Clears the entire hash table by deleting all nodes in every bucket.
Iterates through all buckets, deletes each node in the bucket's linked list,
and sets the bucket to nullptr.

*/
void HashTable::clear() {
    for (int i = 0; i < _HASH_TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next; // Move to next node
            delete temp; // Delete current node
        }
        table[i] = nullptr; // Reset bucket to nullptr
    }
    numberOfItems = 0; // Reset item count
}



/*  getItem

Retrieves a HashNode with the specified key. Traverses the linked list
in the corresponding bucket to find the node.

Returns:
  - HashNode*: Pointer to the HashNode if found, nullptr otherwise.
*/
HashNode* HashTable::getItem(int searchKey) {
    int index = searchKey % _HASH_TABLE_SIZE; // Compute bucket index
    Node* current = table[index];

    while (current) {
        if (current->key == searchKey) { // Node found
            return dynamic_cast<HashNode*>(current); // Cast to HashNode*
        }
        current = current->next;
    }

    return nullptr; // Key not found
}



/*  contains

Checks if a node with the specified key exists in the hash table.
Calls getItem to determine if the key is present.

*/
bool HashTable::contains(int searchKey) {
    return getItem(searchKey) != nullptr;
}
