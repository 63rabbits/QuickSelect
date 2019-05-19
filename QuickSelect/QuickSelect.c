#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "InsertionSort.h"
#include "QuickSelect.h"

//////////////////////////////////////////////////
int quickSelectSlave(int *array, int length, int Kth, int leftIndex, int rightIndex);
int pivotQS(int *array, int length, int leftIndex, int rightIndex);
int partitionQS(int *array, int length, int leftIndex, int rightIndex, int pivotIndex);
int medianQS(int *array, int length, int leftIndex, int rightIndex);
bool swapQS(int *array, int indexA, int indexB);

//////////////////////////////////////////////////
//  public
int quickSelect(int *array, int length, int Kth, int leftIndex, int rightIndex, QS_OPTION_e option) {
    // Block illegal parameters.
    if (array == NULL) return INT_MIN;
    if (length <= 0) return INT_MIN;
    if ((leftIndex < 0) || (leftIndex >= length)) return INT_MIN;
    if ((rightIndex < 0) || (rightIndex >= length)) return INT_MIN;
    if (leftIndex > rightIndex) return INT_MIN;
    if (Kth <= 0) return INT_MIN;
    if (Kth > length) return INT_MIN;
    
    if ((QS_OPTION_RANGE & option) == QS_OPTION_RANGE_PARTIAL) {
        if (Kth > (rightIndex - leftIndex + 1)) return INT_MIN;
    }
    else {
        leftIndex = 0;
        rightIndex = length - 1;
    }
    int partialLength = rightIndex - leftIndex + 1;
    
    if ((QS_OPTION_ORDER & option) == QS_OPTION_ASCENDING_ORDER) {
        Kth = Kth - 1;
    }
    else {
        Kth = partialLength - Kth;
    }
    
    int *newArray = array;
    
    int KthIndex = quickSelectSlave(&newArray[leftIndex], partialLength, Kth, 0, (partialLength - 1)) + leftIndex;
    
    return KthIndex;
}

//////////////////////////////////////////////////
//  private
int quickSelectSlave(int *array, int length, int Kth, int leftIndex, int rightIndex) {
    // Note:This algorithm shuffles the contents of the array.
    
    if (leftIndex == rightIndex) return leftIndex;
    
    int pivotIndex = pivotQS(array, length, leftIndex, rightIndex);
    pivotIndex = partitionQS(array, length, leftIndex, rightIndex, pivotIndex);
    
    if (pivotIndex == Kth) {
        return pivotIndex;
    }
    else if (Kth < pivotIndex) {
        rightIndex = pivotIndex - 1;
    }
    else {
        leftIndex = pivotIndex + 1;
    }
    return quickSelectSlave(array, length, Kth, leftIndex, rightIndex);
}

int pivotQS(int *array, int length, int leftIndex, int rightIndex) {
    if ((rightIndex - leftIndex) < QS_SIZE_OF_GROUP) {
        return medianQS(array, length, leftIndex, rightIndex);
    }
    
    int storeIndex = leftIndex;
    for (int i=leftIndex; i<=rightIndex; i+=QS_SIZE_OF_GROUP) {
        int subRightIndex = i + QS_SIZE_OF_GROUP - 1;
        if (rightIndex < subRightIndex) {
            subRightIndex = rightIndex;
        }
        int medianIndex = medianQS(array, length, i, subRightIndex);
        swapQS(array, storeIndex, medianIndex);
        storeIndex++;
    }
    
    return pivotQS(array, length, leftIndex, storeIndex-1);
}

int partitionQS(int *array, int length, int leftIndex, int rightIndex, int pivotIndex) {
    int pivotValue = array[pivotIndex];
    swapQS(array, pivotIndex, rightIndex);
    int storeIndex = leftIndex;
    for (int i=leftIndex; i<rightIndex; i++) {
        if (array[i] < pivotValue) {
            swapQS(array, storeIndex, i);
            storeIndex++;
        }
    }
    swapQS(array, storeIndex, rightIndex);
    
    return storeIndex;
}

int medianQS(int *array, int length, int leftIndex, int rightIndex) {
    insertionSort(array, length, leftIndex, rightIndex, SORT_OPTION_RANGE_PARTIAL);
    return leftIndex + (rightIndex - leftIndex)/2;
}

bool swapQS(int *array, int indexA, int indexB) {
    int temp = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = temp;
    
    return true;
}
