/* hash_key.h */

#ifndef HASH_KEY_H
#define HASH_KEY_H

#include <iostream>
using namespace std;

template<typename Key, size_t size>
struct HashKey {
  unsigned long operator()(const Key &key) const;
};

#endif /* hash_key.h */