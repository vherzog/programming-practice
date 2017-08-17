#include "linked_list.h"
#include <iostream>
using namespace std;

Node::Node(int value) {
  // Node constructor with data input
  this->data = value;
  this->next = NULL;
}

LinkedList::LinkedList() {
  this->head = NULL;
}

LinkedList::LinkedList(int value) {
  this->head = new Node(value);
}

LinkedList::~LinkedList() {
  // LinkedList destructor
  Node* current = this->head;
  Node* next = NULL;
  
  while(current) {
    next = current->next;
    delete current;
    current = next;
  }
}
  
int LinkedList::size() {
    // Return the size of the linked list
  int size = 0;
  
  Node* current = this->head;
  while(current) {
    current = current->next;
    size++;
  }
  return size;
}
  
bool LinkedList::empty() {
    // Return true if linked list is empty
    if(this->head == NULL) {
      return true;
    }
    else {
      return false;
    }
  }
  
int LinkedList::value_at(int index) {
    // Return the value of the node at indicated index
    Node* head = this->head;
    if(head == NULL) {
      //throw std::out_of_range('linked list is empty');
      cout << "WARNING: Linked List empy" << endl;
      return -1;
    }
    for(int i = 1; i < index; i++) {
      head = head->next;
      if(head = NULL) {
        //throw std::out_of_range('index out of linked list range');
        cout << "WARNING: Out of range" << endl;
      return -1;
      }
    }
    return head->data;
  }
  
void LinkedList::push_front(int value) {
    // Adds a node to the beginning of linked list
    if(this->head == NULL) {
      this->head = new Node(value);
    }
    else {
      Node* tmp = this->head;
      this->head = new Node(value);
      this->head->next = tmp;
    }
  }
  
int LinkedList::pop_front() {
    // Remove head of linked list
    if(this->head == NULL) {
      //throw std::out_of_range('linked list empty');
      cout << "WARNING: Linked List empy" << endl;
      return -1;
    }
    Node* tmp = this->head->next;
    int value = this->head->data;
    delete this->head;
    this->head = tmp;
    return value;
  }
  
void LinkedList::push_back(int value) {
  // Add to end of linked list
  if(this->head == NULL) {
    this->head = new Node(value);
  }
  else {
    Node* current = this->head;
    while(current->next != NULL) {
      current = current->next;
    }
    current->next = new Node(value);
  }
}

int LinkedList::pop_back() {
  // Remove end of linked list
  int value;
  if(this->head == NULL) {
    //throw std::out_of_range('linked list empty');
    cout << "WARNING: Linked List empy" << endl;
    return -1;
  }
  else if(this->head->next == NULL) {
    value = this->head->data;
    delete this->head;
    this->head = NULL;
  }
  else {
    Node* current = this->head;
    while(current->next->next != NULL) {
      current = current->next;
    }
    value = current->next->data; 
    delete current->next;
    current->next = NULL;
  }
  return value;
}

int LinkedList::front() {
  // Return value of first Node in list
  if(this->head != NULL) {
    return this->head->data;
  }
  else {
    //throw std::out_of_range('linked list is empty');
    cout << "WARNING: Linked List empy" << endl;
    return -1;
  }
}

int LinkedList::back() {
  // Return value of last Node in list
  if(this->head != NULL) {
    Node* current = this->head;
    while(current->next != NULL) {
      current = current->next;
    }
    return current->data;
  }
  else {
   //throw std::out_of_range('linked list is empty');
    cout << "WARNING: Linked List empy" << endl;
    return -1;
  }
}

void LinkedList::insert(int index, int value) {
  // Insert node at LinkedList index with value
  Node* current = this->head;
  Node* prev = NULL;
  for(int i = 0; i < index && current; i++) {
    prev = current;
    current = current->next;
  }
  if(i != index) {
    //throw std::out_of_range('index out of range');
    cout << "WARNING: Out of range" << endl;
    return;
  }

  Node* newNode = new Node(value);

  if (prev == NULL) {
    newNode->next = this->head;
    this->head = newNode;
  }
  else {
    newNode->next = prev->next;
    prev->next = newNode;
  }
}

void LinkedList::erase(int index) {
  // Erase node at LinkedList index
  if(this->head == NULL) {
    //throw std::out_of_range('linked list empty');
    cout << "WARNING: Linked List empy" << endl;
    return;
  }
  else {
    Node* current = this->head;
    Node* prev = NULL;
    for(int i = 0; i < index && current; i++) {
      prev = current;
      current = current->next;
    }

    if(i != index) {
      //throw std::out_of_range('index out of range');
      cout << "WARNING: Linked List empy" << endl;
      return;
    }
    else if(prev == NULL) {
      prev = this->head->next;
      delete this->head;
      this->head = prev;
    }
    else {
      Node* tmp = current->next;
      delete current;
      prev->next = tmp;
    }
  }
}

void LinkedList::print_list() {
  // Print all nodes in list
  Node* current = this->head;
  while(current) {
    std::cout<<current->data<<std::endl;
    current = current->next;
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












