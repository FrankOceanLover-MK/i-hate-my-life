#include "FifoNode.hpp"

Data::Data(int keyValue, std::string fullName, std::string address, std::string city, std::string state, std::string zip)
    : key(keyValue), fullName(fullName), address(address), city(city), state(state), zip(zip) {}

FifoNode::FifoNode(int value) : Node(value), dataValues(nullptr) {
    // Initialization of FifoNode
}

FifoNode:: FifoNode(int value, Data* newData): Node(value), dataValues(newData){}
