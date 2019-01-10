#ifndef STACK_H
#define STACK_H

#include <tuple>
#include "symbol.h"

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

  std::tuple<symbol::t, T> pop() {
    if (!head) {
      return std::make_tuple(symbol::empty, T());
    }

    T val = head->val;

    node_t *node = head;
    head = head->prev;
    delete node;

    return std::make_tuple(symbol::ok, val);
  }
};

#endif