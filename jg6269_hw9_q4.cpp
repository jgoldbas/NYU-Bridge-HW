//
// Created by Julianna Goldbas on 3/7/20.
//  HW 9 Question 4 oddsKeepEvenFlip
/*
Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)
This function gets an array of integers arr and its logical size arrSize.
When called, it should reorder (in-place) the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).
Implementation requirements:
1. Your function should run in linear time. That is, if there are n items in arr, calling
oddsKeepEvensFlip(arr, n) will run in �(�).
2. Write a main() program that tests this function.*/


#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {
    const int MAX_IN_ARRAY = 6;
    int arr[MAX_IN_ARRAY] = {5,2,11,7,6,4};

    cout << "The original array: { ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;

    oddsKeepEvensFlip(arr, MAX_IN_ARRAY);
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    //should produce [5, 11, 7, 4, 6. 2]
    int i, k;
    int tempArr[arrSize]; //temporary new array to hold the new sorted sequence
    //see Module 11

    //for odd numbers L->R
    k = 0; //keep this index var for both loops
    for (i = 0; i < arrSize; i += 1) {

        if (arr[i] % 2 != 0) {
            tempArr[k] = arr[i];
            k++;
        }
    }
    //for evens in reverse
    for (i = arrSize - 1; i >= 0; i -= 1) {
        if (arr[i] % 2 == 0) {
            tempArr[k] = arr[i]; //using k index var for temp
            k++;
        }
    }
    cout << "The sorted array: { ";
    for (i = 0; i < arrSize; i++) {
        cout << tempArr[i] << " ";
       // cout << tempArr[i] - 1 << "}";
    }
    //cout << tempArr[i] << " }" << endl;
    cout << "}" << endl;
}



