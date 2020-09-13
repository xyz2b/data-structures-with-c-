#ifndef DATASTRUCT_LOOPQUEUE_H
#define DATASTRUCT_LOOPQUEUE_H

#include "./Queue.h"
#include "../Exception.h"

/*
    LoopQueue
    enqueue     O(1) 均摊
    dequeue     O(1) 均摊
    front       O(1)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class LoopQueue final : public Queue<T>
{
private:
    int capacity;
    T* data;

    int front;
    int tail;

    void _resize(int newCapacity);
public:
    LoopQueue();
    LoopQueue(const int capacity);
    ~LoopQueue();

    int getCapacity() override;

    int getSize() override;

    bool isEmpty() override;

    T& getFront() override;

    void enqueue(T& e) override;

    T dequeue() override;
};

template <class T>
inline
LoopQueue<T>::LoopQueue() {
    this->data = new T[11];
    this->capacity = 10;
    this->front = 0;
    this->tail = 0;
}

template <class T>
inline
LoopQueue<T>::LoopQueue(const int capacity) {
    this->data = new T[capacity + 1];
    this->capacity = capacity;
    this->front = 0;
    this->tail = 0;
}

template <class T>
inline
LoopQueue<T>::~LoopQueue() {
    delete[] data;
}

template<class T>
inline int
LoopQueue<T>::getCapacity() {
    return capacity;
}

template<class T>
inline int
LoopQueue<T>::getSize() {
    return ((tail - front) + (capacity + 1)) % (capacity + 1);
}

template<class T>
inline bool
LoopQueue<T>::isEmpty() {
    return front == tail;
}

template<class T>
inline T&
LoopQueue<T>::getFront() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    return data[front];
}

template<class T>
inline void
LoopQueue<T>::enqueue(T& e) {
    if((tail + 1) % (capacity + 1) == front)
        _resize(capacity * 2);

    data[tail] = e;

    tail = (tail + 1) % (capacity + 1);
}

template<class T>
inline T
LoopQueue<T>::dequeue() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    T ret = data[front];

    front = (front + 1) % (capacity + 1);

    if(getSize() == capacity / 4 && capacity / 2 != 0)
        _resize(capacity / 2); 

    return ret;
}

template <class T> void 
LoopQueue<T>::_resize(int newCapacity) {
    T* newData = new T[newCapacity + 1];

    if(tail > front)
        memcpy(newData, data + front, getSize() * sizeof(T));
    else {
        // 将 data[front, capacity+1) --> newData[((newCapacity + 1) - ((capacity + 1 - front))), newCapacity)
        memcpy(newData, data + front, (capacity + 1 - front) * sizeof(T));
        // 将 data[0,tail) --> newData[0, tail)
        memcpy(newData + (capacity + 1 - front), data, tail * sizeof(T));
    }

    tail = getSize();
    front = 0;

    delete[] data;
    data = newData;
    capacity = newCapacity; 
}

// template <class T>
// ostream& operator << (ostream& os, const LoopQueue<T>& stack) {
//     cout << "Stack: size = " <<  stack.getSize() << ", capacity = " << stack.getCapacity() << endl;
//     cout << "[";
//     for(int i = 0; i < stack.getSize(); ++i) {
//         cout << stack.data.get(i);
//         if (i != stack.getSize() - 1)
//             cout << ", ";
//     }
//     cout << "] top";
//     return os;
// }

#endif /* DATASTRUCT_LOOPQUEUE_H */