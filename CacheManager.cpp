#include "CacheManager.hpp"
#include "DoublyLinkedList.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <stdexcept>

CacheManager::CacheManager(size_t capacity) : _maxSize(capacity), _curSize(0) {
    _fifoCache = new DoublyLinkedList();
    _hashTable = new HashTable();
}

HashTable* CacheManager::getTable() {
    return _hashTable;
}

DoublyLinkedList* CacheManager::getFifoList() {
    return _fifoCache;
}

Node* CacheManager::getItem(int key) {
    Node* node = _hashTable->getItem(key);
    if (node) {
        _fifoCache->moveToHead(node);
    }
    return node;
}

size_t CacheManager::getSize() {
    return _curSize;
}

bool CacheManager::isEmpty() {
    return _curSize == 0;
}


size_t CacheManager::getNumberOfItems() {
    return _hashTable->getNumberOfItems();
}

bool CacheManager::add(int key, Data* newItem) {
    //check if node exist. update to head in fifo list
    if (_hashTable->contains(key)) {
        Node* existingNode = _hashTable->getItem(key);
        //existingNode->data = newItem;
        _fifoCache->moveToHead(existingNode);
        return true;
    }
    
    // checkng if cache manager is full
    if (_curSize >= _maxSize) {
        Node* tailNode = _fifoCache->getTail();
        _hashTable->remove(tailNode->key);
        _fifoCache->deleteTailNode();
        _curSize--;
    }

    FifoNode* newNode = new FifoNode(key, newItem);
    HashNode* newNode1 = new HashNode(key, newNode);
    _fifoCache->insertAtHead(newNode);
    _hashTable->add(key, newNode1);
    _curSize++;

    return true;
}

bool CacheManager::remove(int key) {
    if (!_hashTable->contains(key)) {
        return false;
    }

    Node* node = _hashTable->getItem(key);
    _fifoCache->deleteNode(node);
    _hashTable->remove(key);
    _curSize--;

    return true;
}

void CacheManager::clear() {
    _fifoCache->deleteList();
    _hashTable->clear();
    _curSize = 0;
}

bool CacheManager::contains(int key) {
    return _hashTable->contains(key);
}
