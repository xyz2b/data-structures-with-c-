// 1.循环队列的思想

#ifndef DATASTRUCT_DEQUE_H
#define DATASTRUCT_DEQUE_H

#include "../Exception.h"

/*
    Deque (使用size成员变量，不浪费那一个数组空间)
    addLast
    addFront
    removeLast
    removeFront
    getLast
    getFront
*/
template <class T>
class Deque
{
private:
    int capacity;
    T* data;
    int size;
    
    int front;
    int tail;

    void _resize(int newCapacity);
public:
    Deque();
    Deque(const int capacity);
    ~Deque();

    int getCapacity();

    int getSize();

    bool isEmpty();

    T& getFront();
    
    T& getLast();

    void addLast(T& e);

    void addFront(T& e);

    T removeLast();

    T removeFront();
};

template <class T>
inline
Deque<T>::Deque() {
    this->data = new T[10];
    this->capacity = 10;
    this->front = 0;
    this->tail = 0;
    this->size = 0;
}

template <class T>
inline
Deque<T>::Deque(const int capacity) {
    this->data = new T[capacity];
    this->capacity = capacity;
    this->front = 0;
    this->tail = 0;
    this->size = 0;
}

template <class T>
inline
Deque<T>::~Deque() {
    delete[] data;
}

template<class T>
inline int
Deque<T>::getCapacity() {
    return capacity;
}

template<class T>
inline int
Deque<T>::getSize() {
    return size;
}

template<class T>
inline bool
Deque<T>::isEmpty() {
    return size == 0;
}

template<class T>
inline T&
Deque<T>::getFront() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    return data[front];
}

template<class T>
inline T&
Deque<T>::getLast() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    int index = tail == 0 ? getCapacity() - 1 : tail - 1;

    return data[index];
}

template<class T>
inline void
Deque<T>::addLast(T& e) {
    if(size == capacity)
        _resize(capacity * 2);

    data[tail] = e;

    tail = (tail + 1) % capacity;
    
    size++;
}

template<class T>
inline void
Deque<T>::addFront(T& e) {
    if(size == capacity)
        _resize(capacity * 2);

    // 首先确定添加新元素的索引位置
    // 这个位置是 front - 1的地方
    // 但是要注意，如果front == 0，新的位置就是capacity - 1的位置
    // 同理，不管是tail还是front，如果新的位置是-1之后的位置，当其等于0时，新的位置就是capacity - 1的位置
    front = front == 0 ? getCapacity() - 1 : front - 1;

    data[front] = e;

    size++;
}

template<class T>
inline T
Deque<T>::removeFront() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    T ret = data[front];
    front = (front + 1) % capacity;
    size--;

    if(getSize() == capacity / 4 && capacity / 2 != 0)
        _resize(capacity / 2); 

    return ret;
}

template<class T>
inline T
Deque<T>::removeLast() {
    if(isEmpty())
        throw Exception("Queue is empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    tail = tail == 0 ? getCapacity() - 1 : tail - 1;
    T ret = data[tail];
    size--;

    if(getSize() == capacity / 4 && capacity / 2 != 0)
        _resize(capacity / 2); 

    return ret;
}

template <class T> void 
Deque<T>::_resize(int newCapacity) {
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
// ostream& operator << (ostream& os, const Deque<T>& stack) {
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

#endif /* DATASTRUCT_DEQUE_H */