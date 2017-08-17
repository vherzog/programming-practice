#include <iostream>
using namespace std;

#include "linked_list.h"
#include "hash_map.h"

int main(int argc, char* argv[]) {
  LinkedList llist = LinkedList(4);
  
  cout << "LinkedList created!" << endl;
  
  llist.push_front(12);
  llist.push_front(9);
  llist.push_front(1);
  llist.push_front(5);
  
  llist.print_list();
  
  size_t table_size = 12;
  HashMap<int, bool, table_size> hashmap;
  
  hashmap.put(1, true);
  hashmap.put(2, false);
  
  bool val1, val2;
  bool result hashmap.get(2, val1);
  
  cout<<"HashMap returns 2 is "<<val1<<endl;
  
  
}