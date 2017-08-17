#include "hash_map.h"
#include "hash_key.h"

#include <iostream>
using namespace std;

/* HashElement class template */
template<typename Key, typename Value> HashElement::HashElement(const Key &key, const Value &value) {
  _key = key;
  _value = value;
  _next = NULL;
}

template<typename Key, typename Value> Key HashElement::get_key() const {
  return _key;
}

template<typename Key, typename Value> Value HashElement::get_value() const {
  return _value;
}

template<typename Key, typename Value> void HashElement::set_value(Value value) {
  _value = value;
}

template<typename Key, typename Value> HashElement* HashElement::get_next() const {
  return _next;
}

template<typename Key, typename Value> void HashElement::set_next(HashElement* next) {
  _next = next;
}

/* HashMap class template */
template <typename Key, typename Value, size_t size, typename F = HashKey<Key, size>>HashMap::HashMap() {}

template <typename Key, typename Value, size_t size, typename F = HashKey<Key, size>>HashMap::~HashMap() {
  for(size_t i = 0; i < size; ++i) {
    HashElement<Key, Value> *entry = table[i];
    
    while(entry != NULL) {
      HashElement<Key, Value> *prev = entry;
      entry = entry->get_next();
      delete prev;
    }
    
    table[i] = NULL;
  }
}

template <typename Key, typename Value, size_t size, typename F = HashKey<Key, size>> bool HashMap::get(const Key &key, Value &value) {
  unsigned long hashVal = hashFunc(key);
  HashElement<Key, Value> *entry = table[hashVal];
  
  while(entry != NULL) {
    if(entry->get_key() == key) {
      value = entry->get_value();
      return true;
    }
    entry = entry->getNext();
  }
  return false;
} 

template <typename Key, typename Value, size_t size, typename F = HashKey<Key, size>> void HashMap::put(const Key &key, const Value &value) {
  unsigned long hashVal = hashFunc(key);
  HashElement<Key, Value> *prev = NULL;
  HashElement<Key, Value> *entry = table[hashVal];
  
  while(entry != NULL && entry->get_key() != key) {
    prev = entry;
    entry = entry->get_next();
  }
  if(entry == NULL) {
    entry = new HashElement<Key, Value>(key, value);
    if(prev == NULL) {
      table[hashVal] = entry;
    }
    else {
      prev->set_next(entry);
    }
  }
  else {
    entry->set_value(value);
  }
}

template <typename Key, typename Value, size_t size, typename F = HashKey<Key, size>> void HashMap::remove(const Key &key) {
  unsigned long hashVal = hashFunc(key);
  HashElement<Key, Value> *prev = NULL;
  HashElement<Key, Value> *entry = table[hashVal];
  
  while(entry != NULL && entry->get_key() != key) {
    prev = entry;
    entry = entry->get_next();
  }
  
  if(entry == NULL) {
    // Key not found!
    return;
  }
  else {
    if(prev == NULL) {
      table[hashVal] = entry->get_next();
    }
    else {
      prev->set_next(entry->get_next());
    }
    
    delete entry;
  }
}


















