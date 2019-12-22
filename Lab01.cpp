/*
 Lab 1
 James Foti
 Red ID: 820124143
 CS 310
 Professor Healey
 6/13/2019
 */

#include <iostream>

int max(int a, int b);
void knapSack(int weights[], int values[], int weightLimit, int size);
int scanner(unsigned short arr[], int size, int distance = 20, int i = 0, int j = 1, int k = 2);
int scannerModified(unsigned short array[], int size, int distance = 20, int i = 0, int j = 1, int k = 2);

// 3.6 Exercises - Question 2
int max(int a, int b) {
    if (a > b) return a;
    if (b > a) return b;
    return a;
}

void knapSack(int weights[], int values[], int weightLimit, int size) {
    int itemsInBag[size];
    int valueTable[size + 1][weightLimit + 1];
    
    for (int i = 0; i < size+1; i++) {
        for (int w = 0; w < weightLimit+1; w++) {
            if (i == 0 || w == 0)
                valueTable[i][w] = 0;
            else if (weights[i - 1] <= w)
                valueTable[i][w] = max(values[i - 1] + valueTable[i - 1][w - weights[i - 1]], valueTable[i - 1][w]);
            else
                valueTable[i][w] = valueTable[i - 1][w];
        }
    }
    int maxValue = valueTable[size][weightLimit];
    
    for (int i = size; i > 0 && maxValue > 0; i--) {
        if (maxValue != valueTable[i - 1][weightLimit]) {
            itemsInBag[i-1] = 1;
            maxValue = maxValue - values[i - 1];
            weightLimit = weightLimit - weights[i - 1];
        }
        else {
            itemsInBag[i-1] = 0;
        }
    }
    std::cout<<"Items in knapsack: ";
    for (int i = 0; i<size; i++) {
        if (itemsInBag[i] > 1 || itemsInBag[i] < 0) {
            std::cout<<0<<" ";
        }
        else {
            std::cout<<itemsInBag[i]<<" ";
        }
    }
}

// 3.6 Exercises - Questions 3-4
int scanner(unsigned short array[], int size, int distance, int i, int j, int k) {
    if (i < size && j < size && k < size) {
        if ((array[j]-array[i] == distance) && (array[k] - array[j] == distance)) return i;
        else if (array[j] - array[i] < distance) return scanner(array, size, distance, i, ++j, k);
        else if (array[k] - array[j] < distance) return scanner(array, size, distance, i, j, ++k);
        else return scanner(array, size, distance, ++i, j, k);
    }
    else return -1;
}
int scannerModified(unsigned short array[], int size, int distance, int i, int j, int k) {
    if (i < size && j < size && k < size) {
        if ((array[j]-array[i] == distance) && (array[k] - array[j] == distance)) return -1;
        else if (i != k && j != k && (array[j]-array[i] == distance) && (array[k] - array[j] != distance)) return i;
        else if (array[j] - array[i] < distance) return scannerModified(array, size, distance, i, ++j, k);
        else if (array[k] - array[j] < distance) return scannerModified(array, size, distance, i, j, ++k);
        else return scannerModified(array, size, distance, ++i, j, k);
    }
    else return -1;
}

// 5.4 Exercises - Question 6
class DynamicCharArray {
private:
    char *arr;
    int length;
public:
    DynamicCharArray() {
        arr = new char[8];
    }
    DynamicCharArray(int size) {
        arr = new char[size];
        length = size;
    }
    DynamicCharArray (const DynamicCharArray &other) {
        std::cout<<"copied";
        arr = other.arr;
    }
    int size() {
        return length;
    }
    void expand(int amount) {
        const int newSize = length + amount;
        char *newArray = new char[newSize];
        for (int i = 0; i < length; i++) {
            newArray[i] = arr[i];
        }
        delete [] arr;
        arr = newArray;
        length = newSize;
    }
    ~DynamicCharArray() {
        delete [] arr;
    }
};

int main(int argc, const char * argv[]) {
    // 3.6 Exercises - Question 2 (TESTS)
    int values1[] = {15,20,30,40,50};
    int weights1[] = {1, 2, 3, 4, 5};
    int weightLimit1 = 5;
    int size1 = sizeof(values1) / sizeof(values1[0]);
    knapSack(weights1, values1, weightLimit1, size1);
    std::cout<<"\n";
    std::cout<<"\n";
    
    int values2[] = {1, 2, 3, 4, 5};
    int weights2[] = {15,20,30,40,50};
    int weightLimit2 = 50;
    int size2 = sizeof(values2) / sizeof(values2[0]);
    knapSack(weights2, values2, weightLimit2, size2);
    std::cout<<"\n";
    std::cout<<"\n";
    
    int values3[] = {10, 20, 30};
    int weights3[] = {60, 100, 120};
    int weightLimit3 = 160;
    int size3 = sizeof(values3) / sizeof(values3[0]);
    knapSack(weights3, values3, weightLimit3, size3);
    std::cout<<"\n";
    std::cout<<"\n";
    
    // 3.6 Exercises - Question 3-4 (TESTS)
    unsigned short data1[] = {10,20,31,40,55,60,65525};
    unsigned short data2[] = {1, 2, 3, 4, 5, 6, 7};
    unsigned short data3[] = {1, 2, 3, 4, 40, 60, 80};
    unsigned short data4[] = {3, 4, 20, 40, 60};
    
    int size_1 = sizeof(data1) / sizeof(data1[0]);
    int size_2 = sizeof(data2) / sizeof(data2[0]);
    int size_3 = sizeof(data3) / sizeof(data3[0]);
    int size_4 = sizeof(data4) / sizeof(data4[0]);
    
    std::cout<<"Index position: "<<scanner(data1, size_1)<<"\n";
    std::cout<<"Index position: "<<scannerModified(data1, size1);
    std::cout<<"\n";
    std::cout<<"\n";
    
    std::cout<<"Index position: "<<scanner(data2, size_2)<<"\n";
    std::cout<<"Index position: "<<scannerModified(data2, size2);
    std::cout<<"\n";
    std::cout<<"\n";
    
    std::cout<<"Index position: "<<scanner(data3, size_3)<<"\n";
    std::cout<<"Index position: "<<scannerModified(data3, size_3);
    std::cout<<"\n";
    std::cout<<"\n";
    
    std::cout<<"Index position: "<<scanner(data4, 7, 20)<<"\n";
    std::cout<<"Index position: "<<scannerModified(data4, size_4);
    std::cout<<"\n";
    std::cout<<"\n";
    
    // 5.4 Exercises - Question 6 (TESTS)
    DynamicCharArray d1(5);
    d1.expand(4);
    d1.expand(5);
    std::cout<<"Size of array: "<<d1.size();
    std::cout <<"\n";
    
    DynamicCharArray d2(20);
    d2.expand(4);
    d2.expand(5);
    std::cout<<"Size of array: "<<d2.size();
    std::cout<<"\n";
    
    return 0;
}
