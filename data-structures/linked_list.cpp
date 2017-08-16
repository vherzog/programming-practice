#include "linked_list.h"
#include <iostream>
using namespace std;

Node::Node(int value) {
  // Node constructor with data input
  this.data = value;
  this.next = null;
}

LinkedList::LinkedList() {
  this.head = null;
}

LinkedList::LinkedList(int value) {
  this.head = new Node(value);
}

LinkedList::~LinkedList() {
  // LinkedList destructor
  Node* current = this.head;
  Node* next = null;
  
  while(current) {
    next = current.next;
    delete current;
    current = next;
  }
}
  
int LinkedList::size() {
    // Return the size of the linked list
  int size = 0;
  
  Node* current = this.head;
  while(current) {
    current = current.next;
    size++;
  }
  return size;
}
  
bool LinkedList::empty() {
    // Return true if linked list is empty
    if(this.head == null) {
      return true;
    }
    else {
      return false;
    }
  }
  
int LinkedList::value_at(int index) {
    // Return the value of the node at indicated index
    Node* head = this.head;
    if(head == null) {
      throw std::out_of_range('linked list is empty');
    }
    for(int i = 1; i < index; i++) {
      head = head.next;
      if(head = null) {
        throw std::out_of_range('index out of linked list range');
      }
    }
    return head.data;
  }
  
void LinkedList::push_front(int value) {
    // Adds a node to the beginning of linked list
    if(this.head == null) {
      this.head = new Node(value);
    }
    else {
      Node* tmp = this.head;
      this.head = new Node(value);
      this.head.next = tmp;
    }
  }
  
int LinkedList::pop_front() {
    // Remove head of linked list
    if(this.head == null) {
      throw std::out_of_range('linked list empty');
      return null;
    }
    Node* tmp = this.head.next;
    int value = this.head.data;
    delete this.head;
    this.head = tmp;
    return value;
  }
  
void LinkedList::push_back(int value) {
  // Add to end of linked list
  if(this.head == null) {
    this.head = new Node(value);
  }
  else {
    Node* current = this.head;
    while(current.next != null) {
      current = current.next;
    }
    current.next = new Node(value);
  }
}

int LinkedList::pop_back() {
  // Remove end of linked list
  int value;
  if(this.head == null) {
    throw std::out_of_range('linked list empty');
    return null;
  }
  else if(this.head.next == null) {
    value = this.head.data;
    delete this.head;
    this.head = null;
  }
  else {
    while(current.next.next != null) {
      current = current.next;
    }
    value = current.next.data; 
    delete current.next;
    current.next = null;
  }
  return value;
}

int LinkedList::front() {
  // Return value of first Node in list
  if(this.head != null) {
    return this.head.data;
  }
  else {
   throw std::out_of_range('linked list is empty');
  }
}

int LinkedList::back() {
  // Return value of last Node in list
  if(this.head != null) {
    Node* current = this.head;
    while(current.next != null) {
      current = current.next;
    }
    return current.data;
  }
  else {
   throw std::out_of_range('linked list is empty');
  }
}

void LinkedList::insert(int index, int value) {
  // Insert node at LinkedList index with value
  Node* current = this.head;
  Node* prev = null;
  for(int i = 0; i < index && current; i++) {
    prev = current;
    current = current.next;
  }
  if(i != index) {
    throw std::out_of_range('index out of range');
  }

  Node* newNode = new Node(value);

  else if (prev == null) {
    newNode.next = this.head;
    this.head = newNode;
  }
  else {
    newNode.next = prev.next;
    prev.next = newNode;
  }
}

void LinkedList::erase(int index) {
  // Erase node at LinkedList index
  if(this.head == null) {
    throw std::out_of_range('linked list empty');
  }
  else {
    Node* current = this.head;
    Node* prev = null;
    for(int i = 0; i < index && current; i++) {
      prev = current;
      current = current.next;
    }

    if(i != index) {
      throw std::out_of_range('index out of range');
    }
    else if(prev == null) {
      prev = this.head.next;
      delete this.head;
      this.head = prev;
    }
    else {
      Node* tmp = current.next;
      delete current;
      prev.next = tmp;
    }
  }
}

void LinkedList::print_list() {
  // Print all nodes in list
  Node* current = this.head;
  while(current) {
    std::cout<<current.data<<std::endl;
    current = current.next;
  }
}

int LinkedList::nth_from_end(int n) {
  // Return node n-th from the end of LinkedList
  return 0;
}

void LinkedList::reverse() {
  // Reverse LinkedList
}

void LinkedList::remove_value(int value) {
  // Remove the first node in LinkedList with that value
}













