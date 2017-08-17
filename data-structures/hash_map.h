/* hash_map.h */
#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <iostream>
using namespace std;
#include <vector>

#include "hash_key.h"

template<typename Key, typename Value>
class HashElement {
private:
  Key _key;
  Value _value;
  HashElement *_next;
  HashElement(const HashElement &);
  HashElement & operator=(const HashElement &);
  
  
public:
  HashElement(const Key &key, const Value &value);
  Key get_key() const;
  Value get_value() const;
  void set_value(Value value);
  HashElement *get_next() const;
  void set_next(HashElement *next);
};

template <typename Key, typename Value, size_t size, typename F = HashKey<Key, size>> 
class HashMap {
private:
  int elementCount;
  HashMap(const HashMap &other);
  const HashMap &operator=(const HashMap &other);
  HashElement<Key, Value> *table[size];
  F hashFunc;
  
public:
  HashMap() : table(), hashFunc();
  ~HashMap();
  bool get(const Key &key, Value &value);
  void put(const Key &key, const Value &vlaue);
  void remove(const Key &key);
}; /* HashMap class definition */


#endif /* has_maph.h */