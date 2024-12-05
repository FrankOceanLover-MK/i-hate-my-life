#include "HashTable.hpp"
#include <iostream>
#include <stdexcept>

HashTable::HashTable() : table(new HashNode*[_HASH_TABLE_SIZE]()), numberOfItems(0) {}

HashNode** HashTable::getTable() {
    return table;
}

int HashTable::getSize() {
    return _HASH_TABLE_SIZE;
}

bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

int HashTable::getNumberOfItems() {
    return numberOfItems;
}

bool HashTable::add(int searchKey, HashNode* newItem) {
    int index = searchKey % _HASH_TABLE_SIZE;

    if (!table[index]) {
        table[index] = newItem;
        numberOfItems++;
        return true;
    }

    Node* current = table[index]; // Use Node* for traversal
    while (current) {
        if (current->key == searchKey) {
            return false; // Duplicate key not allowed
        }
        if (!current->next) {
            current->next = newItem; // Safely assign as Node*
            numberOfItems++;
            return true;
        }
        current = current->next;
    }

    return false;
}

bool HashTable::remove(int searchKey) {
    int index = searchKey % _HASH_TABLE_SIZE;
    Node* current = table[index];
    Node* prev = nullptr;

    while (current) {
        if (current->key == searchKey) {
            if (prev) {
                prev->next = current->next;
            } else {
                table[index] = static_cast<HashNode*>(current->next);
            }
            delete current;
            numberOfItems--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

void HashTable::clear() {
    for (int i = 0; i < _HASH_TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
    numberOfItems = 0;
}

HashNode* HashTable::getItem(int searchKey) {
    int index = searchKey % _HASH_TABLE_SIZE;
    Node* current = table[index];

    while (current) {
        if (current->key == searchKey) {
            return dynamic_cast<HashNode*>(current); // Safely cast to HashNode*
        }
        current = current->next;
    }

    return nullptr;
}

bool HashTable::contains(int searchKey) {
    return getItem(searchKey) != nullptr;
}

