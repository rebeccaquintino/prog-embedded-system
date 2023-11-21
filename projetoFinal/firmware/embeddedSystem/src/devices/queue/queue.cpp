#include "../queue/queue.hpp"

// Creates an empty Queue
Queue::Queue() {    
  first = 0;
  nodes = 0;
}
// Destroys the whole Queue
Queue::~Queue() {    
  Node* ptr_next = first;

  while (first) {
    ptr_next = ptr_next-> nextNode;
    delete first;
    first = ptr_next;
  }

  nodes = 0;
}

// Saves a new log into the Queue
void Queue::insert(std::string newLog) {  

  std::string current_time = str_time.now();

  Node* aux1 = first;
  Node* aux2 = first;

  nodes++;
  // Creates a new log in case there weren't any
  if (first == 0) {
    first = new Node(newLog, 0, nodes, current_time);     
  }
  // Creates a new log entry and adds it to the end of the Queue
  else {                      
    while (aux2 != 0) {
      aux1 = aux2; 
      aux2 = aux1->getNext();
    }
    // The last log always points to 0 
    aux1->setNext(new Node(newLog, 0, nodes, current_time));
  }
}

// Function to print the logs in the Queue
void Queue::printLog() {
  Node* aux1 = first; // Pointer to traverse the linked list

  // Check if the queue is empty
  if (first == 0) {
    std::cout << "No access" << std::endl;
    return;
  }

  std::cout << " " << std::endl;
  std::cout << "---------- Access allowed log -------------" << std::endl;

  // Traverse the linked list and print each log
  while (aux1 != 0) {
    std::string aux2 = aux1->getLog(); // Get the log from the current node
    std::cout << aux2 << std::endl; // Print the log
    aux1 = aux1->getNext(); // Move to the next node
  }
  // Destroys the Queue after printing to the log console
  this->~Queue();      
}
