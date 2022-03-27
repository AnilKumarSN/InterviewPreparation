#include "stdio.h"
#include "stdbool.h"
#include "limits.h"
#include "math.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "sys/types.h"
#include "assert.h"
#include "time.h"

/* Major data types typedef. */
typedef unsigned char           boolean;

typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned int            uint32;
typedef unsigned long long      uint64;

typedef char                    int8;
typedef short                   int16;
typedef int                     int32;
typedef long long               int64;

typedef float                   float_t;
typedef double                  double_t;

#define SWAP(a_m, b_m)  (((a_m) ^= (b_m)), ((b_m) ^= (a_m)), ((a_m) ^= (b_m)))
#define MIN(a_m,b_m)    (b_m ^ ((a_m ^ b_m) & -(a_m < b_m)))
#define MAX(a_m,b_m)    (a_m ^ ((a_m ^ b_m) & -(a_m < b_m)))
#define SETBIT(flag_m, mask_m, val_m) (val_m = (val_m & ~mask_m) | (-flag_m & mask_m))
#define MERGE(a_m,b_m,r_m,mask_m) (r_m = a_m ^ ((a_m ^ b_m) & mask_m))

// Print a digit in binary
void dumpBinary(int n, char reason[]) {
    int i;
    printf("0");
    for (i = 1 << 30; i > 0; i = i / 2) {
        if((n & i) != 0) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("[ %d ]: %s ", n, reason);
    printf("\r\n");
}

/*
    Count set bits in an integer

    Write an efficient program to count the number of 1s in the binary representation of an integer.

    Examples :

    Input : n = 6
    Output : 2
    Binary representation of 6 is 110 and has 2 set bits

    Input : n = 13
    Output : 3
    Binary representation of 13 is 1101 and has 3 set bits

    Brian Kernighan’s Algorithm:

    n =  9 (1001)
    count = 0

    Since 9 > 0, subtract by 1 and do bitwise & with (9-1)
    n = 9&8  (1001 & 1000)
    n = 8
    count  = 1

    Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
    n = 8&7  (1000 & 0111)
    n = 0
    count = 2

    Since n = 0, return count which is 2 now.
*/

uint32 countSetBits(int n)
{
    uint32 count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int main()
{
    uint32 i = 9;
    dumpBinary(i, "Input");
    printf("Number of bits set in 0X%x is %d \r\n", i, countSetBits(i));
    return 0;
}