//
// Created by Victor on 09.04.2021.
//

#ifndef LAB2_3_DYNAMICARRAY_H
#define LAB2_3_DYNAMICARRAY_H
#include <cstdlib>

struct Data {
    int cookingTime;
    int thinnessOfDough;

    bool operator < (const Data& aSecond) const;
    bool operator == (const Data& aSecond) const;

    Data();

    Data(int a, int b);
};

struct DynamicArray{
    int capacity;
    int realsize;
    Data* innerArray;
    const int alpha = 2;

    DynamicArray();

    void push_front(Data *el);

    void push_back(const Data &el);

    Data pop_front();

    Data pop_back();

    Data get(int n);

    void print();

    int size();

    ~DynamicArray();
};


#endif //LAB2_3_DYNAMICARRAY_H
