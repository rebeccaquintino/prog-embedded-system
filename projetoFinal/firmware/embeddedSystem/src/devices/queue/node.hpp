#pragma once

#include <string>

/* Node struct for linked list */
template <typename Tp>
struct Node {
public:
    Tp log;        // Data stored in the node
    Node* next;    // Pointer to the next node in the linked list
    Node(Tp data, Node* nextNode);   // Constructor to initialize the node with data and next node pointer
    void setLog(Tp data);   // Setter function to set the data of the node
    Tp getLog(void);   // Getter function to get the data of the node
    void setNext(Node* nextNode);   // Setter function to set the next node pointer
    Node* getNext();   // Getter function to get the next node pointer
};
