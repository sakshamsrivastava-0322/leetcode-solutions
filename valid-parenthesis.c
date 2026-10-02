#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Push opening brackets; on a closing bracket, the top must match */
bool isValid(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc(n + 1);
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                free(stack);
                return false;
            }
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1);
    free(stack);
    return result;
}

/* Local tests */
int main() {
    // Test 1: typical case, valid
    printf("Test 1: %s (expected true)\n",
           isValid("()[]{}") ? "true" : "false");

    // Test 2: typical case, wrong closing bracket
    printf("Test 2: %s (expected false)\n",
           isValid("(]") ? "true" : "false");

    // Test 3: edge case, opening bracket never closed
    printf("Test 3: %s (expected false)\n",
           isValid("(") ? "true" : "false");

    // Test 4: edge case, closing bracket with nothing open
    printf("Test 4: %s (expected false)\n",
           isValid("]") ? "true" : "false");

    // Test 5: nested brackets
    printf("Test 5: %s (expected true)\n",
           isValid("{[]}") ? "true" : "false");

    return 0;
}

