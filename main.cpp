#include <iostream>
#include "LinearSearch/LinearSearch.h"
#include "Student.h"
#include "SelectionSort/SelectionSort.h"
#include "ArrayGenerator.h"
#include "SortingHelper.h"
#include "Array/Array.h"
#include "Stack/ArrayStack.h"
#include "Queue/ArrayQueue.h"
#include "Queue/LoopQueue.h"
#include "Queue/Queue.h"
#include "Deque/Deque.h"
#include "Stack/QueueStack.h"
#include "Queue/StackQueue.h"
#include "LinkedList/LinkedList.h"
#include "Stack/LinkedListStack.h"
#include "Queue/LinkedListQueue.h"
#include "leetcode/sum.h"
#include "Recursion/Sum.h"
#include "leetcode/removeLinkedListElements.h"
#include "MergeSort/MergeSort.h"

#include <ctime>
#include <iomanip>
#include <cstring>

using namespace std;

/*
 * 递归语句之前的语句执行顺序是从递归最外层到递归最内层
 * 递归语句之后的语句执行顺序是从递归最内层到递归最外层
 */

int main(){

    // int n = 10;
    // int* data = ArrayGenerator::generateOrderedArray(n);

    // int res = LinearSearch<int>::search(16, data, sizeof(data)/sizeof(data[0]));
    // cout << res << endl;

    // int res2 = LinearSearch<int>::search(666, data, sizeof(data)/sizeof(data[0]));
    // cout << res2 << endl;

    // Student students[] = {Student("Alice", 98),Student("bobo", 100),Student("xyz",60)};
    // Student xyz = Student("Xyz", 98);
    // int res3 = LinearSearch<Student>::search(xyz, students, sizeof(students)/sizeof(students[0]));
    // cout << res3 << endl;

    // SelectionSort<int>::sort(data, sizeof(data)/sizeof(data[0]));
    // for(int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
    //     cout << data[i] << endl;
    // }

    // SelectionSort<Student>::sort(students, sizeof(students)/sizeof(students[0]));
    // for(int i = 0;i < int(sizeof(students)/sizeof(students[0])); ++i) {
    //     cout << students[i] << endl;
    // }

    // int data[3] = {1000, 10000, 100000};
    // for(int i : data) {
    //     cout << "Random Array" << endl;
    //     int* data = ArrayGenerator::generateRandomArray(i, i);
    //     // int data2[i];
    //     // memcpy(data2, data, i);

    //     // SortingHelper<int>::sortTest("SelectionSort", data, i);
    //     // SortingHelper<int>::sortTest("InsertionSort", data2, i);
    //     SortingHelper<int>::sortTest("InsertionSort3", data, i);

    //     // cout << "Ordered Array" << endl;
    //     // data = ArrayGenerator::generateOrderedArray(i);
    //     // memcpy(data2, data, i);

    //     // SortingHelper<int>::sortTest("SelectionSort", data, i);
    //     // SortingHelper<int>::sortTest("InsertionSort", data2, i);
    // }

    // Array<int>* a = new Array<int>();

    // for(int i = 0; i < 10; ++i)
    //     a->addLast(i);

    // cout << *a << endl;

    // cout << a->getCapacity() << endl;
    // cout << a->getSize() << endl;
    // cout << a->isEmpty() << endl;

    // a->add(2, 100);

    // cout << *a << endl;

    // cout << a->getCapacity() << endl;
    // cout << a->getSize() << endl;
    // cout << a->isEmpty() << endl;

    // cout << a->get(2) << endl;


    // a->set(2, 300);
    // cout << a->getCapacity() << endl;
    // cout << a->getSize() << endl;
    // cout << a->isEmpty() << endl;

    // cout << a->get(12) << endl;

    // int ret = a->remove(2);
    // cout << ret << endl;

    // cout << a->getCapacity() << endl;
    // cout << a->getSize() << endl;
    // cout << a->isEmpty() << endl;
    // cout << *a << endl;


    // int index = a->removeAlement(3);
    // cout << index << endl;
    // cout << a->getCapacity() << endl;
    // cout << a->getSize() << endl;
    // cout << a->isEmpty() << endl;
    // cout << *a << endl;


    // a->addLast(111);
    // cout << *a << endl;

    // for(int i = 0; i < 5; ++i)
    //     a->removeLast();
    // cout << *a << endl;
    // a->removeLast();
    // cout << *a << endl;

    // for(int i = 0; i < 5; ++i)
    //     a->addLast(i);
    // cout << *a << endl;
    // a->addLast(6);
    // cout << *a << endl;

    // delete a;

    // ArrayStack<int>* stack = new ArrayStack<int>();
    // for(int i = 0; i < 10; ++i)
    //     stack->push(i);

    // cout << stack->getSize() << endl;
    // cout << endl;

    // for(int i = 0; i < 5; ++i) {
    //     cout << stack->pop() << endl;
    // }

    // cout << endl;
    // cout << stack->getSize() << endl;

    // for(int i = 100; i < 105; ++i) {
    //     stack->push(i);
    // }

    // cout << endl;
    // cout << stack->getSize() << endl;
    // cout << stack->peek() << endl;    

    // delete stack;

    // 使用基类指针删除派生实例是未定义的行为，所以本程序通过 将派生类(ArrayStack)标记为最终版本(final)，以及对基类中的析构函数进行保护(~Stack() = default) 限制了这种行为，如果这样使用会抛出异常
    // Stack<int>* s = new ArrayStack<int>();
    // delete s;

    // LoopQueue<int>* q = new LoopQueue<int>();

    // for(int i = 0; i < 10; ++i) {
    //     q->enqueue(i);
    // }
    // cout << q->getCapacity() << endl;
    // cout << q->getSize() << endl;

    // for(int i = 0; i < 5; ++i) {
    //     cout << q->dequeue() << endl;
    // }

    // cout << endl;
    // for(int i = 0; i < 11; ++i) {
    //     q->enqueue(i);
    // }

    // cout << q->getCapacity() << endl;
    // cout << q->getSize() << endl;

    // for(int i = 0; i < 12; ++i) {
    //     cout << q->dequeue() << endl;
    // }

    // cout << q->getCapacity() << endl;
    // cout << q->getSize() << endl;
    // cout << q->getFront() << endl;

    // return 0;

    // int opCount = 100000;

    // ArrayQueue<int>* arrayQueue = new ArrayQueue<int>(opCount);
    // double time1 = testQueue(arrayQueue, opCount);
    // cout << "ArrayQueue, time: " << time1 << "s" << endl;

    // LoopQueue<int>* loopQueue = new LoopQueue<int>(opCount);
    // double time2 = testQueue(loopQueue, opCount);
    // cout << "ArrayQueue, time: " << time2 << "s" << endl;  

    // Deque<int>* d = new Deque<int>();

    // for(int i = 0; i < 5; ++i) {
    //     d->addFront(i);
    // }
    // cout << d->getCapacity() << endl;
    // cout << d->getSize() << endl;

    // for(int i = 0; i < 6; ++i) {
    //     d->addLast(i);
    // }
    // cout << d->getCapacity() << endl;
    // cout << d->getSize() << endl;


    // for(int i = 0; i < 5; ++i) {
    //     cout << d->removeFront() << endl;
    // }
    // cout << d->getCapacity() << endl;
    // cout << d->getSize() << endl;

    // for(int i = 0; i < 6; ++i) {
    //     cout << d->removeLast() << endl;
    // }
    // cout << d->getCapacity() << endl;
    // cout << d->getSize() << endl;


    // QueueStack<int>* stack = new QueueStack<int>();
    // for(int i = 0; i < 10; ++i)
    //     stack->push(i);

    // cout << stack->getSize() << endl;
    // cout << stack->peek() << endl;
    // cout << endl;

    // for(int i = 0; i < 5; ++i) {
    //     cout << stack->pop() << endl;
    // }
    // cout << stack->peek() << endl;

    // cout << endl;
    // cout << stack->getSize() << endl;

    // for(int i = 100; i < 105; ++i) {
    //     stack->push(i);
    // }

    // cout << endl;
    // cout << stack->getSize() << endl;
    // cout << stack->peek() << endl;

    // cout << endl;
    // for(int i = 0; i < 10; ++i) {
    //     cout << stack->pop() << endl;
    // }    

    // delete stack;


    // StackQueue<int>* queue = new StackQueue<int>();

    // for(int i = 0; i < 10; ++i) {
    //     queue->enqueue(i);
    // }
    // cout << queue->getCapacity() << endl;
    // cout << queue->getSize() << endl;

    // for(int i = 0; i < 5; ++i) {
    //     cout << queue->dequeue() << endl;
    // }

    // cout << endl;
    // for(int i = 0; i < 11; ++i) {
    //     queue->enqueue(i);
    // }

    // cout << queue->getCapacity() << endl;
    // cout << queue->getSize() << endl;
    // cout << endl;

    // for(int i = 0; i < 12; ++i) {
    //     cout << queue->dequeue() << endl;
    // }

    // cout << queue->getCapacity() << endl;
    // cout << queue->getSize() << endl;
    // cout << queue->getFront() << endl;
    
    // delete queue;

    // LinkedList<int>* list = new LinkedList<int>();
    // for(int i = 0; i < 12; ++i)
    //     list->addFirst(i);
    // cout << list->get(0) << endl;
    // cout << *list << endl;

    // cout << list->remove(1) << endl;
    // cout << *list << endl;


    // cout << list->removeFirst() << endl;
    // cout << *list << endl;

    // LinkedListStack<int>* stack = new LinkedListStack<int>();
    // for(int i = 0; i < 12; ++i)
    //     stack->push(i);

    // cout << stack->peek() << endl;
    // for(int i = 0; i < 12; ++i)
    //     cout << stack->pop() << endl;

    // int opCount = 1000;

    // ArrayStack<int>* arrayStack = new ArrayStack<int>();
    // double time1 = testStack(arrayStack, opCount);
    // cout << "ArrayStack, time: " << fixed << setprecision(10) << time1 << "s" << endl;

    // LinkedListStack<int>* linkedListStack = new LinkedListStack<int>();
    // double time2 = testStack(linkedListStack, opCount);
    // cout << "LinkedListStack, time: " << fixed << setprecision(10) << time2 << "s" << endl;  

    // LinkedListQueue<int>* queue = new LinkedListQueue<int>();

    // for(int i = 0; i < 10; ++i) {
    //     queue->enqueue(i);
    // }
    // cout << queue->getSize() << endl;

    // for(int i = 0; i < 5; ++i) {
    //     cout << queue->dequeue() << endl;
    // }

    // sumSolution s = sumSolution();

    // int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9};

    // cout << s.sum(data, 10) << endl;


    // int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9};

    // cout << SumR::sum(data, 10) << endl;
    

    // int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Node<int>* n = new Node<int>(data, 10);

    // cout << n << endl;

    // RemoveElementsSolution<int>::removeElement(n, 2, 0);

    // cout << n << endl;


    // LinkedList<int>* listR = new LinkedList<int>();
    // for(int i = 0; i < 12; ++i)
    //     listR->addR(i, i);
    // cout << *listR << endl;

    // listR->addR(5, 100);
    // cout << *listR << endl;

    // LinkedList<int>* list = new LinkedList<int>();
    // for(int i = 0; i < 12; ++i)
    //     list->add(i, i);
    // cout << *list << endl;
    // list->addR(5, 100);
    // list->addR(0, 100);
    // cout << *list << endl;

    // cout << list->getR(5) << endl;
    // list->setR(5,10000);
    // cout << list->getR(5) << endl;
    // cout << *list << endl;


    // cout << list->removeR(5) << endl;
    // cout << *list << endl;

    // cout << list->removeR(11) << endl;
    // cout << *list << endl;

    // cout << list->removeR(0) << endl;
    // cout << *list << endl;

    // list->removeElement(1);
    // cout << *list << endl;

    // int arr[10] = {3, 5, 6, 1, 0, 10, 7, 0, 9, 0};

    // MergeSort<int>::sort(arr, 10);

    // for(int i : arr) {
    //     cout << i << ", ";
    // }

    // cout << endl;

    int n[3] = {1000, 10000, 100000};
    for(int i : n) {
        cout << "Random Array" << endl;
        int* data = ArrayGenerator::generateRandomArray(i, i);
        // int* data = ArrayGenerator::generateOrderedArray(i);
        int* data2 = ArrayGenerator::copyArray(data, i);
        int* data3 = ArrayGenerator::copyArray(data, i);
        // SortingHelper<int>::sortTest("MergeSort", data, i);
        // SortingHelper<int>::sortTest("MergeSort2", data2, i);
        // SortingHelper<int>::sortTest("MergeSort3", data3, i);
        // SortingHelper<int>::sortTest("MergeSort4", data3, i);
        SortingHelper<int>::sortTest("MergeSortBU", data2, i);
        SortingHelper<int>::sortTest("MergeSortBU2", data3, i);
    }
    return 0;
}


