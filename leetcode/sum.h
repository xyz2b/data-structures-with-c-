#ifndef DATASTRUCT_SUM_H
#define DATASTRUCT_SUM_H

#include <vector>

using namespace std;

class sumSolution
{
private:
public:
    int sum(int* arr, int size) {
        if(size == 0)
            return 0;
        
        return arr[0] + sum(arr + 1, size--);
    }
};

#endif 