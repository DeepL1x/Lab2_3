//
// Created by Victor on 09.04.2021.
//

#include "PriorityQueue.h"

void PriorityQueue::push(Data a) {
    heap.q.push_back(a);
    heap.siftUp(size() - 1);
}

void PriorityQueue::pop() {
    if (heap.size() == 0){
//            std::cout << "Queue underflow" << std::endl;
    }
    else {
        heap.swap(heap.q.innerArray[0], heap.q.innerArray[size()-1]);
        heap.q.pop_back();
        heap.siftDown(0);
    }
}

Data PriorityQueue::top() {
    if (heap.size() == 0){
//            std::cout << "Queue is empty" << std::endl;
        Data temp = Data(-1, -1);
        return temp;
    }
    return heap.q.innerArray[0];
}

bool PriorityQueue::empty(){
    return !heap.size();
}

int PriorityQueue::size(){
    return heap.size();
}

