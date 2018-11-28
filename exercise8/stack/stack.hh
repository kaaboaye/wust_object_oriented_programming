#ifndef STACK_H
#define STACK_H

#include <tuple>

template <typename T>
class Stack {
  struct node_t {
    T val;
    node_t *prev;

    node_t(T val) {
      this->val = val;
      this->prev = nullptr;
    }
  };

  node_t *head;

 public:
  Stack() { head = nullptr; }

  void push(T val) {
    node_t *el = new node_t(val);

    if (head) {
      el->prev = head;
    }

    head = el;
  }

  std::tuple<bool, T> pop() {
    if (!head) {
      return std::make_tuple(false, T());
    }

    T val = head->val;

    node_t *node = head;
    head = head->prev;
    delete node;

    return std::make_tuple(true, val);
  }
};

#endif