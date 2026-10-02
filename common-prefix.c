#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Start with the first string as the prefix, shrink it for each other string */
char* longestCommonPrefix(char** strs, int strsSize) {
    int prefixLen = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < prefixLen && strs[i][j] == strs[0][j]) {
            j++;
        }
        prefixLen = j;
    }

    char* result = (char*)malloc(prefixLen + 1);
    memcpy(result, strs[0], prefixLen);
    result[prefixLen] = '\0';
    return result;
}

/* Local tests */
int main() {
    // Test 1: typical case
    char* a[] = {"flower", "flow", "flight"};
    char* r1 = longestCommonPrefix(a, 3);
    printf("Test 1: \"%s\" (expected \"fl\")\n", r1);
    free(r1);

    // Test 2: edge case, no common prefix
    char* b[] = {"dog", "racecar", "car"};
    char* r2 = longestCommonPrefix(b, 3);
    printf("Test 2: \"%s\" (expected \"\")\n", r2);
    free(r2);

    // Test 3: edge case, single string
    char* c[] = {"alone"};
    char* r3 = longestCommonPrefix(c, 1);
    printf("Test 3: \"%s\" (expected \"alone\")\n", r3);
    free(r3);

    return 0;
}