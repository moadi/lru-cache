#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

#include <iostream>

struct CacheEntry
{
    int key;
    char data;
    CacheEntry* prev;
    CacheEntry* next;

    CacheEntry(int k, char v) : key(k), data(v), prev(nullptr), next(nullptr) { if(!std::isalnum(data)) readData(); }
    
    private:
        void readData()
        {
            std::cout << "Enter value: ";
            while(1)
            {
               std::cin >> data;
               if (std::isalnum(data))
                  break;
               else
                 std::cerr << "Enter a number or alphabet\n";
            }
        }
};

class DoublyLinkedList
{
    private:
        CacheEntry* head;
        CacheEntry* tail;

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) { }
        CacheEntry* addToList(int, char);
        void moveNodeToTail(CacheEntry*);
        void updateHead();        
        int getHeadKey() { return head->key; }

        ~DoublyLinkedList();
};

#endif
