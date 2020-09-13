#ifndef DATASTRUCT_LINKEDLIST_H
#define DATASTRUCT_LINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    T e;
    Node* next;

    Node(const T& e, Node* next): e(e), next(next) {}
    Node(const T& e): e(e), next(nullptr) {}
    Node(): next(nullptr) {}

};

template <class T>
ostream& operator << (ostream& os, const Node<T>& n) {
    cout << n.e;
    return os;
}


/*
    LinkedList
    add         O(n)
    addFirst    O(1)
    addLast     O(n)

    remove      O(n)
    removeFirst O(1)
    removeLast  O(n)

    set         O(n)

    get         O(n)
    contains    O(n)
*/
template <class T>
class LinkedList {
private:
    Node<T>* dummyhead;
    int size;

public:
    LinkedList() {
        this->dummyhead = new Node<T>();
        this->size = 0;
    }
    // TODO: 需要删除所有节点
    // ~LinkedList() { delete head; }

    // 获取链表元素个数
    int getSize() const { return size; }
    // 判断链表是否为空
    bool isEmpty() const { return size == 0; }

    // 在链表头添加新元素e
    void addFirst(const T& e); 

    // 在链表index(0-based)位置添加新元素e
    // 链表中不常用的一个操作
    void add(const int index, const T& e);

    // 获取链表index(0-based)位置的元素
    T& get(const int index) const;

    // 获取链表第一个元素
    T& getFirst() const;

    // 获取链表最后一个元素
    T& getLast() const;

    // 修改链表index(0-based)位置的元素为e
    // 链表中不常用的一个操作
    void set(const int index, const T& e);

    // 查看链表中是否有元素e
    bool contains(const T& e) const;

    // 删除链表index(0-based)位置的元素
    T remove(const int index);

    // 删除链表开头的元素
    T removeFirst();

    // 删除链表结尾的元素
    T removeLast();
};

template <class T>
inline void
LinkedList<T>::add(const int index, const T& e) {
    if(index < 0 || index > size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    Node<T>* prev = dummyhead;
    for(int i = 0; i < index; ++i) {
        prev = prev->next;
    }

    // Node<T>* node = new Node<T>(e);
    // node->next = prev->next;
    // prev->next = node;

    prev->next = new Node<T>(e, prev->next);

    size++;
}

template <class T>
inline void
LinkedList<T>::addFirst(const T& e) {
    add(0 ,e);
}

template <class T>
inline T&
LinkedList<T>::get(const int index) const {
    if(index < 0 || index >= size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    Node<T>* current = dummyhead->next;
    for(int i = 0; i < index; ++i) {
        current = current->next;
    }
    
    return current->e;    
}

template <class T>
inline T&
LinkedList<T>::getFirst() const {
    return get(0);
}

template <class T>
inline T&
LinkedList<T>::getLast() const {
    return get(getSize() - 1);
}

template <class T>
inline void
LinkedList<T>::set(const int index, const T& e) {
    if(index < 0 || index >= size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    Node<T>* current = dummyhead->next;
    for(int i = 0; i < index; ++i) {
        current = current->next;
    }
    
    current->e = e;    
}

template <class T>
inline bool
LinkedList<T>::contains(const T& e) const {
    Node<T>* current = dummyhead->next;
    while (current != nullptr) {
        if(current->e == e)
            return true;
        current = current->next;
    }
    return false;
}

template <class T>
inline T
LinkedList<T>::remove(const int index) {
    if(index < 0 || index >= size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    Node<T>* prev = dummyhead;
    for(int i = 0; i < index; ++i) {
        prev = prev->next;
    }

    Node<T>* retNode = prev->next;

    prev->next = retNode->next;
    retNode->next = nullptr;
    size--;

    T ret = retNode->e;
    delete retNode;

    return ret;
}

template <class T>
inline T
LinkedList<T>::removeFirst() {
    return remove(0);
}

template <class T>
inline T
LinkedList<T>::removeLast() {
    return remove(getSize() - 1);
}

template <class T>
ostream& operator << (ostream& os, const LinkedList<T>& list) {
    // for(Node<T>* current = dummyhead->next; current != nullptr; current = current->next)
    //     cout << list.get(i) << "->";

    // Node<T>* current = dummyhead->next;
    // while (current != nullptr) {
    //     cout << list.get(i) << "->";
    //     current = current->next;
    // }

    for(int i = 0; i < list.getSize(); ++i)
        cout << list.get(i) << "->";
    cout << "NULL";
    return os;
}

#endif /* DATASTRUCT_LINKEDLIST_H */