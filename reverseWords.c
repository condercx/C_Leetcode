#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char* s, int start, int end) {
    for (; start < end; start++, end--) {
        s[start] ^= s[end];
        s[end] ^= s[start];
        s[start] ^= s[end];
    }
}

void cleanBlanks(char* s) {
    int start = 0;
    int end = strlen(s) - 1;
    while (s[start] == ' ') start++;
    while (s[end] == ' ') end--;
    int slow = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] == ' ' && s[i+1] == ' ') continue;
        s[slow] = s[i];
        slow++;
    }
    s[slow] = '\0';
}
char* reverseWords(char* s) {
    cleanBlanks(s);
    int len = strlen(s);
    reverse(s, 0, len - 1);
    int slow = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse(s, slow, i - 1);
            slow = i + 1;
        }
    }
    return s;
}