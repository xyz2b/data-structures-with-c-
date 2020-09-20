#ifndef DATASTRUCT_REVERSELIST_H
#define DATASTRUCT_REVERSELIST_H

#include "../LinkedList/LinkedList.h"

template <class T>
class reverseList
{
private:

public:
    Node<T>* reverseListR(Node<T>* head);
    Node<T>* reverseListNR(Node<T>* head);
};

template<class T>
inline Node<T>* 
reverseList<T>::reverseListR(Node<T>* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node<T>* res = reverseListR(head->next);

    head->next->next = head;
    head->next = nullptr;

    return res;
}

template<class T>
inline Node<T>* 
reverseList<T>::reverseListNR(Node<T>* head) {
    Node<T>* prev = nullptr; 
    Node<T>* cur = head;
    while (cur != nullptr)
    {
        Node<T>* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
    
}

#endif