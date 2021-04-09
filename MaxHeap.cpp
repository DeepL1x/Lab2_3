//
// Created by Victor on 09.04.2021.
//

#include "MaxHeap.h"

int MaxHeap::getParent(int i)  {
    return (i - 1) / 2;
}

int MaxHeap::getRightChild(int i) {
    return 2 * i + 2;
}

int MaxHeap::getLeftChild(int i) {
    return 2 * i + 1;
}

int MaxHeap::size() {
    return q.size();
}

void MaxHeap::swap(Data &a, Data &b) {
    Data temp = a;
    a = b;
    b = temp;
}

void MaxHeap::siftUp(int i) {
    if(i > 0 && i < size() && q.innerArray[getParent(i)] < q.innerArray[i]) {
        swap(q.innerArray[i], q.innerArray[getParent(i)]);
        siftUp(getParent(i));
    }
}

void MaxHeap::siftDown(int i) {
    if(i > -1 && getLeftChild(i) < size()) {
        int max = getLeftChild(i);
        if (getRightChild(i) > 0 && getRightChild(i) < size() && q.innerArray[getLeftChild(i)] < q.innerArray[getRightChild(i)])
            max = getRightChild(i);
        if (!(q.innerArray[i] < q.innerArray[max]))
            return;
        swap(q.innerArray[i], q.innerArray[max]);
        siftDown(max);
    }
}
