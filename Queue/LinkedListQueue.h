#ifndef DATASTRUCT_LINKEDLISTQUEUE_H
#define DATASTRUCT_LINKEDLISTQUEUE_H

#include "./Queue.h"
#include "../LinkedList/LinkedList.h"
#include "../Exception.h"

/*
    LinkedListQueue
    enqueue     O(1) 均摊
    dequeue     O(n)
    front       O(1)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class LinkedListQueue final : public Queue<T>
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedListQueue(): head(nullptr), tail(nullptr), size(0) {};
    // ~LinkedListQueue();

    int getSize() override;

    bool isEmpty() override;

    T& getFront() override;

    void enqueue(T& e) override;

    T dequeue() override;
};

template<class T>
inline int
LinkedListQueue<T>::getSize() {
    return size;
}

template<class T>
inline bool
LinkedListQueue<T>::isEmpty() {
    return size == 0;
}

template<class T>
inline T&
LinkedListQueue<T>::getFront() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    return head->e;
}

template<class T>
inline void
LinkedListQueue<T>::enqueue(T& e) {
    if(tail == nullptr) {
        tail = new Node(e);
        head = tail;
    } else {
        tail->next = new Node(e);
        tail = tail->next;
    }
    size++;
}

template<class T>
inline T
LinkedListQueue<T>::dequeue() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    Node<T>* retNode = head;
    head = head->next;
    retNode->next = nullptr;
    T ret = retNode->e;
    delete retNode;

    if(head == nullptr)
        tail = nullptr;

    size--;

    return ret;
}

// template <class T>
// ostream& operator << (ostream& os, const LinkedListQueue<T>& stack) {
//     cout << "Stack: size = " <<  stack.getSize() << ", capacity = " << stack.getCapacity() << endl;
//     cout << "[";
//     for(int i = 0; i < stack.getSize(); ++i) {
//         cout << stack.array.get(i);
//         if (i != stack.getSize() - 1)
//             cout << ", ";
//     }
//     cout << "] top";
//     return os;
// }

#endif /* DATASTRUCT_LINKEDLISTQUEUE_H */