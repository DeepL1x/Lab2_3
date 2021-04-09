//
// Created by Victor on 08.04.2021.
//

#ifndef LAB2_3_MAXq_H
#define LAB2_3_MAXq_H
#include "DynamicArray.h"
struct MaxHeap{
    DynamicArray q = DynamicArray();

    int getParent(int i);

    int getRightChild(int i);

    int getLeftChild(int i);

    int size();

    void swap (Data& a, Data& b);

    void siftUp(int i);

    void siftDown(int i);
};
#endif //LAB2_3_MAXq_H
