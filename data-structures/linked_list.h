/* linked_list.h */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


class Node {
public:
  int data;
  Node* next;
  Node(int value);
};

class LinkedList {
public:
  Node* head;
  LinkedList();
  LinkedList(int value);
  ~LinkedList();
  int size();
  bool empty();
  int value_at(int index);
  void push_front(int value);
  int pop_front();
  void push_back(int value);
  int pop_back();
  int front();
  int back();
  void insert(int index, int value);
  void erase(int index);
  void print_list();
  int nth_from_end(int n);
  void reverse();
  void remove_value(int value);
};

#endif /* linked_list.h */