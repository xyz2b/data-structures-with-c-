#ifndef DATASTRUCT_REMOVELINKEDLISTELEMENTS_H
#define DATASTRUCT_REMOVELINKEDLISTELEMENTS_H

#include "../LinkedList/LinkedList.h"

#include <string>

using namespace std;

template <class T>
class RemoveElementsSolution
{
private:
    RemoveElementsSolution() {}

    static string generateDepthString(int depth);
public:
    static Node<T>* removeElement(Node<T>* head, T e, int depth);
};

template <class T>
inline string
RemoveElementsSolution<T>::generateDepthString(int depth) {
    string res = "";
    for(int i = 0; i < depth; ++i) {
        res += "--";
    }

    return res;
}

template <class T>
inline Node<T>*
RemoveElementsSolution<T>::removeElement(Node<T>* head, T e, int depth) {
    string depthString = generateDepthString(depth);
    cout << depthString;

    cout << "Call: remove " << e << " in " << head << endl;
    
    // 终止条件
    if(head == nullptr) {
        cout << depthString;
        cout << "Retrun: " << head << endl;
        return nullptr;
    }


    // 下沉到下一层
    Node<T>* res = removeElement(head->next, e, depth + 1);

    cout << depthString;
    cout << "After remove " << e << ": " << res << endl;

    // 本层处理逻辑
    Node<T>* ret;
    if(head->e == e) {
        ret = res;
    } else {
        head->next = res;
        ret = head;
    }
    
    cout << depthString;
    cout << "Return: " << ret << endl;
    return ret;
}

#endif