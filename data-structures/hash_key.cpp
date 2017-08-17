#include "hash_key.h"

#include <iostream>
using namespace std;

template<typename Key, size_t size> unsigned long HashKey::operator()(const Key &key) const {
  return (reinterpret_cast<unsigned long>(key) % size);
}