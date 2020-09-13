#ifndef DATASTRUCT_ARRAYSTACK_H
#define DATASTRUCT_ARRAYSTACK_H

#include "./Stack.h"
#include "../Array/Array.h"
#include "../Exception.h"

/*
    ArrayStack
    push        O(1) 均摊
    pop         O(1) 均摊
    peek        O(1)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class ArrayStack final : public Stack<T>
{
private:
    Array<T>* array;
public:
    ArrayStack();
    ArrayStack(const int capacity);
    ~ArrayStack();

    int getCapacity();

    int getSize() override;

    bool isEmpty() override;

    T& peek() override;

    void push(T& e) override;

    T pop() override;
};

template <class T>
inline
ArrayStack<T>::ArrayStack() {
    array = new Array<T>();
}

template <class T>
inline
ArrayStack<T>::ArrayStack(const int capacity) {
    array = new Array<T>(capacity);
}

template <class T>
inline
ArrayStack<T>::~ArrayStack() {
    delete array;
}

template<class T>
inline int
ArrayStack<T>::getCapacity() {
    return array->getCapacity();
}

template<class T>
inline int
ArrayStack<T>::getSize() {
    return array->getSize();
}

template<class T>
inline bool
ArrayStack<T>::isEmpty() {
    return array->isEmpty();
}

template<class T>
inline T&
ArrayStack<T>::peek() {
    return array->getLast();
}

template<class T>
inline void
ArrayStack<T>::push(T& e) {
    array->addLast(e);
}

template<class T>
inline T
ArrayStack<T>::pop() {
    return array->removeLast();
}

// template <class T>
// ostream& operator << (ostream& os, const ArrayStack<T>& stack) {
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

#endif /* DATASTRUCT_ARRAYSTACK_H */