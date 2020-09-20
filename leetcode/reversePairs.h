#ifndef DATASTRUCT_REVERSEPAIRS_H
#define DATASTRUCT_REVERSEPAIRS_H

#include <cstring>

using namespace std;

class ReversePairs
{
private:
    int res = 0;
    void _sort(int* arr, int length, int l, int r, int* temp);
    void merge(int* arr, int length, int l, int mid, int r, int* temp);
public:
    int reversePairs(int* arr, int length);
};


int
ReversePairs::reversePairs(int* arr, int length) {
    int* temp = new int[length];
    memcpy(temp, arr, sizeof(int) * length);

    res = 0;
    _sort(arr, length, 0, length - 1, temp);

    return res;
}

void
ReversePairs::_sort(int* arr, int length, int l, int r, int* temp) {
    if(l >= r) return;

    int mid = l + (r - l)/2;

    _sort(arr, length, l, mid, temp);
    _sort(arr, length, mid + 1, r, temp);

    if(arr[mid] > arr[mid + 1])
        merge(arr, length, l, mid, r, temp);
}

void
ReversePairs::merge(int* arr, int length, int l, int mid, int r, int* temp) {
    memcpy(temp + l, arr + l, (r - l + 1) * sizeof(int));

    int i = l;
    int j = mid + 1;

    // 每轮循环为arr[k]赋值
    for(int k = l; k <= r; ++k) {
        if(i > mid) {
            arr[k] = temp[j];
            ++j;
        } else if(l > length - 1) {
            arr[k] = temp[i];
            ++i;
        } else if(temp[i] <= temp[j]) {
            arr[k] = temp[i];
            ++i;
        } else {
            arr[k] = temp[j];
            ++j;

            res += mid - i + 1;
        }   
    }
}

#endif