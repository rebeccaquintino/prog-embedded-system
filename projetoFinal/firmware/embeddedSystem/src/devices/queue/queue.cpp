#include "../queue/queue.hpp"

//creates an empty Queue
template <typename Tp>
Queue<Tp>::Queue(){    
  first = 0;
}
//destroy the whole Queue
template <typename Tp>
Queue<Tp>::~Queue(){    
  Node<Tp>* ptr_next = first;

  while(first){
    ptr_next = ptr_next -> next;
    delete first;
    first = ptr_next;
  }
}
//saves a new log into the Queue
template <typename Tp>
void Queue<Tp>::insert(Tp newLog){    
  Node<Tp>* aux1 = first;
  Node<Tp>* aux2 = first;
  //creates a new log in case there were'nt any
  if (first == 0){
     first = new Node<Tp>(newLog, 0);     
  }
  //creates a new log entry and adds to the end of the Queue
  else {                      
     while (aux2 != 0) {
        aux1 = aux2; 
        aux2 = aux1->getNext();
  }
     //last log always points to 0 
     aux1->setNext(new Node<Tp>(newLog, 0));
  }
}

template <typename Tp>
void Queue<Tp>::printLog() {
  Node<Tp>* aux1 = first;

  while (aux1 != 0){
     Tp aux2 = aux1->getLog();
     aux1 = aux1->getNext();
  }
  //destroys the Queue after printing to log console
  this->~Queue();      
}