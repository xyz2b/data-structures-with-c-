#ifndef DATASTRUCT_ARRAYQUEUE_H
#define DATASTRUCT_ARRAYQUEUE_H

#include "./Queue.h"
#include "../Array/Array.h"
#include "../Exception.h"

/*
    ArrayQueue
    enqueue     O(1) 均摊
    dequeue     O(n)
    front       O(1)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class ArrayQueue final : public Queue<T>
{
private:
    Array<T>* array;
public:
    ArrayQueue();
    ArrayQueue(const int capacity);
    ~ArrayQueue();

    int getCapacity() override;

    int getSize() override;

    bool isEmpty() override;

    T& getFront() override;

    void enqueue(T& e) override;

    T dequeue() override;
};

template <class T>
inline
ArrayQueue<T>::ArrayQueue() {
    array = new Array<T>();
}

template <class T>
inline
ArrayQueue<T>::ArrayQueue(const int capacity) {
    array = new Array<T>(capacity);
}

template <class T>
inline
ArrayQueue<T>::~ArrayQueue() {
    delete array;
}

template<class T>
inline int
ArrayQueue<T>::getCapacity() {
    return array->getCapacity();
}

template<class T>
inline int
ArrayQueue<T>::getSize() {
    return array->getSize();
}

template<class T>
inline bool
ArrayQueue<T>::isEmpty() {
    return array->isEmpty();
}

template<class T>
inline T&
ArrayQueue<T>::getFront() {
    return array->getFirst();
}

template<class T>
inline void
ArrayQueue<T>::enqueue(T& e) {
    array->addLast(e);
}

template<class T>
inline T
ArrayQueue<T>::dequeue() {
    return array->removeFirst();
}

// template <class T>
// ostream& operator << (ostream& os, const ArrayQueue<T>& stack) {
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

#endif /* DATASTRUCT_ARRAYQUEUE_H */