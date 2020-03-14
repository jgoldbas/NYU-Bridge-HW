
#include <iostream>
using namespace std;

int* getPosNumsF1(int* arr, int arrSize, int& outPosArrSize);
// This function gets an array and its logical size. When called
// it creates a NEW ARRAY w/ only +nums from arr. the function
// creates an array w/ only + nums.

void getPosNumsF2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
//updates the output parameter outPosArr with the base address of the array
//(containing the + numbers), and the output parameter outPosArrSize with
//the array’s logical size.

int* getPosNumsF3(int* arr, int arrSize, int* outPosArrSizePtr);
//returns the base address of the array (containing the positive numbers),
//and uses the pointer outPosArrSizePtr to update array’s logical size.

void getPosNumsF4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
//uses the pointer outPosArrPtr to update the base address of the array (containing
//the positive numbers), and the pointer outPosArrSizePtr to update the array’s
// logical size.

void printArray(int* arr, int arrSize);

int main () {
    int arr[] = {3, -1, 0, 6, 4}; // 3 6 4
    int arrSize = 5;
    int outPosArrSize;
    int* outPosArr;
    int outPosArrSizePtr;
    int* outPosArrPtr;

    cout << "Part a. " << endl;
    int* arr1 = getPosNumsF1(arr, arrSize, outPosArrSize);
    printArray (arr1, outPosArrSize);
    cout << "logical size: " << outPosArrSize << endl;
    cout << "updated base address: " << arr1 << endl;


    /*cout << "Part b. " << endl;
    getPosNumsF2(arr, arrSize, outPosArr, outPosArrSize);
    //cout << "outPosArrSize2: " << outPosArrSize << endl;
    printArray(outPosArr, outPosArrSize);

    cout << "Part c. " << endl;
    getPosNumsF3(arr, arrSize, outPosArrSizePtr);
    printArray(outPosArr, outPosArrSize);

    cout << "Part d. " << endl;
    getPosNumsF4(arr, arrSize, &outPosArrPtr, &outPosArrSizePtr);
    cout << "updated base address: " << outPosArrPtr << endl;
    cout << "updated logical size: " << outPosArrSizePtr <<  endl;
    printArray(outPosArrPtr, outPosArrSizePtr);
    //delete [] arr1;
    delete [] outPosArr;*/
    return 0;
}
/*
int* getPosNumsF1(int* arr, int arrSize, int& outPosArrSize) {
    outPosArrSize = 0;
    //for every element in the inputted arr[], if # is + add to the new posArray size

    //loop to get the updated array SIZE
    for (int i = 0; i < arrSize; i += 1) {
        if (arr[i] > 0)
            outPosArrSize++; //add +1 to size
    }

    int* tempArr = new int[outPosArrSize]; //new array pointed to by 'temp'

    int index = 0; //initializing an index value
    // loop to get updated elements into new array
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0){
            tempArr[index] = arr[i];
            index++;
        }
    }
    return tempArr; //returns tempArray base address containing only + nums to the
    //int* arr1; value which is a pointer
}

void getPosNumsF2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i += 1) {
        if (arr[i] > 0)
            outPosArrSize++;
    }
    outPosArr = new int[outPosArrSize]; //new pos number array of new size.
    int index = 0; //initializing how many indexes
    for (int i = 0; i < arrSize; i++) { //this loop COPIES the pos values kept from the first for loop
        //to a new local array outPosArr.
        if (arr[i] > 0) {
            outPosArr[index] = arr[i];
            index++;
        }
    }
}

int* getPosNumsF3(int* arr, int arrSize, int* outPosArrSizePtr) {
    int outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0)
            outPosArrSize++;
    }
    int* tempArr3 = new int[outPosArrSize];
    int index = 0;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > 0){
            tempArr3[index] = arr[i];
            index++;
        }
    }
    return tempArr3;
}*/

void getPosNumsF4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
//uses the pointer outPosArrPtr to update the base address of the array (containing
//the positive numbers), uses
    int outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0)
            outPosArrSize++;
    }
    outPosArrSizePtr = &outPosArrSize;

    int tempArr4[*outPosArrSizePtr];
    for(int i = 0, index = 0; i < arrSize; i++, index++) {
        if(arr[i] > 0) {
            tempArr4[index] = arr[i];
        }
    }
    *outPosArrSizePtr = outPosArrSize;
    int* tempPtr;
    tempPtr = tempArr4;
    *outPosArrPtr = tempPtr;
    for (int i = 0; i < *outPosArrSizePtr; i++) {
        cout << *(*outPosArrPtr + i) << " " ;

    }

    cout << endl;


}

void printArray(int* arr, int arrSize) {
    cout << "New array with only positive nums: ";
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



