#include <stdio.h>
#include <string.h>

/* Two pointers: swap from both ends, move toward the middle */
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

/* Local tests */
int main() {
    // Test 1: typical case (odd length)
    char a[] = "hello";
    reverseString(a, strlen(a));
    printf("Test 1: %s (expected olleh)\n", a);

    // Test 2: edge case, single character
    char b[] = "x";
    reverseString(b, strlen(b));
    printf("Test 2: %s (expected x)\n", b);

    // Test 3: even length
    char c[] = "abcd";
    reverseString(c, strlen(c));
    printf("Test 3: %s (expected dcba)\n", c);

    return 0;
}