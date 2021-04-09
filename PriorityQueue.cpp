//
// Created by Victor on 09.04.2021.
//

#include "PriorityQueue.h"

void PriorityQueue::push(Data a) {
    heap.array.push_back(a);
    heap.siftUp(size() - 1);
}

void PriorityQueue::pop() {
    if (heap.size() == 0){
//            std::cout << "arrayueue underflow" << std::endl;
    }
    else {
        heap.swap(heap.array.innerArray[0], heap.array.innerArray[size()-1]);
        heap.array.pop_back();
        heap.siftDown(0);
    }
}

Data PriorityQueue::top() {
    if (heap.size() == 0){
//            std::cout << "arrayueue is empty" << std::endl;
        Data temp = Data(-1, -1);
        return temp;
    }
    return heap.array.innerArray[0];
}

bool PriorityQueue::empty(){
    return !heap.size();
}

int PriorityQueue::size(){
    return heap.size();
}

