//
// Created by Victor on 09.04.2021.
//

#include "MaxIntHeap.h"
#include <iostream>

MaxIntHeap::MaxIntHeap(int *aArray, int aSize) {
    array = aArray;
    size = aSize;
}

void MaxIntHeap::buildHeap() {
    for (int i = size/2 - 1; i >= 0; --i) {
        siftDown(i);
    }
}

int MaxIntHeap::getParent(int i)  {
        return (i - 1) / 2;
}

int MaxIntHeap::getRightChild(int i) {
        return 2 * i + 2;
}

int MaxIntHeap::getLeftChild(int i) {
    return 2 * i + 1;
}

void MaxIntHeap::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void MaxIntHeap::siftUp(int i) {
    if(i > 0 && i < size && array[getParent(i)] < array[i]) {
        swap(array[i], array[getParent(i)]);
        siftUp(getParent(i));
    }
}

void MaxIntHeap::siftDown(int i) {
    if(i > -1 && getLeftChild(i) < size) {
        int max = getLeftChild(i);
        if (getRightChild(i) > 0 && getRightChild(i) < size && array[getLeftChild(i)] < array[getRightChild(i)])
            max = getRightChild(i);
        if (!(array[i] < array[max]))
            return;
        swap(array[i], array[max]);
        siftDown(max);
    }
}
