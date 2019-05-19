#include <unistd.h>
//#define checkMemoryLeak

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "InsertionSort.h"
#include "QuickSelect.h"

//////////////////////////////////////////////////
void test(void);

//////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    srand((unsigned) time(NULL));
    
#ifdef checkMemoryLeak
    while (true) {
        test();
        sleep(1);
    }
#else
    test();
#endif
    
    return EXIT_SUCCESS;
}

void test() {
    int testCount = 10;
    int subTestCount = 1;
    int printLimit = 20;
    int numElement = 20;
    int Kth = 5;
    
    int beginOfPartial = 5;
    int endOfPartial = 16;
    
    int array[numElement];
    
    for (int testNo=0; testNo<testCount; testNo++) {
        printf("\n=== [Test #%d] === ", testNo+1);
        
        switch (testNo) {
            case 0:
                printf("Standard\n");
                printf("Select %dth value.\n\n", Kth);
            {
                for (int i=0; i<subTestCount; i++) {
                    printf("input : ");
                    for (int j=0; j<numElement; j++) {
                        array[j] = rand()%100;
                        if (j<printLimit) {
                            printf("%2d, ", array[j]);
                        }
                    }
                    printf("\n");
                    
                    int KthIndex = quickSelect(array, numElement, Kth, 0, 0, QS_OPTION_NONE);
                    if (KthIndex < 0) {
                        printf("error [%s] : could not select.\n", __func__);
                        break;
                    }
                    printf("value of %dth = %d\n", Kth, array[KthIndex]);
                    
                    bool check = insertionSortSimple(array, numElement, SORT_OPTION_ASCENDING_ORDER);
                    if (!check) {
                        printf("error [%s] : could not sort.\n", __func__);
                        break;
                    }
                    printf("sort  : ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        if (j == Kth-1) {
                            printf("%2d ", Kth);
                        }
                        else {
                            printf("    ");
                        }
                    }
                    printf("\n");
                    
                    printf("        ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        printf("%2d, ", array[j]);
                    }
                    printf("\n");
                    printf("\n");
                }
            }
                break;
            case 1:
                printf("Standard (descending order)\n");
                printf("Select %dth value.\n\n", Kth);
            {
                for (int i=0; i<subTestCount; i++) {
                    printf("input : ");
                    for (int j=0; j<numElement; j++) {
                        array[j] = rand()%100;
                        if (j<printLimit) {
                            printf("%2d, ", array[j]);
                        }
                    }
                    printf("\n");
                    
                    int KthIndex = quickSelect(array, numElement, Kth, 0, 0, QS_OPTION_DESCENDING_ORDER);
                    if (KthIndex < 0) {
                        printf("error [%s] : could not select.\n", __func__);
                        break;
                    }
                    printf("value of %dth = %d\n", Kth, array[KthIndex]);
                    
                    bool check = insertionSortSimple(array, numElement, SORT_OPTION_DESCENDING_ORDER);
                    if (!check) {
                        printf("error [%s] : could not sort.\n", __func__);
                        break;
                    }
                    printf("sort  : ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        if (j == Kth-1) {
                            printf("%2d ", Kth);
                        }
                        else {
                            printf("    ");
                        }
                    }
                    printf("\n");
                    
                    printf("        ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        printf("%2d, ", array[j]);
                    }
                    printf("\n");
                    printf("\n");
                }
            }
                break;
            case 2:
                printf("Partial\n");
                printf("Select %dth value.\n\n", Kth);
            {
                for (int i=0; i<subTestCount; i++) {
                    printf("input : ");
                    for (int j=0; j<numElement; j++) {
                        array[j] = rand()%100;
                        if (j == beginOfPartial) {
                            printf("[ ");
                        }
                        if (j<printLimit) {
                            printf("%2d, ", array[j]);
                        }
                        if (j == endOfPartial) {
                            printf("] ");
                        }
                    }
                    printf("\n");
                    
                    int KthIndex = quickSelect(array, numElement, Kth, beginOfPartial, endOfPartial, QS_OPTION_RANGE_PARTIAL);
                    if (KthIndex < 0) {
                        printf("error [%s] : could not select.\n", __func__);
                        break;
                    }
                    printf("value of %dth = %d\n", Kth, array[KthIndex]);
                    
                    bool check = insertionSort(array, numElement, beginOfPartial, endOfPartial, SORT_OPTION_RANGE_PARTIAL);
                    if (!check) {
                        printf("error [%s] : could not sort.\n", __func__);
                        break;
                    }
                    printf("sort  : ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        if (j == beginOfPartial) {
                            printf("  ");
                        }
                        if (j == Kth + beginOfPartial -1) {
                            printf("%2d ", Kth);
                        }
                        else {
                            printf("    ");
                        }
                        if (j == endOfPartial) {
                            printf("  ");
                        }
                    }
                    printf("\n");
                    
                    printf("        ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        if (j == beginOfPartial) {
                            printf("[ ");
                        }
                        printf("%2d, ", array[j]);
                        if (j == endOfPartial) {
                            printf("] ");
                        }
                    }
                    printf("\n");
                    printf("\n");
                }
            }
                break;
            case 3:
                printf("Partial (descending order)\n");
                printf("Select %dth value.\n\n", Kth);
            {
                for (int i=0; i<subTestCount; i++) {
                    printf("input : ");
                    for (int j=0; j<numElement; j++) {
                        array[j] = rand()%100;
                        if (j == beginOfPartial) {
                            printf("[ ");
                        }
                        if (j<printLimit) {
                            printf("%2d, ", array[j]);
                        }
                        if (j == endOfPartial) {
                            printf("] ");
                        }
                    }
                    printf("\n");
                    
                    int KthIndex = quickSelect(array, numElement, Kth, beginOfPartial, endOfPartial, QS_OPTION_RANGE_PARTIAL | QS_OPTION_DESCENDING_ORDER);
                    if (KthIndex < 0) {
                        printf("error [%s] : could not select.\n", __func__);
                        break;
                    }
                    printf("value of %dth = %d\n", Kth, array[KthIndex]);
                    
                    bool check = insertionSort(array, numElement, beginOfPartial, endOfPartial, SORT_OPTION_RANGE_PARTIAL | SORT_OPTION_DESCENDING_ORDER);
                    if (!check) {
                        printf("error [%s] : could not sort.\n", __func__);
                        break;
                    }
                    printf("sort  : ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        if (j == beginOfPartial) {
                            printf("  ");
                        }
                        if (j == Kth + beginOfPartial -1) {
                            printf("%2d ", Kth);
                        }
                        else {
                            printf("    ");
                        }
                        if (j == endOfPartial) {
                            printf("  ");
                        }
                    }
                    printf("\n");
                    
                    printf("        ");
                    for (int j=0; j<numElement; j++) {
                        if (j>printLimit) break;
                        if (j == beginOfPartial) {
                            printf("[ ");
                        }
                        printf("%2d, ", array[j]);
                        if (j == endOfPartial) {
                            printf("] ");
                        }
                    }
                    printf("\n");
                    printf("\n");
                }
            }
                // *************************************
                testNo = INT_MAX - 1;        // stop loop.
                // *************************************
                break;
            default:
                break;
        }
    }
}
