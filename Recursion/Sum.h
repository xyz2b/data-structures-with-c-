#ifndef DATASTRUCT_SUMR_H
#define DATASTRUCT_SUMR_H

class SumR
{
private:
    static int sum(int* arr, int length, int l);
public:
    static int sum(int* arr, int length);
};

inline int
SumR::sum(int* arr, int length, int l) {
    // 终止条件
    if(l == length)
        return 0;
    
    // 处理当前层逻辑
    // 下探到下一层
    return arr[l] + sum(arr, length, l + 1);
}

inline int
SumR::sum(int* arr, int length) {
    return sum(arr, length, 0);
}

#endif 