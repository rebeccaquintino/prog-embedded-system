#include "node.hpp"

// Constructor to initialize the node with data and next node pointer
template <typename Tp>
Node<Tp>::Node(Tp _log, Node* _next) {
    log = _log;
    next = _next;
}
// Setter function to set the data of the node
template <typename Tp>
void Node<Tp>::setLog(Tp _log) {
    log = _log;
}
// Getter function to get the data of the node
template <typename Tp>
Tp Node<Tp>::getLog() {
    return log;
}
// Setter function to set the next node pointer
template <typename Tp>
void Node<Tp>::setNext(Node* _next) {
    next = _next;
}
// Getter function to get the next node pointer
template <typename Tp>
Node<Tp>* Node<Tp>::getNext() {
    return next;
}
