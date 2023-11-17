#pragma once

/* Node struct for linked list*/
template <typename Tp>
struct Node {
  Tp value;
  Node* next;
  Node(Tp item) : value{item}, next{nullptr} {}
};
/* Queue class*/
template <typename Tp>
class Queue {
  using NodeP = Node <Tp>*;

 public:
  Queue(int capacity) : capacity_{capacity} {}
  auto enqueue(Tp item) -> void;
  auto dequeue() -> Tp;
  auto peek() const -> Tp { return head_->value; }
  auto lenght() const -> int { return lenght_; }
  auto capacity() const -> int { return capacity_; }
  operator bool() const { return lenght_ != 0; }

 private:
  int capacity_;
  int lenght_{0};
  NodeP head_{nullptr};
  NodeP tail_{nullptr};
};

/* Enqueue itens in the back of the queue */
template <typename Tp>
auto Queue<Tp>::enqueue(Tp item) -> void {
  if (lenght_ < capacity_) {
    if (tail_ == nullptr) {
      tail_ = new Node<Tp>(item);
      head_ = tail_;
    } else {
      NodeP node = new Node<Tp>(item);
      tail_->next = node;
      tail_ = node;
      tail_->next = head_;
    }
    lenght_++;
  } else {
    head_->value = item;
    tail_->next = head_;
    tail_ = head_;
    head_ = head_->next;
  }
}

/* Dequeue itens from the front of the queue */
template <typename Tp>
auto Queue<Tp>::dequeue() -> Tp {
  --lenght_;
  Tp value = head_->value;
  auto tmp = head_;
  head_ = head_->next;
  if (lenght_ != 0) {
    tail_->next = head_;
  } else {
    tail_ = nullptr;
  }
  delete tmp;
  return value;
}