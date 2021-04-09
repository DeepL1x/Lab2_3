//
// Created by Victor on 08.04.2021.
//

#ifndef LAB2_3_PRIORITYQUEUE_H
#define LAB2_3_PRIORITYQUEUE_H
#include "MaxHeap.h"
struct PriorityQueue{
    MaxHeap heap;

    void push(Data a);

    void pop();

    Data top();

    bool empty();

    int size();
};
#endif //LAB2_3_PRIORITYQUEUE_H
