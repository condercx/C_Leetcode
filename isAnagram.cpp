#include <bits/stdc++.h>

// bool isAnagram(char* s, char* t) {
//     int slen = strlen(s), tlen = strlen(t);
//     if (slen != tlen) return false;

//     int sh[26] = {0}, th[26] = {0};

//     for (int i = 0; i < slen; i++) {
//         sh[s[i] - 'a'] += 1;
//         th[t[i] - 'a'] += 1;
//     }

//     for (int j = 0; j < 26; j++) {
//         if (sh[j] != th[j]) return false;
//     }
//     return true;
// }

bool isAnagram(char* s, char* t) {
    int slen = strlen(s), tlen = strlen(t);
    if (slen != tlen) return false;

    int sh[26] = {0};
    for (int i = 0; i < slen; i++) {
        sh[s[i] - 'a']++;
    }
    for (int j = 0; j < slen; j++) {
        sh[t[j] - 'a']--;
        if (sh[t[j] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}