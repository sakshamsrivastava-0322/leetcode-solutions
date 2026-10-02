#include <stdio.h>
#include <limits.h>

/* One pass: track the lowest price so far and the best profit */
int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

/* Local tests */
int main() {
    // Test 1: typical case
    int a[] = {7, 1, 5, 3, 6, 4};
    printf("Test 1: %d (expected 5)\n", maxProfit(a, 6));

    // Test 2: edge case, prices only go down
    int b[] = {7, 6, 4, 3, 1};
    printf("Test 2: %d (expected 0)\n", maxProfit(b, 5));

    // Test 3: edge case, single day
    int c[] = {5};
    printf("Test 3: %d (expected 0)\n", maxProfit(c, 1));

    return 0;
}