#include "../queue/queue.hpp"
#include <iostream>
#include <string>

// Creates an empty Queue
template <typename Tp>
Queue<Tp>::Queue() {    
  first = 0;
  nodes = 0;
}
// Destroys the whole Queue
template <typename Tp>
Queue<Tp>::~Queue() {    
  Node<Tp>* ptr_next = first;

  while (first) {
    ptr_next = ptr_next->getNext();
    delete first;
    first = ptr_next;
  }

  nodes = 0;
}
// Saves a new log into the Queue
template <typename Tp>
void Queue<Tp>::insert(Tp newLog) {    
  Node<Tp>* aux1 = first;
  Node<Tp>* aux2 = first;

  nodes++;
  // Creates a new log in case there weren't any
  if (first == 0) {
    first = new Node<Tp>(newLog, 0, nodes);     
  }
  // Creates a new log entry and adds it to the end of the Queue
  else {                      
    while (aux2 != 0) {
      aux1 = aux2; 
      aux2 = aux1->getNext();
    }
    // The last log always points to 0 
    aux1->setNext(new Node<Tp>(newLog, 0, nodes));
  }
}

// Function to print the logs in the Queue
template <typename Tp>
void Queue<Tp>::printLog() {
  Node<Tp>* aux1 = first; // Pointer to traverse the linked list

  // Check if the queue is empty
  if (first == nullptr) {
    std::cout << "No logs" << std::endl;
    return;
  }

  std::cout << " " << std::endl;
  std::cout << "---------- Access allowed log -------------" << std::endl;

  // Traverse the linked list and print each log
  while (aux1 != nullptr) {
    Tp aux2 = aux1->getLog(); // Get the log from the current node
    std::cout << aux2 << std::endl; // Print the log
    aux1 = aux1->getNext(); // Move to the next node
  }
  // Destroys the Queue after printing to the log console
  this->~Queue();      
}
