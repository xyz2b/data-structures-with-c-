#ifndef DATASTRUCT_StackQueue_H
#define DATASTRUCT_StackQueue_H

#include "./Queue.h"
#include "../Stack/ArrayStack.h"
#include "../Exception.h"

/*
    StackQueue
    enqueue     O(1) 均摊
    dequeue     O(n)
    front       O(n)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class StackQueue final : public Queue<T>
{
private:
    ArrayStack<T>* stack1;
    ArrayStack<T>* stack2;
    T front;
public:
    StackQueue();
    StackQueue(const int capacity);
    ~StackQueue();

    int getCapacity() override;

    int getSize() override;

    bool isEmpty() override;

    T& getFront() override;

    void enqueue(T& e) override;

    T dequeue() override;
};

template <class T>
inline
StackQueue<T>::StackQueue() {
    stack1 = new ArrayStack<T>();
    stack2 = new ArrayStack<T>();
}

template <class T>
inline
StackQueue<T>::StackQueue(const int capacity) {
    stack1 = new ArrayStack<T>(capacity);
    stack2 = new ArrayStack<T>(capacity);
}

template <class T>
inline
StackQueue<T>::~StackQueue() {
    delete stack1;
    delete stack2;
}

template<class T>
inline int
StackQueue<T>::getCapacity() {
    return stack1->getCapacity();
}

template<class T>
inline int
StackQueue<T>::getSize() {
    return stack1->getSize() + stack2->getSize();
}

template<class T>
inline bool
StackQueue<T>::isEmpty() {
    return stack1->isEmpty() && stack2->isEmpty();
}

template<class T>
inline T&
StackQueue<T>::getFront() {
    // stack2不为空时，stack2的栈顶就是整个队列的队首
    if(!stack2->isEmpty())
        return stack2->peek();
    
    return front;
}

template<class T>
inline void
StackQueue<T>::enqueue(T& e) {
    if(stack1->isEmpty())
        front = e;
    stack1->push(e);
}

template<class T>
inline T
StackQueue<T>::dequeue() {
    // stack2的栈顶就是整个队列的队首，所以stack2不为空队首就在stack2中
    if(!stack2->isEmpty())
        return stack2->pop();

    // 将stack1中的元素除了需要被出队的第一个元素之外的所有元素导入stack2中，且顺序正好反过来，即stack2的栈顶就是队列的队首
    while(stack1->getSize() > 1) {
        T elem = stack1->pop();
        stack2->push(elem);
    }
        
    return stack1->pop();
    
}

// template <class T>
// ostream& operator << (ostream& os, const StackQueue<T>& stack) {
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

#endif /* DATASTRUCT_StackQueue_H */