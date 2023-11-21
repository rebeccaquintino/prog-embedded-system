#pragma once

#include <string>

/* Node struct for linked list */
struct Node {
public:
    std::string log;        // Data stored in the node
    std::string time; 
    Node* nextNode;    // Pointer to the next node in the linked list
    int number;

    Node(std::string log_, Node* next_, int number_, std::string time_);   // Constructor to initialize the node with data and next node pointer

    void setTime(std::string time_);
    std::string getTime(void);

    void setLog(std::string log_);   // Setter function to set the data of the node
    std::string getLog(void);   // Getter function to get the data of the node

    void setNext(Node* next_);   // Setter function to set the next node pointer
    Node* getNext();   // Getter function to get the next node pointer
};
