//
// Created by Victor on 09.04.2021.
//

#ifndef LAB2_3_HEAPSORT_H
#define LAB2_3_HEAPSORT_H
#include "MaxIntHeap.h"

void siftDown(int aTop, MaxIntHeap& aHeap, int aBottom);

void heapSort(int* aArray, int aSize);


#endif //LAB2_3_HEAPSORT_H
