#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Count letters: +1 for s, -1 for t. All zeros means anagram. */
bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

/* Local tests */
int main() {
    // Test 1: typical case, is an anagram
    printf("Test 1: %s (expected true)\n",
           isAnagram("anagram", "nagaram") ? "true" : "false");

    // Test 2: typical case, not an anagram
    printf("Test 2: %s (expected false)\n",
           isAnagram("rat", "car") ? "true" : "false");

    // Test 3: edge case, different lengths
    printf("Test 3: %s (expected false)\n",
           isAnagram("a", "ab") ? "true" : "false");

    return 0;
}