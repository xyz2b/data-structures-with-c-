#ifndef DATASTRUCT_ARRAYGENERATOR_H
#define DATASTRUCT_ARRAYGENERATOR_H
#include <cstdlib>

class ArrayGenerator
{
private:
    ArrayGenerator() {}
    // static int* arr;
public:
    static int* generateOrderedArray(int n);
    
    static int* generateRandomArray(int n, int bound);

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

#endif /* DATASTRUCT_ARRAYGENERATOR_H */