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
    return array.size();
}

void MaxHeap::swap(Data &a, Data &b) {
    Data temp = a;
    a = b;
    b = temp;
}

void MaxHeap::siftUp(int i) {
    if(i > 0 && i < size() && array.innerArray[getParent(i)] < array.innerArray[i]) {
        swap(array.innerArray[i], array.innerArray[getParent(i)]);
        siftUp(getParent(i));
    }
}

void MaxHeap::siftDown(int i) {
    if(i > -1 && getLeftChild(i) < size()) {
        int max = getLeftChild(i);
        if (getRightChild(i) > 0 && getRightChild(i) < size() && array.innerArray[getLeftChild(i)] < array.innerArray[getRightChild(i)])
            max = getRightChild(i);
        if (!(array.innerArray[i] < array.innerArray[max]))
            return;
        swap(array.innerArray[i], array.innerArray[max]);
        siftDown(max);
    }
}
