#pragma once

#include <string>

/* Node struct for linked list */
template <typename Tp>
struct Node {
public:
    Tp log;        // Data stored in the node
    Node* nextNode;    // Pointer to the next node in the linked list
    int number;
    Node(Tp log_, Node* next_, int number_);   // Constructor to initialize the node with data and next node pointer
    void setLog(Tp log_);   // Setter function to set the data of the node
    Tp getLog(void);   // Getter function to get the data of the node
    void setNext(Node* next_);   // Setter function to set the next node pointer
    Node* getNext();   // Getter function to get the next node pointer

    // Overloaded operator+ to concatenate an integer and a string
    friend std::string operator+(int n, const std::string& data) {
        std::string complements = ". ";
        std::string str_n = std::to_string(n);

        str_n.append(complements);
        str_n.append(data);

        return str_n;
    }
};
