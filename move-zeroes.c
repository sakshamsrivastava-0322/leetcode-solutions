#include <stdio.h>

/* Copy non-zeros to the front in order, then fill the rest with zeros */
void moveZeroes(int* nums, int numsSize) {
    int pos = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }

    while (pos < numsSize) {
        nums[pos] = 0;
        pos++;
    }
}

/* Helper for local tests only */
void printArray(int* nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", nums[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]");
}

/* Local tests */
int main() {
    // Test 1: typical case
    int a[] = {0, 1, 0, 3, 12};
    moveZeroes(a, 5);
    printf("Test 1: ");
    printArray(a, 5);
    printf(" (expected [1, 3, 12, 0, 0])\n");

    // Test 2: edge case, single zero
    int b[] = {0};
    moveZeroes(b, 1);
    printf("Test 2: ");
    printArray(b, 1);
    printf(" (expected [0])\n");

    // Test 3: edge case, no zeros
    int c[] = {1, 2, 3};
    moveZeroes(c, 3);
    printf("Test 3: ");
    printArray(c, 3);
    printf(" (expected [1, 2, 3])\n");

    return 0;
}