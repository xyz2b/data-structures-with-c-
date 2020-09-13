#ifndef DATASTRUCT_DOUBLYLINKEDLIST_H
#define DATASTRUCT_DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
class DoublyNode {
public:
    T e;
    DoublyNode* next;
    DoublyNode* prev;

    Node(const T& e, DoublyNode* next, DoublyNode* prev): e(e), next(next), prev(prev) {}
    Node(const T& e, DoublyNode* next): e(e), next(next), prev(nullptr) {}
    Node(const T& e, DoublyNode* prev): e(e), next(nullptr), prev(nullptr) {}
    Node(const T& e): e(e), next(nullptr), prev(nullptr) {}
    Node(): next(nullptr), prev(nullptr) {}

};

template <class T>
ostream& operator << (ostream& os, const DoublyNode<T>& n) {
    cout << n.e;
    return os;
}


#endif /* DATASTRUCT_DOUBLYLINKEDLIST_H */