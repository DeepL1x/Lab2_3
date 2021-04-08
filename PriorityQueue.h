//
// Created by Victor on 08.04.2021.
//

#ifndef LAB2_3_PRIORITYQUEUE_H
#define LAB2_3_PRIORITYQUEUE_H
#include "MaxHeap.h"
struct PriorityQueue{
    MaxHeap heap;

    void push(Data a) {
        heap.q.push_back(a);
        heap.siftUp(size() - 1);
    }

    void pop() {
        if (heap.size() == 0){
//            std::cout << "Queue underflow" << std::endl;
        }
        else {
            heap.swap(heap.q.innerArray[0], heap.q.innerArray[size()-1]);
            heap.q.pop_back();
            heap.siftDown(0);
        }
    }
    Data top() {
        if (heap.size() == 0){
//            std::cout << "Queue is empty" << std::endl;
            Data temp = Data(-1, -1);
            return temp;
        }
        return heap.q.innerArray[0];
    }
    bool empty(){
        return !heap.size();
    }
    int size(){
        return heap.size();
    }
};
#endif //LAB2_3_PRIORITYQUEUE_H
