#ifndef QuickSelect_h
#define QuickSelect_h

#include <stdbool.h>

//////////////////////////////////////////////////
#define QS_SIZE_OF_GROUP 5

typedef enum QUICKSELECTOption {
    QS_OPTION_NONE = 0,
    QS_OPTION_ORDER = 0x0001,
    QS_OPTION_RANGE = 0x0002,
    
    QS_OPTION_ASCENDING_ORDER = 0x0000,
    QS_OPTION_DESCENDING_ORDER = 0x0001,
    
    QS_OPTION_RANGE_ALL = 0x0000,
    QS_OPTION_RANGE_PARTIAL = 0x0002
} QS_OPTION_e;

//////////////////////////////////////////////////
int quickSelect(int *array, int length, int Kth, int leftIndex, int rightIndex, QS_OPTION_e option);

#endif
