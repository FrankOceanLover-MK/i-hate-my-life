#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

void DoublyLinkedList::insertAtHead(Node* newNode) {
    if (!newNode) return;

    newNode->next = head;
    newNode->prev = nullptr;

    if (head) {
        head->prev = newNode;
    }

    head = newNode;

    if (!tail) {
        tail = head;
    }
}

void DoublyLinkedList::insertAtTail(Node* newNode) {
    if (!newNode) return;

    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail) {
        tail->next = newNode;
    }

    tail = newNode;

    if (!head) {
        head = tail;
    }
}

Node* DoublyLinkedList::findNode(int value) {
    Node* current = head;
    while (current) {
        if (current->key == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::deleteNode(Node* existingNode) {
    if (!existingNode) return;

    if (existingNode->prev) {
        existingNode->prev->next = existingNode->next;
    } else {
        head = existingNode->next;
    }

    if (existingNode->next) {
        existingNode->next->prev = existingNode->prev;
    } else {
        tail = existingNode->prev;
    }

    delete existingNode;
}

void DoublyLinkedList::moveToHead(Node* existingNode) {
    if (!existingNode || existingNode == head) return;

    deleteNode(existingNode);
    insertAtHead(existingNode);
}

void DoublyLinkedList::moveToTail(Node* existingNode) {
    if (!existingNode || existingNode == tail) return;

    deleteNode(existingNode);
    insertAtTail(existingNode);
}

void DoublyLinkedList::deleteHeadNode() {
    if (head) {
        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }
}

void DoublyLinkedList::deleteTailNode() {
    if (tail) {
        Node* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }
}

void DoublyLinkedList::deleteList() {
    while (head) {
        deleteHeadNode();
    }
}

Node* DoublyLinkedList::getHead() {
    return head;
}

Node* DoublyLinkedList::getTail() {
    return tail;
}
