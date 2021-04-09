//
// Created by Victor on 09.04.2021.
//

#include "TestHeapSort.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "HeapSort.h"
#define capacity 50000

void bubbleSort(int* aArray, int aCapacity) {
    int swaps;
    for(int i = 0; i < aCapacity - 1; i++) {
        swaps = 0;
        for(int j = 0; j < aCapacity - 1 - i; j++) {
            if(aArray[j] > aArray[j+1]) {
                int temp = aArray[j+1];
                aArray[j+1] = aArray[j];
                aArray[j] = temp;
                swaps++;
            }
        }
        if(swaps == 0)
            break;
    }
}
void insertionSort(int* aArray, int aCapacity){
    int key, j;
    for (int i = 1; i < aCapacity; i++) {
        key = aArray[i];
        j = i;
        while (j > 0 && aArray[j - 1] > key) {
            aArray[j] = aArray[j - 1];
            j--;
        }
        aArray[j] = key;
    }
}

void testHeapSortSpeed() {
    int* array = new int[capacity];
    int* temp = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        array[i] = 1 + rand() % 5000;
        temp[i] = array[i];

    }
    clock_t timeStart1 = clock();
        heapSort(temp, capacity);
    clock_t timeEnd1 = clock();
    float time1 = (float(timeEnd1 - timeStart1)) / CLOCKS_PER_SEC;

    for (int i = 0; i < capacity; ++i) {
        temp[i] = array[i];
    }

    clock_t timeStart2 = clock();
        make_heap(temp, temp+capacity);
        sort_heap(temp, temp+capacity);
    clock_t timeEnd2 = clock();
    float time2 = (float(timeEnd2 - timeStart2)) / CLOCKS_PER_SEC;

    for (int i = 0; i < capacity; ++i) {
        temp[i] = array[i];
    }

    clock_t timeStart3 = clock();
        bubbleSort(temp, capacity);
    clock_t timeEnd3 = clock();
    float time3 = (float(timeEnd3 - timeStart3)) / CLOCKS_PER_SEC;

    for (int i = 0; i < capacity; ++i) {
        temp[i] = array[i];
    }

    clock_t timeStart4 = clock();
        insertionSort(temp, capacity);
    clock_t timeEnd4 = clock();
    float time4 = (float(timeEnd4 - timeStart4)) / CLOCKS_PER_SEC;

    cout << setw(25) << left << "Time of my heap sort: " << setw(6) << right << time1 << endl;
    cout << setw(25) << left << "Time of STL heap sort: " << setw(6) << right << time2 << endl;
    cout << setw(25) << left << "Time of bubble sort: " << setw(6) << right << time3 << endl;
    cout << setw(25) << left << "Time of insertion sort: " << setw(6) << right << time4 << endl;

    delete [] array;
    delete [] temp;
}

bool testHeapSort() {
    int* array = new int[capacity];
    int* temp = new int[capacity];
    bool isDataEqual = 1;
    for (int i = 0; i < capacity; ++i) {
        temp[i] = array[i] = 1 + rand() % 5000;
    }
    heapSort(array, capacity);
    make_heap(temp, temp + capacity);
    sort_heap(temp, temp + capacity);
    for (int i = 0; i < capacity; ++i) {
        if (array[i] != temp[i])
            isDataEqual = 0;
    }
    delete [] array;
    delete [] temp;
    testHeapSortSpeed();
    if (isDataEqual)
    {
        cout << endl << "The sort is working fine" << endl << endl;
        return true;
    }
    cerr << "Sort doesn't work properly" << endl << endl;
    return false;
}
