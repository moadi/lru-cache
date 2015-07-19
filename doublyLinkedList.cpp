#include "doublyLinkedList.h"
#include <cassert>

CacheEntry* DoublyLinkedList::addToList(int key, char val)
{
    // if this is the first element in the list
    if (head == nullptr)
    {
        CacheEntry* ptr = new CacheEntry(key, val);
        head = ptr;
        tail = ptr;
        return ptr;
    }
    else
    {
        CacheEntry* ptr = new CacheEntry(key, val);
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
        return ptr;
    }
}

void DoublyLinkedList::moveNodeToTail(CacheEntry* ptr)
{
    assert(ptr != nullptr);
    if (ptr == tail)
        return;
    
    // update the pointers for the objects
    // adjacent to ptr
    if (ptr->prev != nullptr)
        ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;

    // now update the tail
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;
}

void DoublyLinkedList::updateHead()
{
    CacheEntry* lru = head;
    
    head = head->next;
    head->prev = nullptr;
    delete lru;
}

DoublyLinkedList::~DoublyLinkedList()
{
    CacheEntry* ptr = head;
    while (ptr != nullptr)
    {
        CacheEntry* tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
}
