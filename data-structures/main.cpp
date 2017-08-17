#include <iostream>
using namespace std;

#include "linked_list.h"

int main(int argc, char* argv[]) {
  LinkedList llist = LinkedList(4);
  
  cout << "LinkedList created!" << endl;
  
  llist.push_front(12);
  llist.push_front(9);
  llist.push_front(1);
  llist.push_front(5);
  
  llist.print_list();
  
  
}