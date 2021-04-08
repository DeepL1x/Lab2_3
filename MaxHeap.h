//
// Created by Victor on 08.04.2021.
//

#ifndef LAB2_3_MAXq_H
#define LAB2_3_MAXq_H
#include "DynamicArray.h"
struct MaxHeap{
    DynamicArray q;

    int getParent(int i) {
        if (i == 0)
            return 0;
        return (i - 1) / 2;
    }

    int getRightChild(int i) {
        if (2 * i + 2 < size())
            return 2 * i + 2;
        return -1;
    }

    int getLeftChild(int i) {
        if (2 * i + 1 < size())
            return 2 * i + 1;
        return -1;
    }

    int size(){
        return q.size();
    }

    void swap (Data& a, Data& b){
        Data temp = a;
        a = b;
        b = temp;
    }
    void siftUp(int i) {
        while (q.innerArray[getParent(i)] < q.innerArray[i]) {
            swap(q.innerArray[i], q.innerArray[getParent(i)]);
            i = getParent(i);
        }
    }

    void siftDown(int i) {
        while (i > -1 && getLeftChild(i) < size()) {
            int max = getLeftChild(i);
            if (getRightChild(i) < size() && !(q.innerArray[getRightChild(i)] < q.innerArray[getLeftChild(i)]))
                max = getRightChild(i);
            if (!(q.innerArray[i] < q.innerArray[max]))
                return;
            swap(q.innerArray[i], q.innerArray[max]);
            i = max;
        }
    }
};
#endif //LAB2_3_MAXq_H
