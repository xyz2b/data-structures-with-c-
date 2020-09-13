#ifndef DATASTRUCT_SORTINGHELPER_H
#define DATASTRUCT_SORTINGHELPER_H

#include "SelectionSort/SelectionSort.h"
#include "InsertionSort/InsertionSort.h"

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
            SelectionSort<int>::sort(arr, len);
        } else if (sortname == "SelectionSort2") {
            SelectionSort<int>::sort2(arr, len);
        } else if (sortname == "InsertionSort") {
            InsertionSort<int>::sort(arr, len);
        } else if (sortname == "InsertionSort2") {
            InsertionSort<int>::sort2(arr, len);
        } else if (sortname == "InsertionSort3") {
            InsertionSort<int>::sort3(arr, len);
        }
        clock_t end_time = clock();

        if(!SortingHelper<int>::isSorted(arr, len))
            throw sortname + " failed";

        cout << fixed << setprecision(10) << sortname << ", n = " << len << ", time: " << (end_time - start_time)/(double)CLOCKS_PER_SEC <<  " s" << endl;
    }
};

#endif /* DATASTRUCT_SORTINGHELPER_H */