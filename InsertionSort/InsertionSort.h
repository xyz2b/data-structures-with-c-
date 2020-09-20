#ifndef DATASTRUCT_INSERTIONSORT_H
#define DATASTRUCT_INSERTIONSORT_H

/* 时间复杂度：O(n^2)，空间复杂度：O(1) */
template <class T>
class InsertionSort
{
private:
    InsertionSort() {};
public:
    static void sort(T* data, int len);
    static void sort(T* data, int len, int l, int r);

    static void sort2(T* data, int len);
    static void sort3(T* data, int len);

    static void swap(T* data, int i, int j);
};

template <class T>
inline void
InsertionSort<T>::sort2(T* data, int len) {
    /* 循环不变量：arr[0...i) 是有序的；arr[i...n) 是无序的 */
    for(int i = 0; i < len; ++i) {
        /* 将data[i]插入到合适的位置 */
        // for(int j = i; j > 0; --j) {
        //     if(data[j] < data[j-1])
        //         swap(data, j, j-1);
        //     else
        //         break;
        // }
        for(int j = i; j > 0 && data[j] < data[j-1]; --j)
            swap(data, j, j-1);
    }
}

template <class T>
inline void
InsertionSort<T>::sort(T* data, int len) {
    /* 循环不变量：arr[0...i) 是有序的；arr[i...n) 是无序的 */
    for(int i = 0; i < len; ++i) {
        /* 将data[i]插入到合适的位置 */
        T t = data[i];
        int j;
        for(j = i; j > 0 && t < data[j-1]; --j)
            data[j] = data[j - 1];
        data[j] = t;
    }
}

template <class T>
inline void
InsertionSort<T>::sort(T* data, int len, int l, int r) {
    /* 循环不变量：arr[0...i) 是有序的；arr[i...n) 是无序的 */
    for(int i = l; i <= r; ++i) {
        /* 将data[i]插入到合适的位置 */
        T t = data[i];
        int j;
        for(j = i; j > l && t < data[j-1]; --j)
            data[j] = data[j - 1];
        data[j] = t;
    }
}

template <class T>
inline void
InsertionSort<T>::sort3(T* data, int len) {
    /* 循环不变量：arr[0...i) 是有序的；arr[i...n) 是无序的 */
    for(int i = len - 1 ; i >= 0; --i) {
        /* 将data[i]插入到合适的位置 */
        T t = data[i];
        int j;
        for(j = i; j < len - 1 && t > data[j+1]; ++j)
            data[j] = data[j + 1];
        data[j] = t;
    }
}


template <class T>
inline void
InsertionSort<T>::swap(T* data, int i, int j) {
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

#endif /* DATASTRUCT_INSERTIONSORT_H */