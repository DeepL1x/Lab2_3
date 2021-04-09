//
// Created by Victor on 09.04.2021.
//

#include "HeapSort.h"

void siftDown(int aTop, MaxIntHeap& aHeap, int aBottom){
    if(aTop > -1 && aHeap.getLeftChild(aTop) < aBottom) {

        int max = aHeap.getLeftChild(aTop);

        if (aHeap.getRightChild(aTop) > 0 && aHeap.getRightChild(aTop) < aBottom &&
        aHeap.array[aHeap.getLeftChild(aTop)] < aHeap.array[aHeap.getRightChild(aTop)])
            max = aHeap.getRightChild(aTop);

        if (aHeap.array[aTop] >= aHeap.array[max])
            return;

        aHeap.swap(aHeap.array[aTop], aHeap.array[max]);

        siftDown(max, aHeap, aBottom);
    }
}

void heapSort(int* aArray, int aSize){
    MaxIntHeap heap = MaxIntHeap(aArray, aSize);
    heap.buildHeap();
    int heapSize = aSize;
    for (int i = 0; i < aSize - 1; ++i) {
        heap.swap(heap.array[0], heap.array[aSize - 1 - i]);
        heapSize--;
        siftDown(0, heap, heapSize);
    }
}

