/**
* 
* Mohit Kumar
* Arpan Rakeshbhai
* 12/03/2024
* 
* 
* FifoNode.cpp : Implements the FifoNode class, which extends the Node class to include additional
* data storage via the Data object. This file also implements the Data class, used
* to store detailed information associated with a FifoNode, such as address details.
* 
* 12/03/2024 - Created by Mohit Kumar and Arpan Rakeshbhai
* 12/04/2024 - Modified by Franco Barra. He helped us the overloaded contstructor 

* 
*/

#include "FifoNode.hpp"

/*  Data Constructor

Initializes a Data object with the given details, including a key, full name,
address, city, state, and ZIP code.

*/
Data::Data(int keyValue, std::string fullName, std::string address, std::string city, std::string state, std::string zip)
    : key(keyValue), fullName(fullName), address(address), city(city), state(state), zip(zip) {}

/*  FifoNode Constructor

Initializes a FifoNode with the given key value. This constructor sets the
dataValues pointer to nullptr, indicating no associated data yet.


*/
FifoNode::FifoNode(int value) : Node(value), dataValues(nullptr) {
    // Initialization of FifoNode without associated data
}


//  FifoNode Constructor (Overloaded)

FifoNode::FifoNode(int value, Data* newData) : Node(value), dataValues(newData) {}
