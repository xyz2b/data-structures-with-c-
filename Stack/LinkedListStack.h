#ifndef DATASTRUCT_LINKEDLISTSTACK_H
#define DATASTRUCT_LINKEDLISTSTACK_H

#include "./Stack.h"
#include "../LinkedList/LinkedList.h"
#include "../Exception.h"

/*
    LinkedListStack
    push        O(1) 均摊
    pop         O(1) 均摊
    peek        O(1)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class LinkedListStack final : public Stack<T>
{
private:
    LinkedList<T>* list;
public:
    LinkedListStack();
    ~LinkedListStack();

    int getSize() override;

    bool isEmpty() override;

    T& peek() override;

    void push(T& e) override;

    T pop() override;
};

template <class T>
inline
LinkedListStack<T>::LinkedListStack() {
    list = new LinkedList<T>();
}

template <class T>
inline
LinkedListStack<T>::~LinkedListStack() {
    delete list;
}

template<class T>
inline int
LinkedListStack<T>::getSize() {
    return list->getSize();
}

template<class T>
inline bool
LinkedListStack<T>::isEmpty() {
    return list->isEmpty();
}

template<class T>
inline T&
LinkedListStack<T>::peek() {
    return list->getFirst();
}

template<class T>
inline void
LinkedListStack<T>::push(T& e) {
    list->addFirst(e);
}

template<class T>
inline T
LinkedListStack<T>::pop() {
    return list->removeFirst();
}

// template <class T>
// ostream& operator << (ostream& os, const LinkedListStack<T>& stack) {
//     cout << "Stack: size = " <<  stack.getSize() << ", capacity = " << stack.getCapacity() << endl;
//     cout << "[";
//     for(int i = 0; i < stack.getSize(); ++i) {
//         cout << stack.LinkedList.get(i);
//         if (i != stack.getSize() - 1)
//             cout << ", ";
//     }
//     cout << "] top";
//     return os;
// }

#endif /* DATASTRUCT_LINKEDLISTSTACK_H */