/**
* 
* Mohit Kumar
* Arpan Rakeshbhai
* 12/03/2024
* 
* 
* DoublyLinkedList.cpp : Implements the DoublyLinkedList class, which provides methods to manage a 
* doubly linked list. This data structure supports efficient insertion, deletion, 
* and traversal in both forward and backward directions.
* 
* 12/03/2024 - Created by Mohit Kumar and Arpan Rakeshbhai
* 12/04/2024 - Modified by Franco Barra. He assisted us in fixing our methods and debugging
* 
*/

#include "DoublyLinkedList.hpp"
#include <iostream>

/*  DoublyLinkedList

Constructor that initializes an empty DoublyLinkedList. The head and tail pointers
are set to nullptr, indicating the list is empty.

*/
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}



/*  insertAtHead

Inserts a new node at the head of the list. Updates the head pointer
and adjusts the previous pointers of the existing nodes if necessary.

*/
void DoublyLinkedList::insertAtHead(Node* newNode) {
    if (!newNode) return;

    newNode->next = head;  // Set the new node's next pointer to the current head
    newNode->prev = nullptr;  // The new node becomes the head, so no previous node

    if (head) {
        head->prev = newNode;  // Update the current head's previous pointer to the new node
    }

    head = newNode;  // Update the head pointer to the new node

    if (!tail) {
        tail = head;  // If the list was empty, tail also points to the new head
    }
}



/*  insertAtTail

Inserts a new node at the tail of the list. Updates the tail pointer
and adjusts the next pointers of the existing nodes if necessary.

*/
void DoublyLinkedList::insertAtTail(Node* newNode) {
    if (!newNode) return;

    newNode->prev = tail;  // Set the new node's previous pointer to the current tail
    newNode->next = nullptr;  // The new node becomes the tail, so no next node

    if (tail) {
        tail->next = newNode;  // Update the current tail's next pointer to the new node
    }

    tail = newNode;  // Update the tail pointer to the new node

    if (!head) {
        head = tail;  // If the list was empty, head also points to the new tail
    }
}



/*  findNode

Finds a node in the list with the specified key value. Traverses the list
from the head to locate the node.

Returns:
  - Node*: Pointer to the node if found, nullptr otherwise.
*/
Node* DoublyLinkedList::findNode(int value) {
    Node* current = head;  // Start traversal from the head
    while (current) {
        if (current->key == value) {
            return current;  // Return the node if the key matches
        }
        current = current->next;  // Move to the next node
    }
    return nullptr;  // Return nullptr if the node is not found
}



/*  deleteNode

Deletes a specified node from the list. Updates the pointers of neighboring
nodes to remove the node from the list, and frees its memory.

*/
void DoublyLinkedList::deleteNode(Node* existingNode) {
    if (!existingNode) return;

    // Update the previous node's next pointer
    if (existingNode->prev) {
        existingNode->prev->next = existingNode->next;
    } else {
        head = existingNode->next;  // Update head if deleting the first node
    }

    // Update the next node's previous pointer
    if (existingNode->next) {
        existingNode->next->prev = existingNode->prev;
    } else {
        tail = existingNode->prev;  // Update tail if deleting the last node
    }

    delete existingNode;  // Free the memory of the deleted node
}



/*  moveToHead

Moves a specified node to the head of the list. Deletes the node from
its current position and reinserts it at the head.

*/
void DoublyLinkedList::moveToHead(Node* existingNode) {
    if (!existingNode || existingNode == head) return;

    deleteNode(existingNode);  // Remove the node from its current position
    insertAtHead(existingNode);  // Reinsert the node at the head
}



/*  moveToTail

Moves a specified node to the tail of the list. Deletes the node from
its current position and reinserts it at the tail.

*/
void DoublyLinkedList::moveToTail(Node* existingNode) {
    if (!existingNode || existingNode == tail) return;

    deleteNode(existingNode);  // Remove the node from its current position
    insertAtTail(existingNode);  // Reinsert the node at the tail
}



/*  deleteHeadNode

Deletes the node at the head of the list. Updates the head pointer and
adjusts the previous pointer of the new head node.

*/
void DoublyLinkedList::deleteHeadNode() {
    if (head) {
        Node* temp = head;  // Temporarily store the head node
        head = head->next;  // Update the head pointer to the next node

        if (head) {
            head->prev = nullptr;  // Update the new head's previous pointer to null
        } else {
            tail = nullptr;  // If the list becomes empty, update the tail to null
        }

        delete temp;  // Delete the old head node
    }
}



/*  deleteTailNode

Deletes the node at the tail of the list. Updates the tail pointer and
adjusts the next pointer of the new tail node.

*/
void DoublyLinkedList::deleteTailNode() {
    if (tail) {
        Node* temp = tail;  // Temporarily store the tail node
        tail = tail->prev;  // Update the tail pointer to the previous node

        if (tail) {
            tail->next = nullptr;  // Update the new tail's next pointer to null
        } else {
            head = nullptr;  // If the list becomes empty, update the head to null
        }

        delete temp;  // Delete the old tail node
    }
}



/*  deleteList

Deletes all nodes in the list. Traverses the list and deletes each node
until the list is empty.

*/
void DoublyLinkedList::deleteList() {
    while (head) {
        deleteHeadNode();  // Continuously delete the head node until the list is empty
    }
}



/*  getHead

Returns the head node of the list.

*/
Node* DoublyLinkedList::getHead() {
    return head;
}


/*  getTail

Returns the tail node of the list.

Returns:
  - Node*: Pointer to the tail node, or nullptr if the list is empty.
*/
Node* DoublyLinkedList::getTail() {
    return tail;
}
