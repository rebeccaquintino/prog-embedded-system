#include "node.hpp"

// Constructor to initialize the node with data and next node pointer
template <typename Tp>
Node<Tp>::Node(Tp log_, Node* next_, int number_) {
    // Assign the provided values to the member variables
    number = number_;
    nextNode = next_;
    log = number + log_;
}
// Setter function to set the data of the node
template <typename Tp>
void Node<Tp>::setLog(Tp log_) {
    // Update the log by adding the provided value to the existing number
    log = number + log_;
}
// Getter function to get the data of the node
template <typename Tp>
Tp Node<Tp>::getLog() {
    // Return the current log value
    return log;
}
// Setter function to set the next node pointer
template <typename Tp>
void Node<Tp>::setNext(Node* next_) {
    // Update the next pointer with the provided value
    nextNode = next_;
}
// Getter function to get the next node pointer
template <typename Tp>
Node<Tp>* Node<Tp>::getNext() {
    // Return the current next pointer
    return nextNode;
}
