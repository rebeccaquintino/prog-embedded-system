#pragma once

#include "../queue/node.hpp"  // Including the header file for the Node class

/* Queue class template */
template <typename Tp>
class Queue {
public:
    Node<Tp> first;  // First node of the queue
    Queue();         // Constructor
    ~Queue();        // Destructor
    void insert(Tp); // Function to insert an element into the queue
    void printLog();  // Function to print the elements in the queue
};
