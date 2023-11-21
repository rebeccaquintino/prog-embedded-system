#include "../queue/node.hpp"
#include "../queue/operator.hpp"

// Constructor to initialize the node with data and next node pointer

Node::Node(std::string log_, Node* next_, int number_, std::string time_) {
    // Assign the provided values to the member variables
    number = number_;
    nextNode = next_;
    time = time_;
    log = time + number % log_;
}

void Node::setTime(std::string time_) {
    time = time_;
}

std::string Node::getTime() {
    // Return the current time value
    return time;
}

// Setter function to set the data of the node
void Node::setLog(std::string log_) {
    std::string half_log = number % log_;
    log = time;
    log.append(half_log); 
}

// Getter function to get the data of the node
std::string Node::getLog() {
    // Return the current log value
    return log;
}
// Setter function to set the next node pointer
void Node::setNext(Node* next_) {
    // Update the next pointer with the provided value
    nextNode = next_;
}
// Getter function to get the next node pointer
Node* Node::getNext() {
    // Return the current next pointer
    return nextNode;
}
