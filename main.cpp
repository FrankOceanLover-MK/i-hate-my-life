//
//  main.cpp
//  week_11
//
//  Created by Franco Barra on 11/10/24.
//

#include <iostream>
#include "DoublyLinkedList.hpp"
#include "Node.hpp"
#include "HashNode.hpp"
#include "FifoNode.hpp"
#include "CacheManager.hpp"
#include <string>

using namespace std;

//class Dog{
//private:
//    string name;
//public:
//    Dog(string input){
//        name = input;
//    }
//    string getName(){
//        return name;
//    }
//};


void printTable(HashTable *inputTable) {
    std::cout << "\nTable contents " << "(" << inputTable->getNumberOfItems() << " entries):";
    bool isFirst = true;
    HashNode** internalTable = inputTable->getTable();

    for (size_t i = 0; i < inputTable->getSize(); ++i) {
        Node* curEntry = internalTable[i];
        if (curEntry == nullptr) {
            if (isFirst) {
                std::cout << "\n\nEmpty: " << i;
                isFirst = false;
            }
            else {
                std::cout << ", " << i;
            }

            continue;
        }

        // have a valid entry in the table
        isFirst = true;
        while (curEntry) {
            // curEntry is pointing to the next node
            if (isFirst) {
                std::cout << "\n\nIndex: " << i << ": " << curEntry->key;
                isFirst = false;
            }
            else {
                std::cout << ", " << curEntry->key;
            }

            curEntry = curEntry->next;
        }

        isFirst = true;
    }

    std::cout << "\n\nEnd of table\n\n";
}

int main(int argc, const char * argv[]) {
    
    
    // create 10 Data Structs
    
    Data* data1 = new Data(1, "John Doe", "123 Maple St", "San Francisco", "CA", "94101");
    Data* data2 = new Data(2, "Jane Smith", "456 Elm St", "Los Angeles", "CA", "90001");
    Data* data3 = new Data(3, "Alice Johnson", "789 Oak St", "San Diego", "CA", "92101");
    Data* data4 = new Data(4, "Bob Brown", "101 Pine St", "Sacramento", "CA", "95814");
    Data* data5 = new Data(5, "Charlie Davis", "202 Cedar St", "San Jose", "CA", "95101");
    Data* data6 = new Data(6, "Eve Martinez", "303 Spruce St", "Fresno", "CA", "93701");
    Data* data7 = new Data(7, "Frank Wilson", "404 Birch St", "Long Beach", "CA", "90802");
    Data* data8 = new Data(8, "Grace Lee", "505 Willow St", "Oakland", "CA", "94601");
    Data* data9 = new Data(9, "Hank Adams", "606 Chestnut St", "Irvine", "CA", "92602");
    Data* data10 = new Data(10, "Ivy Baker", "707 Palm St", "Santa Clara", "CA", "95050");
    
    
    
    size_t size = 11;
    CacheManager* cacheManager = new CacheManager(size);
    
    // testing add method
    cacheManager->add(1, data1);
    cacheManager->add(2, data2);
    cacheManager->add(3, data3);
    cacheManager->add(4, data4);
    cacheManager->add(5, data5);
    cacheManager->add(6, data6);
    cacheManager->add(7, data7);
    cacheManager->add(8, data8);
    cacheManager->add(9, data9);
    cacheManager->add(10, data10);
    
    HashTable* hashtable1 = cacheManager->getTable();
    printTable(hashtable1);
    
    cacheManager->remove(1);
    cacheManager->remove(3);
    cacheManager->remove(5);
    cacheManager->remove(7);
    cacheManager->remove(9);
    
    cout << endl << endl;
    printTable(hashtable1);
    
    return 0;
}
