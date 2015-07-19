#ifndef _LRU_CACHE_H_
#define _LRU_CACHE_H_

#include <unordered_map>
#include <memory>
#include <iostream>
#include "doublyLinkedList.h"

class LRUCache
{
    public:
        LRUCache(std::size_t sz = 10) : cacheSize(sz) { cache.reserve(cacheSize); }
        char get(int);
        void set(int, char);
    private:
        std::unordered_map<int, CacheEntry*> cache;
        DoublyLinkedList list;
        std::size_t cacheSize;
};

#endif
