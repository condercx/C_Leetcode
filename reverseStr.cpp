#include <bits/stdc++.h>

void reverse(char* s, int left, int right) {
    for (int i = left, j = right; i < j; i++, j--) {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
    }
}
char* reverseStr(char* s, int k) {
    int left = 0, len = strlen(s);
    while (left + 2 * k <= len) {
        reverse(s, left, left + k - 1);
        left += 2 * k;
    }

    if (left < len) {
        int remain = len - left;
        if (remain < k) {
            reverse(s, left, len - 1);
        } 
        else {
            reverse(s, left, left + k - 1);
        }
    }

    return s;
}