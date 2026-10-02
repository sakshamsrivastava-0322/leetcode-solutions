#include <stdio.h>

/* Check the middle, then discard the half that can't contain the target */
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

/* Local tests */
int main() {
    // Test 1: typical case, target is present
    int a[] = {-1, 0, 3, 5, 9, 12};
    printf("Test 1: %d (expected 4)\n", search(a, 6, 9));

    // Test 2: typical case, target is missing
    printf("Test 2: %d (expected -1)\n", search(a, 6, 2));

    // Test 3: edge case, single element
    int b[] = {5};
    printf("Test 3: %d (expected 0)\n", search(b, 1, 5));

    return 0;
}