#include "lruCache.h"
#include <cassert>

char LRUCache::get(int key)
{
    // lookup key in cache
    // if found, return and set this node as tail
    // else return null char
    auto it = cache.find(key);
    if (it != cache.end())
    {
        CacheEntry* ptr = it->second;
        list.moveNodeToTail(ptr);
        return ptr->data;
    }
    else
        return '\0';
}


void LRUCache::set(int key, char val)
{
    auto it = cache.find(key);
    if (it != cache.end())
    {
        // update the key with new value
        it->second->data = val;
        list.moveNodeToTail(it->second);
    }
    else
    {
       // the element does not exist in the cache.
       // add a new element, and if the cache is at
       // max sixe, remove least recently used object
       CacheEntry* ptr = list.addToList(key, val);
       if (cache.size() == cacheSize)
       {
            int k = list.getHeadKey();
            auto it = cache.find(k);
            assert(it != cache.end());
            std::cout << "Erasing " << k << " from cache.\n\n";
            cache.erase(it);
            cache[key] = ptr;
            list.updateHead(); 
       }
       else
       {
            cache[key] = ptr;
       }  
    }
}
