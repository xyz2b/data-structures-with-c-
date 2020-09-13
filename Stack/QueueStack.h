#ifndef DATASTRUCT_QUEUESTACK_H
#define DATASTRUCT_QUEUESTACK_H

#include "./Stack.h"
#include "../Exception.h"
#include "../Queue/LoopQueue.h"

/*
    QueueStack
    push        O(1) 均摊
    pop         O(n) 均摊
    peek        O(n)
    getSize     O(1)
    isEmpty     O(1)    
*/
template <class T>
class QueueStack final : public Stack<T>
{
private:
    LoopQueue<T>* queue;
public:
    QueueStack();
    QueueStack(const int capacity);
    ~QueueStack();

    int getCapacity() override;

    int getSize() override;

    bool isEmpty() override;

    T& peek() override;

    void push(T& e) override;

    T pop() override;
};

template <class T>
inline
QueueStack<T>::QueueStack() {
    queue = new LoopQueue<T>();
}

template <class T>
inline
QueueStack<T>::QueueStack(const int capacity) {
    queue = new LoopQueue<T>(capacity);
}

template <class T>
inline
QueueStack<T>::~QueueStack() {
    delete queue;
}

template<class T>
inline int
QueueStack<T>::getCapacity() {
    return queue->getCapacity();
}

template<class T>
inline int
QueueStack<T>::getSize() {
    return queue->getSize();
}

template<class T>
inline bool
QueueStack<T>::isEmpty() {
    return queue->isEmpty();
}

template<class T>
inline T&
QueueStack<T>::peek() {
    return queue->getFront();
}

template<class T>
inline void
QueueStack<T>::push(T& e) {
    queue->enqueue(e);
    
    int len = getSize();

    // 把新加的元素放到队列的首部，相当于将栈顶元素放在队列的首部，就可以通过队列的方法直接取得栈顶元素
    for(int i = 1; i < len; ++i) {
        T elem = queue->dequeue();
        queue->enqueue(elem);
    } 
}

template<class T>
inline T
QueueStack<T>::pop() {
    return queue->dequeue();
}

// template <class T>
// ostream& operator << (ostream& os, const QueueStack<T>& stack) {
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

#endif /* DATASTRUCT_QUEUESTACK_H */