#ifndef DATASTRUCT_SELECTIONSORT_H
#define DATASTRUCT_SELECTIONSORT_H

/* 时间复杂度：O(n^2)，空间复杂度：O(1) */
template <class T>
class SelectionSort
{
private:
    SelectionSort() {};
public:
    static void sort(T* data, int len);
    static void sort2(T* data, int len);
    // {
    //     for(int i = 0; i < len - 1; ++i) {
    //         int minIndex = i;
    //         for(int j = i + 1; j < len; ++j) {
    //             if(data[j] < data[minIndex])
    //                 minIndex = j;
    //         }
            
    //         int temp = data[minIndex];
    //         data[minIndex] = data[i];
    //         data[i] = temp;
    //     }

    //     return data;
    // }
    static void swap(T* data, int i, int j);
};

template <class T>
inline void
SelectionSort<T>::sort(T* data, int len) {
    /* 循环不变量：arr[0...i) 是有序的；arr[i...n) 是无序的 */
    for(int i = 0; i < len; ++i) {
        /* 找到 arr[i...n) 中的最小值的索引*/
        int minIndex = i;
        for(int j = i; j < len; ++j) {
            if(data[j] < data[minIndex])
                minIndex = j;
        }
        
        swap(data, minIndex, i);
    }
}

template <class T>
inline void
SelectionSort<T>::sort2(T* data, int len) {
    /* 循环不变量：arr[i...n) 是有序的；arr[0...i) 是无序的 */
    for(int i = len - 1; i > 0; --i) {
        /* 找到 arr[0...i] 中的最大值的索引*/
        int maxIndex = i;
        for(int j = i - 1; j >= 0; --j) {
            if(data[j] > data[maxIndex])
                maxIndex = j;
        }
        
        swap(data, maxIndex, i);
    }
}

template <class T>
inline void
SelectionSort<T>::swap(T* data, int i, int j) {
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

#endif /* DATASTRUCT_SELECTIONSORT_H */