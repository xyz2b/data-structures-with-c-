#ifndef DATASTRUCT_STACK_H
#define DATASTRUCT_STACK_H

#include <ctime>
#include <cstdlib>
/*
    栈(Stack)
    LIFO(Last In First Out, 后进先出)

    stack<E>
    void push(E)       
    E pop()
    E peek()
    int getSize()
    boolean isEmpty()
    int getCapacity()
*/
/*
    如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。纯虚函数是通过在声明中使用 "= 0" 来指定的
    设计抽象类（通常称为 ABC）的目的，是为了给其他类提供一个可以继承的适当的基类。抽象类不能被用于实例化对象，它只能作为接口使用。如果试图实例化一个抽象类的对象，会导致编译错误
*/

template<class T>
class Stack
{
public:
    virtual void push(T&) = 0;
    virtual T pop() = 0;
    virtual T& peek() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    // virtual int getCapacity() = 0;
protected:
    // 将派生类标记为最终版本(final)，以及对基类中的析构函数进行保护(~Stack() = default)
    ~Stack() = default;
};

double testStack(Stack<int>* stack, int opCount) {
    clock_t start_time = clock();

    int r = rand();

    for(int i = 0; i < opCount; ++i)
        stack->push(r);

    for(int i = 0; i < opCount; ++i)
        stack->pop();

    clock_t end_time = clock();

    return (end_time - start_time)/(double)CLOCKS_PER_SEC;
}

#endif /* DATASTRUCT_STACK_H */