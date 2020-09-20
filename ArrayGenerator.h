#ifndef DATASTRUCT_ARRAYGENERATOR_H
#define DATASTRUCT_ARRAYGENERATOR_H
#include <cstdlib>
#include <cstring>

using namespace std;

class ArrayGenerator
{
private:
    ArrayGenerator() {}
    // static int* arr;
public:
    static int* generateOrderedArray(int n);
    
    static int* generateRandomArray(int n, int bound);

    static int* copyArray(int* arr, int length);

    // ~ArrayGenerator() {delete []arr;}
};

inline int*
ArrayGenerator::generateOrderedArray(int n) {
    int* arr = new int[n];

    for(int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    return arr;
}

inline int*
ArrayGenerator::generateRandomArray(int n, int bound) {
    int* arr = new int[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = rand() % bound;
    }

    return arr;
}

inline int*
ArrayGenerator::copyArray(int* arr, int length) {
    int* arrNew = new int[length];

    memcpy(arrNew, arr, sizeof(int) * length);

    return arrNew;
}

#endif /* DATASTRUCT_ARRAYGENERATOR_H */