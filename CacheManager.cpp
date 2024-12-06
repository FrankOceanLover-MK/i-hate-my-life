/**
* 
* Mohit Kumar
* Arpan Rakeshbhai
* 12/04/2024
* 
* 
* CacheManager.cpp : Implements the CacheManager class, which integrates a HashTable and a FIFO 
* DoublyLinkedList to manage a cache with efficient O(1) operations. The cache ensures that
* frequently accessed or added items are moved to the head of the list. Items are evicted 
* based on a First-In-First-Out (FIFO) policy when the cache exceeds its maximum capacity.
* 
* 12/04/2024 - Created by Mohit Kumar and Arpan Rakeshbhai
* 12/04/2024 - Modified by Mohit Kumar and Arpan Rakeshbhai through ChatGPT
* 
*/

#include "CacheManager.hpp"
#include "DoublyLinkedList.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <stdexcept>

/*  CacheManager

Constructor that initializes the CacheManager with a specified capacity. It sets up 
an empty FIFO DoublyLinkedList and HashTable to manage the cache content.


*/
CacheManager::CacheManager(size_t capacity) : _maxSize(capacity), _curSize(0) {
    _fifoCache = new DoublyLinkedList();
    _hashTable = new HashTable();
}


/*  getTable

Returns a pointer to the internal HashTable, allowing for verification and debugging.

*/
HashTable* CacheManager::getTable() {
    return _hashTable;
}


/*  getFifoList

Returns a pointer to the internal FIFO DoublyLinkedList, allowing for verification and debugging.

*/
DoublyLinkedList* CacheManager::getFifoList() {
    return _fifoCache;
}


/*  getItem

Retrieves a node from the cache using its key. If the node exists, it is moved to the head of
the FIFO list to indicate recent access.

Returns:
  - Node*: Pointer to the retrieved node, or nullptr if the key does not exist.
*/
Node* CacheManager::getItem(int key) {
    Node* node = _hashTable->getItem(key);
    if (node) {
        _fifoCache->moveToHead(node);
    }
    return node;
}


/*  getSize

Returns the current size of the cache.

*/
size_t CacheManager::getSize() {
    return _curSize;
}


/*  isEmpty

Checks if the cache is empty. Returns true if empty
false otherwise.

*/
bool CacheManager::isEmpty() {
    return _curSize == 0;
}


/*  getNumberOfItems

Returns the number of items stored in the hash table.

*/
size_t CacheManager::getNumberOfItems() {
    return _hashTable->getNumberOfItems();
}


/*  add

Adds a new item to the cache. If the cache is full, the least recently used (FIFO tail)
item is evicted. If the key already exists, the item is moved to the head of the FIFO list.

Returns:
  - bool: True if the item was successfully added or updated, false otherwise.
*/
bool CacheManager::add(int key, Data* newItem) {
    // Check if the node exists, and update it to the head in the FIFO list
    if (_hashTable->contains(key)) {
        Node* existingNode = _hashTable->getItem(key);
        _fifoCache->moveToHead(existingNode);
        return true;
    }
    
    // Check if the cache is full and evict the tail node if necessary
    if (_curSize >= _maxSize) {
        Node* tailNode = _fifoCache->getTail();
        _hashTable->remove(tailNode->key);
        _fifoCache->deleteTailNode();
        _curSize--;
    }

    // Create new node and add it to the cache
    FifoNode* newNode = new FifoNode(key, newItem);
    HashNode* newNode1 = new HashNode(key, newNode);
    _fifoCache->insertAtHead(newNode);
    _hashTable->add(key, newNode1);
    _curSize++;

    return true;
}


/*  remove

Removes an item from the cache using its key. The corresponding node is deleted from
both the FIFO list and the hash table.

Returns:
  - bool: True if the item was successfully removed, false otherwise.
*/
bool CacheManager::remove(int key) {
    if (!_hashTable->contains(key)) {
        return false;
    }

    HashNode* node = _hashTable->getItem(key);
    Node* node2 = node->getCachePointer();
    
    _fifoCache->deleteNode(node2);
    _hashTable->remove(key);
    _curSize--;

    return true;
}


/*  clear

Clears the entire cache by deleting all nodes from both the FIFO list and the hash table.
Resets the current size to 0.
*/
void CacheManager::clear() {
    _fifoCache->deleteList();
    _hashTable->clear();
    _curSize = 0;
}


/*  contains

Checks if a specific key exists in the cache.


Returns:
  - bool: True if the key exists, false otherwise.
*/
bool CacheManager::contains(int key) {
    return _hashTable->contains(key);
}
