//
// Created by Victor on 09.04.2021.
//

#include "DynamicArray.h"
#include <iostream>
#include <iomanip>
#define alpha 2
Data::Data() {
        cookingTime = rand() % 16;
        thinnessOfDough = rand() % 11;
}

Data::Data(int a, int b) {
    cookingTime = a;
    thinnessOfDough = b;
}

bool Data::operator<(const Data &aSecond) const {
    if (cookingTime != aSecond.cookingTime && thinnessOfDough != aSecond.thinnessOfDough){
        return ((2 * cookingTime + thinnessOfDough) < (2 * aSecond.cookingTime + aSecond.thinnessOfDough));
    }
    if (cookingTime == aSecond.cookingTime && thinnessOfDough == aSecond.thinnessOfDough){
        return 0;
    }
    if (cookingTime == aSecond.cookingTime){
        return thinnessOfDough < aSecond.thinnessOfDough;
    }
    return  cookingTime < aSecond.cookingTime;
}

bool Data::operator==(const Data &aSecond) const {
    return ((2 * cookingTime + thinnessOfDough) == (2 * aSecond.cookingTime + aSecond.thinnessOfDough));
}


DynamicArray::DynamicArray() {
    capacity = 1;
    realsize = 0;
    innerArray = new Data[capacity];
}

void DynamicArray::push_back(const Data &el) {
    if (realsize == capacity) {
        capacity *= alpha;
        Data *temp = new Data[capacity];
        for (int i = 0; i < realsize; i++){
            temp[i]=innerArray[i];
        }
        delete [] innerArray;
        innerArray = temp;
    }
    innerArray[realsize] = el;
    realsize++;
}

Data DynamicArray::pop_back() {
    if (!realsize){
//            std::cout << "Error" << std::endl;
        return Data(-1,-1);
    }
    else{
        Data temp = innerArray[realsize-1];
        realsize--;
        return temp;
    }
}

int DynamicArray::size() {
        return realsize;
}

DynamicArray::~DynamicArray() {
    delete[] innerArray;
}

void DynamicArray::push_front(Data *el) {
    if (realsize == capacity) {
        capacity *= alpha;
        Data *temp = new Data[capacity];
        for (int i = realsize; i > 0; i--){
            temp[i] = innerArray[i-1];
        }
        delete [] innerArray;
        innerArray = temp;
    }
    else {
        for (int i = realsize; i > 0; i--){
            innerArray[i]=innerArray[i-1];
        }
    }
    innerArray[0] = *el;
    realsize++;
}

Data DynamicArray::pop_front() {
    if (!realsize){
        std::cout << "Error" << std::endl;
        return Data(-1, -1);
    }
    else if(!(realsize - 1)){
        Data temp = innerArray[0];
        realsize--;
        return temp;
    }
    else{
        Data temp = innerArray[0];
        for (int i = 0; i < realsize-1; i++){
            innerArray[i] = innerArray[i+1];
        }
        realsize--;
        return temp;
    }
}

Data DynamicArray::get(int n) {
    if (n <= realsize && n > 0){
        return innerArray[n-1];
    }
    else {
        std::cout << "Error" << std::endl;
        return Data(-1, -1);
    }
}

void DynamicArray::print() {
        if (!realsize){
            std::cout << "Error" << std::endl;
        }
//        else{
//            for (int i = 0; i < realsize; i++){
//                std::cout << std::setw(9)
//                          << innerArray[i].specialty
//                          << innerArray[i].date
//                          << innerArray[i].usefulness
//                          << std::endl;
//            }
//        }
}

