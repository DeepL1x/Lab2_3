//
// Created by Victor on 08.04.2021.
//

#ifndef LAB2_3_DYNAMICARRAY_H
#define LAB2_3_DYNAMICARRAY_H
#include <iomanip>
struct Data { /*Varenyk*/
    int cookingTime;
    int thinnessOfDough;

    bool operator < (const Data& aSecond) const{
        if (cookingTime != aSecond.cookingTime && thinnessOfDough != aSecond.thinnessOfDough){
            return ((2 * cookingTime + thinnessOfDough) < (2 * aSecond.cookingTime + aSecond.thinnessOfDough));
        }
        if (cookingTime == aSecond.cookingTime && thinnessOfDough == aSecond.thinnessOfDough){
            return thinnessOfDough < aSecond.thinnessOfDough;
        }
        if (cookingTime == aSecond.cookingTime){
            return thinnessOfDough < aSecond.thinnessOfDough;
        }
        return  cookingTime < aSecond.cookingTime;
    }

    bool operator == (const Data& aSecond) const{
        return ((2 * cookingTime + thinnessOfDough) == (2 * aSecond.cookingTime + aSecond.thinnessOfDough));
    }

    Data() {
        cookingTime = rand() % 16;
        thinnessOfDough = rand() % 11;
    }

    Data(int a, int b) {
        cookingTime = a;
        thinnessOfDough = b;
    }
};

struct DynamicArray{
    int capacity;
    int realsize;
    Data* innerArray;
    const int alpha = 2;
    DynamicArray(){
        capacity = 1;
        realsize = 0;
        innerArray = new Data[capacity];
    }
//    void push_front(Data *el) {
//        if (realsize == capacity) {
//            capacity *= alpha;
//            Data *temp = new Data[capacity];
//            for (int i = realsize; i > 0; i--){
//                temp[i] = innerArray[i-1];
//            }
//            delete [] innerArray;
//            innerArray = temp;
//        }
//        else {
//            for (int i = realsize; i > 0; i--){
//                innerArray[i]=innerArray[i-1];
//            }
//        }
//        innerArray[0] = *el;
//        realsize++;
//    }

    void push_back(Data *el){
        if (realsize == capacity) {
            capacity *= alpha;
            Data *temp = new Data[capacity];
            for (int i = 0; i < realsize; i++){
                temp[i]=innerArray[i];
            }
            delete [] innerArray;
            innerArray = temp;
        }
        innerArray[realsize] = *el;
        realsize++;
    }

//    Data pop_front(){
//        if (!realsize){
//            std::cout << "Error" << std::endl;
//        }
//        else if(!(realsize - 1)){
//            Data temp = innerArray[0];
//            realsize--;
//            return temp;
//        }
//        else{
//            Data temp = innerArray[0];
//            for (int i = 0; i < realsize-1; i++){
//                innerArray[i] = innerArray[i+1];
//            }
//            realsize--;
//            return temp;
//        }
//    }

    Data pop_back(){
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

//    Data get(int n){
//        if (n <= realsize && n > 0){
//            return innerArray[n-1];
//        }
//        else {
//            std::cout << "Error" << std::endl;
//        }
//    }

//    void print(){
//        if (!realsize){
//            std::cout << "Error" << std::endl;
//        }
//        else{
//            for (int i = 0; i < realsize; i++){
//                std::cout << std::setw(9)
//                          << innerArray[i].specialty
//                          << innerArray[i].date
//                          << innerArray[i].usefulness
//                          << std::endl;
//            }
//        }
//    }

    int size(){
        return realsize;
    }

    ~DynamicArray(){
        delete [] innerArray;
    }
};
#endif //LAB2_3_DYNAMICARRAY_H
