//
// Created by Victor on 09.04.2021.
//

#ifndef LAB2_3_MAXINTHEAP_H
#define LAB2_3_MAXINTHEAP_H


struct MaxIntHeap {

    int *array;
    int size;

    MaxIntHeap(int *aArray, int aSize);

    void buildHeap();

    int getParent(int i);

    int getRightChild(int i);

    int getLeftChild(int i);

    void siftUp(int i);

    void siftDown(int i);

    void swap(int &a, int &b);
};


#endif //LAB2_3_MAXINTHEAP_H
