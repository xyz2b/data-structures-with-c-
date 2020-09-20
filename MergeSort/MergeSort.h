#ifndef DATASTRUCT_MERGESORT_H
#define DATASTRUCT_MERGESORT_H

#include <cstring>
#include <algorithm>

#include "../InsertionSort/InsertionSort.h"

using namespace std;

template<class T>
class MergeSort
{
private:
    MergeSort() {}

    // 合并两个有序的区间，arr[l, mid] 以及 arr[mid+1, r]
    void static merge(T* arr, int length, int l, int mid, int r);

    void static merge2(T* arr, int length, int l, int mid, int r, T* temp);

    void static _sort(T* arr, int length, int l, int r);

    void static _sortDebug(T* arr, int length, int l, int r, int depth);

    void static _sort2(T* arr, int length, int l, int r);

    void static _sort3(T* arr, int length, int l, int r);

    void static _sort4(T* arr, int length, int l, int r, T* temp);

    static string generateDepthString(int depth);
public:
    // 自顶向下的归并排序
    void static sort(T* arr, int length);

    void static sortDebug(T* arr, int length);

    void static sort2(T* arr, int length);

    void static sort3(T* arr, int length);

    void static sort4(T* arr, int length);

    // 自底向上的归并排序
    void static sortBU(T* arr, int length);

    void static sortBU2(T* arr, int length);
};

template <class T>
inline string
MergeSort<T>::generateDepthString(int depth) {
    string res = "";
    for(int i = 0; i < depth; ++i) {
        res += "--";
    }

    return res;
}

template<class T>
inline void
MergeSort<T>::merge(T* arr, int length, int l, int mid, int r) {
    T* temp = new T[r - l + 1];

    // 将arr[l, r]复制到temp中，注意之后处理时候下标的对应关系
    // arr[l]对应到temp[0]
    // arr[r]对应到temp[r - l]
    memcpy(temp, arr + l, (r - l + 1) * sizeof(T));

    int i = l;
    int j = mid + 1;

    // 每轮循环为arr[k]赋值
    for(int k = l; k <= r; ++k) {
        if(i > mid) {
            arr[k] = temp[j - l];
            ++j;
        } else if (j > r) {
            arr[k] = temp[i - l];
            ++i;
        } else if(temp[i - l] < temp[j - l]) {
            arr[k] = temp[i - l];
            ++i;
        } else {
            arr[k] = temp[j - l];
            ++j;
        }
    }
}


template<class T>
inline void
MergeSort<T>::sortDebug(T* arr, int length) {
    _sortDebug(arr, length, 0, length - 1, 0);
}

template<class T>
inline void
MergeSort<T>::_sortDebug(T* arr, int length, int l, int r, int depth) {
    string depthString = generateDepthString(depth);
    cout << depthString;

    cout << "Call: sort arr[" << l << ", " << r << "] " << "arr = " << "[";
    for(int i = l; i < r; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[r];
    cout << "]" << endl;


    if(l >= r) {
        cout << depthString;
        cout << "Retrun: sort arr[" << l << ", " << r << "] " << "arr = " << "[" << arr[l]  << "]" << endl;
        return;
    }


    // 防止加法溢出，将加法改成减法
    int mid = l + (r - l) / 2;

    _sortDebug(arr, length, l, mid, depth + 1);

    cout << depthString;
    cout << "After sort arr[" << l << ", " << mid << "] " << "arr = " << "[";
    for(int i = l; i < mid; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[mid];
    cout << "]" << endl;


    _sortDebug(arr, length, mid + 1, r, depth + 1);

    cout << depthString;
    cout << "After sort arr[" << mid + 1 << ", " << r << "] " << "arr = " << "[";
    for(int i = mid + 1; i < r; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[r];
    cout << "]" << endl;

    merge(arr, length, l, mid, r);

    cout << depthString;
    cout << "After merge arr[" << l << ", " << r << "] " << "arr = " << "[";
    for(int i = l; i < r; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[r];
    cout << "]" << endl;
}

template<class T>
inline void
MergeSort<T>::sort(T* arr, int length) {
    _sort(arr, length, 0, length - 1);
}

template<class T>
inline void
MergeSort<T>::_sort(T* arr, int length, int l, int r) {
    if(l >= r) {
        return;
    }

    // 防止加法溢出，将加法改成减法
    int mid = l + (r - l) / 2;

    _sort(arr, length, l, mid);
    _sort(arr, length, mid + 1, r);

    merge(arr, length, l, mid, r);
}

template<class T>
inline void
MergeSort<T>::sort2(T* arr, int length) {
    _sort2(arr, length, 0, length - 1);
}

template<class T>
inline void
MergeSort<T>::_sort2(T* arr, int length, int l, int r) {
    if(l >= r) {
        return;
    }

    // 防止加法溢出，将加法改成减法
    int mid = l + (r - l) / 2;

    _sort2(arr, length, l, mid);
    _sort2(arr, length, mid + 1, r);

    if(arr[mid] > arr[mid + 1])
        merge(arr, length, l, mid, r);
}

template<class T>
inline void
MergeSort<T>::sort3(T* arr, int length) {
    _sort3(arr, length, 0, length - 1);
}

template<class T>
inline void
MergeSort<T>::_sort3(T* arr, int length, int l, int r) {
    // if(l >= r) return;

    // 数据规模较小时，使用插入排序法进行排序
    if(r - l <= 15) {
        InsertionSort<T>::sort(arr, length, l, r);
        return;
    }

    // 防止加法溢出，将加法改成减法
    int mid = l + (r - l) / 2;

    _sort3(arr, length, l, mid);
    _sort3(arr, length, mid + 1, r);

    if(arr[mid] > arr[mid + 1])
        merge(arr, length, l, mid, r);
}


template<class T>
inline void
MergeSort<T>::sort4(T* arr, int length) {
    T* temp = new T[length];
    memcpy(temp, arr, sizeof(T) * length);

    _sort4(arr, length, 0, length - 1, temp);
}

template<class T>
inline void
MergeSort<T>::_sort4(T* arr, int length, int l, int r, T* temp) {
    if(l >= r) {
        return;
    }

    // 防止加法溢出，将加法改成减法
    int mid = l + (r - l) / 2;

    _sort4(arr, length, l, mid, temp);
    _sort4(arr, length, mid + 1, r, temp);

    if(arr[mid] > arr[mid + 1])
        merge2(arr, length, l, mid, r, temp);
}

template<class T>
inline void
MergeSort<T>::merge2(T* arr, int length, int l, int mid, int r, T* temp) {
    // 将arr[l, r]复制到temp中，注意之后处理时候下标的对应关系
    // arr[l]对应到temp[0]
    // arr[r]对应到temp[r - l]
    memcpy(temp + l, arr + l, (r - l + 1) * sizeof(T));

    int i = l;
    int j = mid + 1;

    // 每轮循环为arr[k]赋值
    for(int k = l; k <= r; ++k) {
        if(i > mid) {
            arr[k] = temp[j];
            ++j;
        } else if (j > r) {
            arr[k] = temp[i];
            ++i;
        } else if(temp[i] <= temp[j]) {
            arr[k] = temp[i];
            ++i;
        } else {
            arr[k] = temp[j];
            ++j;
        }
    }
}

template<class T>
inline void
MergeSort<T>::sortBU(T* arr, int length) {
    T* temp = new T[length];
    memcpy(temp, arr, sizeof(T) * length);

    // 遍历合并的两个区间的起始位置i
    // 合并[i, i + sz -1] 和 [i + sz, min(i + sz + sz - 1, n-1)]
    for(int sz = 1; sz < length; sz += sz)
        for(int i = 0; i + sz < length; i += sz + sz)
            if(arr[i + sz - 1] > arr[i + sz])
                merge2(arr, length, i, i + sz -1, min(i + sz + sz -1, length - 1), temp);
}


template<class T>
inline void
MergeSort<T>::sortBU2(T* arr, int length) {
    T* temp = new T[length];
    memcpy(temp, arr, sizeof(T) * length);

    int initSz = 16;
    for(int i = 0; i < length; i += initSz)
        InsertionSort<T>::sort(arr, length, i, min(i + 15, length - 1));

    // 遍历合并的两个区间的起始位置i
    // 合并[i, i + sz -1] 和 [i + sz, min(i + sz + sz - 1, n-1)]
    for(int sz = initSz; sz < length; sz += sz)
        for(int i = 0; i + sz < length; i += sz + sz)
            if(arr[i + sz - 1] > arr[i + sz])
                merge2(arr, length, i, i + sz -1, min(i + sz + sz -1, length - 1), temp);
}

#endif