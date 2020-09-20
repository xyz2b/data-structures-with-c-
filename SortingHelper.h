#ifndef DATASTRUCT_SORTINGHELPER_H
#define DATASTRUCT_SORTINGHELPER_H

#include "SelectionSort/SelectionSort.h"
#include "InsertionSort/InsertionSort.h"
#include "MergeSort/MergeSort.h"
#include "Exception.h"

#include <ctime>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class SortingHelper
{
private:
    SortingHelper() {}
public:
    static bool isSorted(T* arr, int len) {
        for(int i = 1; i < len; ++i)
            if(arr[i-1] > arr[i])
                return false;
        return true;
    }

    static void sortTest(string sortname, T* arr, int len) {
        clock_t start_time = clock();
        if(sortname == "SelectionSort") {
            SelectionSort<T>::sort(arr, len);
        } else if (sortname == "SelectionSort2") {
            SelectionSort<T>::sort2(arr, len);
        } else if (sortname == "InsertionSort") {
            InsertionSort<T>::sort(arr, len);
        } else if (sortname == "InsertionSort2") {
            InsertionSort<T>::sort2(arr, len);
        } else if (sortname == "InsertionSort3") {
            InsertionSort<T>::sort3(arr, len);
        } else if (sortname == "MergeSort") {
            MergeSort<T>::sort(arr, len);
        } else if (sortname == "MergeSort2") {
            MergeSort<T>::sort2(arr, len);
        } else if (sortname == "MergeSort3") {
            MergeSort<T>::sort3(arr, len);
        } else if (sortname == "MergeSort4") {
            MergeSort<T>::sort4(arr, len);
        } else if (sortname == "MergeSortBU") {
            MergeSort<T>::sortBU(arr, len);
        } else if (sortname == "MergeSortBU2") {
            MergeSort<T>::sortBU2(arr, len);
        }
        clock_t end_time = clock();

        if(!SortingHelper<T>::isSorted(arr, len))
            throw Exception(sortname + " failed", __FILE__, __LINE__, __PRETTY_FUNCTION__);

        cout << fixed << setprecision(10) << sortname << ", n = " << len << ", time: " << (end_time - start_time)/(double)CLOCKS_PER_SEC <<  " s" << endl;
    }
};

#endif /* DATASTRUCT_SORTINGHELPER_H */