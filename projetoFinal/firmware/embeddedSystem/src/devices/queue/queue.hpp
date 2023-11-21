#pragma once
#include <Arduino.h>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>


#include "../queue/node.hpp"  // Including the header file for the Node class
#include "../clockCalendar/clockCalendar.hpp"


/* Queue class template */
class Queue {
public:
    Node* first;  // First node of the queue
    int nodes;       //counts the total of nodes in the list
    ClockCalendar str_time;

    Queue();         // Constructor
    ~Queue();        // Destructor
    void insert(std::string); // Function to insert an element into the queue
    void printLog();  // Function to print the elements in the queue
};
