#ifndef DATASTRUCT_LINKEDLIST_H
#define DATASTRUCT_LINKEDLIST_H

#include <iostream>
#include "../Exception.h"

using namespace std;

/*
    处理链表问题时，需要多设立指针，保存更多的信息，之后通过这些信息操纵每个节点的指针，在节点之间进行穿针引线
        pre    cur     next
    0 -> 1  ->  2   ->  3   -> 4 -> 5 -> null
*/

template <class T>
class Node {
public:
    T e;
    Node* next;

    Node(const T& e, Node* next): e(e), next(next) {}
    Node(const T& e): e(e), next(nullptr) {}
    Node(): next(nullptr) {}

    // 链表节点构造函数
    // 使用arr作为参数，创建一个链表，当前的Node为链表头结点
    Node(T* arr, int length);

};


template <class T>
inline
Node<T>::Node(T* arr, int length) {
    if(arr == nullptr || length == 0) {
        throw Exception("arr can not be empty", __FILE__, __LINE__, __PRETTY_FUNCTION__);
    }

    this->e = arr[0];
    Node<T>* cur = this;
    for(int i = 1; i < length; ++i) {
        cur->next = new Node(arr[i]);
        cur = cur->next;
    }

}


template <class T>
ostream& operator << (ostream& os, Node<T>* n) {
    Node<T>* cur = n;
    while (cur != nullptr)
    {
        cout << cur->e << "->";
        cur = cur->next;
    }
    cout << "NULL";
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


    Node<T>* _addR(Node<T>* head, int index, const T& e);

    Node<T>* _getR(Node<T>* head, int index) const;

    Node<T>* _removeR(Node<T>* head, int index);

    // 加入调试信息的递归
    // Node<T>* removeElement(Node<T>* head, const T& e, int depth);
    Node<T>* removeElement(Node<T>* head, const T& e);

    string generateDepthString(int depth);

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

    // 递归操作
    void addR(const int index, const T& e);

    // 获取链表index(0-based)位置的元素
    T& get(const int index) const;

    T& getR(const int index) const;

    // 获取链表第一个元素
    T& getFirst() const;

    // 获取链表最后一个元素
    T& getLast() const;

    // 修改链表index(0-based)位置的元素为e
    // 链表中不常用的一个操作
    void set(const int index, const T& e);

    void setR(const int index, const T& e);

    // 查看链表中是否有元素e
    bool contains(const T& e) const;

    // 删除链表index(0-based)位置的元素
    T remove(const int index);

    T removeR(const int index);

    // 删除链表开头的元素
    T removeFirst();

    // 删除链表结尾的元素
    T removeLast();

    void removeElement(const T& e);
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
inline Node<T>*
LinkedList<T>::_addR(Node<T>* head, int index, const T& e) {
    if(index == 0) {
        return new Node<T>(e, head);
    }

    head->next = _addR(head->next, --index, e);

    return head;
}

template <class T>
inline void
LinkedList<T>::addR(const int index, const T& e) {
    if(index < 0 || index > size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);


    dummyhead->next = _addR(dummyhead->next, index, e);

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
inline Node<T>*
LinkedList<T>::_getR(Node<T>* head, int index) const {
    if(index == 0) {
        return head;
    }

    return _getR(head->next, --index);
}

template <class T>
inline T&
LinkedList<T>::getR(const int index) const {
    if(index < 0 || index >= size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    Node<T>* n = _getR(dummyhead->next, index);
    return n->e;
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
inline void
LinkedList<T>::setR(const int index, const T& e) {
    if(index < 0 || index >= size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    Node<T>* n = _getR(dummyhead->next, index);
    
    n->e = e;    
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
inline Node<T>*
LinkedList<T>::_removeR(Node<T>* head, int index) {
    if(index == 0) {
        return head->next;
    }

    head->next = _removeR(head->next, --index);

    return head;
}

template <class T>
inline T
LinkedList<T>::removeR(const int index) {
    if(index < 0 || index >= size)
       throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);


    Node<T>* retNode = _getR(dummyhead->next, index);


    dummyhead->next = _removeR(dummyhead->next, index);
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
inline string
LinkedList<T>::generateDepthString(int depth) {
    string res = "";
    for(int i = 0; i < depth; ++i) {
        res += "--";
    }

    return res;
}


template<class T>
inline void
LinkedList<T>::removeElement(const T& e) {
    // 加入调试信息的递归
    // dummyhead->next = removeElement(dummyhead->next, e, 0);
    dummyhead->next = removeElement(dummyhead->next, e);
}

// 递归函数的宏观语义
// 在以head为头节点的链表中删除值为e的节点，并返回结果链表的头节点
template <class T>
inline Node<T>*
LinkedList<T>::removeElement(Node<T>* head, const T& e) {
    if(head == nullptr) {
        return nullptr;
    }

    head->next = removeElement(head->next, e);

    if(head->e == e) {
        size--;
        return head->next;
    } else {
        return head;
    }
}

// 加入调试信息
// template <class T>
// inline Node<T>*
// LinkedList<T>::removeElement(Node<T>* head, const T& e, int depth) {
//     string depthString = generateDepthString(depth);
//     cout << depthString;

//     cout << "Call: remove " << e << " in " << head << endl;
    
//     // 终止条件
//     if(head == nullptr) {
//         cout << depthString;
//         cout << "Retrun: " << head << endl;
//         return nullptr;
//     }


//     // 下沉到下一层
//     Node<T>* res = removeElement(head->next, e, depth + 1);

//     cout << depthString;
//     cout << "After remove " << e << ": " << res << endl;

//     // 本层处理逻辑
//     Node<T>* ret;
//     if(head->e == e) {
//         ret = res;
//         size--;
//     } else {
//         head->next = res;
//         ret = head;
//     }
    
//     cout << depthString;
//     cout << "Return: " << ret << endl;
//     return ret;
// }


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