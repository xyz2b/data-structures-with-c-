#ifndef DATASTRUCT_LOOPQUEUE2_H
#define DATASTRUCT_LOOPQUEUE2_H

#include "./Queue.h"
#include "../Exception.h"

/*
    LoopQueue2 (使用size成员变量，不浪费那一个数组空间)
    enqueue     O(1) 均摊
    dequeue     O(1) 均摊
    front       O(1)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class LoopQueue2 final : public Queue<T>
{
private:
    int capacity;
    T* data;
    int size;
    
    int front;
    int tail;

    void _resize(int newCapacity);
public:
    LoopQueue2();
    LoopQueue2(const int capacity);
    ~LoopQueue2();

    int getCapacity() override;

    int getSize() override;

    bool isEmpty() override;

    T& getFront() override;

    void enqueue(T& e) override;

    T dequeue() override;
};

template <class T>
inline
LoopQueue2<T>::LoopQueue2() {
    this->data = new T[10];
    this->capacity = 10;
    this->front = 0;
    this->tail = 0;
    this->size = 0;
}

template <class T>
inline
LoopQueue2<T>::LoopQueue2(const int capacity) {
    this->data = new T[capacity];
    this->capacity = capacity;
    this->front = 0;
    this->tail = 0;
    this->size = 0;
}

template <class T>
inline
LoopQueue2<T>::~LoopQueue2() {
    delete[] data;
}

template<class T>
inline int
LoopQueue2<T>::getCapacity() {
    return capacity;
}

template<class T>
inline int
LoopQueue2<T>::getSize() {
    return size;
}

template<class T>
inline bool
LoopQueue2<T>::isEmpty() {
    return size == 0;
}

template<class T>
inline T&
LoopQueue2<T>::getFront() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    return data[front];
}

template<class T>
inline void
LoopQueue2<T>::enqueue(T& e) {
    if(size == capacity)
        _resize(capacity * 2);

    data[tail] = e;

    tail = (tail + 1) % capacity;
    
    size++;
}

template<class T>
inline T
LoopQueue2<T>::dequeue() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    T ret = data[front];
    front = (front + 1) % capacity;
    size--;

    if(getSize() == capacity / 4 && capacity / 2 != 0)
        _resize(capacity / 2); 

    return ret;
}

template <class T> void 
LoopQueue2<T>::_resize(int newCapacity) {
    T* newData = new T[newCapacity];

    if(tail > front)
        memcpy(newData, data + front, getSize() * sizeof(T));
    else {
        // 将 data[front, capacity) --> newData[0, (capacity - front))
        memcpy(newData, data + front, (capacity - front) * sizeof(T));
        // 将 data[0,tail) --> newData[(capacity - front), tail)
        memcpy(newData + (capacity - front), data, tail * sizeof(T));
    }

    tail = getSize();
    front = 0;

    delete[] data;
    data = newData;
    capacity = newCapacity; 
}

// template <class T>
// ostream& operator << (ostream& os, const LoopQueue2<T>& stack) {
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

#endif /* DATASTRUCT_LOOPQUEUE2_H */