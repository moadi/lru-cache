#include <iostream>
#include "lruCache.h"

int main(int argc, const char * argv[]) 
{
    LRUCache myCache(2);
    int key;
    char data;
    
    while (1)
    {
        std::cout << "Enter key [integer]: ";
        std::cin >> key;
        if (key == -1)
            break;
        std::cout << "Enter value [char]: ";
        std::cin >> data;
        myCache.set(key, data);
        std::cout << "\n\n";
    }
    
    return 0;
}
