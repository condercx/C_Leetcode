#include <bits/stdc++.h>

// void reverseString(char* s, int sSize) {
//     int left = 0;
//     int right = sSize - 1;
//     for (; left < sSize / 2; left++, right--) {
//         char tmp;
//         tmp = s[right];
//         s[right] = s[left];
//         s[left] = tmp;
//     }
// }

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    for (; left < sSize / 2; left++, right--) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left] ^= s[right];
    }
}