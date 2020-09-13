#ifndef DATASTRUCT_ARRAY_H
#define DATASTRUCT_ARRAY_H

#include <cstring>
#include <iostream>
#include "../Exception.h"

using namespace std;

/*
    添加操作: O(n)
        addLast     O(1)    最坏复杂度O(n)    均摊复杂度O(1)
        addFirst    O(n)
        add    O(n)

    删除操作: O(n)
        removeLast  O(1)    最坏复杂度O(n)    均摊复杂度O(1)
        removeFirst O(n)
        remove      O(n)

    修改操作: 已知索引O(1)，未知索引O(n)
        set         O(1)

    查找操作: 已知索引O(1)，未知索引O(n)
        get         O(1)
        contains    O(n)
        find        O(n)
*/
template <class T>
class Array
{
private:
    int size;
    int capacity;
    T* data;

    void _resize(int newCapacity);
public:
    Array();
    Array(const int capacity);
    ~Array();

    // 获取数组中的元素个数
    int getSize() const { return size; }

    // 获取数组的容量
    int getCapacity() const { return capacity; }

    // 返回数组是否为空
    bool isEmpty() const { return size == 0; }

    // 向数组末尾添加元素
    void addLast(const T& e);

    // 向数组开头添加元素
    void addFirst(const T& e);

    // 在第index个位置插入一个新元素e
    void add(const int index, const T& e);

    // 获取index索引位置的元素
    T& get(const int index) const;

    T& getLast();

    T& getFirst();

    // 修改index索引位置的元素
    void set(const int index, const T& e);

    // 查找数组中是否有元素e
    bool contains(const T& e) const;

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    int find(const T& e) const;

    // 从数组中删除index位置的元素，返回删除的元素
    T remove(const int index);

    // 从数组中删除第一个元素，返回删除的元素
    T removeFirst();

    // 从数组中删除最后一个元素，返回删除的元素
    T removeLast();

    // 从数组中删除元素e，并返回元素e在数组中的索引，如果元素e不存在于数组中，则返回-1
    int removeAlement(const T& e);
};

// 无参数的构造函数，默认数组的容量capacity=10
template <class T>
inline
Array<T>::Array() {
    this->data = new T[10];
    this->size = 0;
    this->capacity = 10;
}

// 构造函数，传入数组的容量capactiy构造array
template <class T>
inline
Array<T>::Array(const int capacity) {
    this->data = new T[capacity];
    this->size = 0;
    this->capacity = capacity;
}

template <class T>
inline
Array<T>::~Array() {
    delete[] data;
}

template <class T>
inline void
Array<T>::addLast(const T& e) {
    add(size, e);
}

template <class T>
inline void
Array<T>::addFirst(const T& e) {
    add(0, e);
}

template <class T>
inline void
Array<T>::add(const int index, const T& e) {
    if(index < 0 || index > size)
        throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    // 扩容
    if(size == capacity)
        _resize(2 * capacity);

    memmove((void*)(data + index + 1), (void*)(data + index), (size - index) * sizeof(T));

    data[index] = e;

    size++;
}

template <class T>
inline T&
Array<T>::get(const int index) const {
    if(index < 0 || index >= size)
        throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    return data[index];
}

template <class T>
inline T& 
Array<T>::getLast() {
    return get(size - 1);
};

template <class T>
inline T& 
Array<T>::getFirst() {
    return get(0);
};


template <class T>
inline void
Array<T>::set(const int index, const T& e) {
    if(index < 0 || index >= size)
        throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    data[index] = e;    
}

template <class T>
inline bool
Array<T>::contains(const T& e) const {
    for(int i = 0; i < size; ++i)
        if(data[i] == e)
            return true;
        
    return false;
}

template <class T>
inline int
Array<T>::find(const T& e) const {
    for(int i = 0; i < size; ++i)
        if(data[i] == e)
            return i;
        
    return -1;    
}

template <class T>
inline T 
Array<T>::remove(const int index) {
    if(index < 0 || index >= size)
        throw Exception("Index illegal", __FILE__, __LINE__, __PRETTY_FUNCTION__);

    T ret = data[index];
    memmove((void*)(data + index), (void*)(data + index + 1), (size - index) * sizeof(T));
    size--;

    // 缩容
    if(size == capacity / 4 && capacity / 2 != 0)
        // Lazy：数组使用量等于capacity/4，缩容1/2(防止复杂度震荡)
        _resize(capacity / 2);

    return ret;
}

template <class T>
inline T
Array<T>::removeFirst() {
    return remove(0);
}

template <class T>
inline T 
Array<T>::removeLast() {
    return remove(size -1);
}

template <class T>
inline int
Array<T>::removeAlement(const T& e) {
    int index = find(e);
    if(index != -1) {
        remove(index);
        return index;
    }
    return -1;
}

template <class T> void 
Array<T>::_resize(int newCapacity) {
    T* newData = new T[newCapacity];
    memcpy(newData, data, size * sizeof(T));

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <class T>
ostream& operator << (ostream& os, const Array<T>& arr) {
    cout << "Array: size = " <<  arr.getSize() << ", capacity = " << arr.getCapacity() << endl;
    cout << "[";
    for(int i = 0; i < arr.getSize(); ++i) {
        cout << arr.get(i);
        if (i != arr.getSize() - 1)
            cout << ", ";
    }
    cout << "]";
    return os;
}
#endif /* DATASTRUCT_ARRAY_H */