#ifndef DATASTRUCT_LINEARSEARCH_H
#define DATASTRUCT_LINEARSEARCH_H

template <class T>
class LinearSearch
{
private:
    LinearSearch() {}
public:
    static int search(T target, T* data, int len);
    // {
        // for(int i = 0; i < len; ++i)
        //     if(data[i] == target)
        //         return i;

        // return -1;
    // }

};

template <class T>
inline int
LinearSearch<T>::search(T target, T* data, int len)
{
    for(int i = 0; i < len; ++i)
        if(data[i] == target)
            return i;

    return -1;
}

#endif /* DATASTRUCT_LINEARSEARCH_H */
