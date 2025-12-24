#include <bits/stdc++.h>



bool canConstruct(char* ransomNote, char* magazine) {
    int hashtable[26] = {0};
    int i;
    if (strlen(ransomNote) > strlen(magazine)) return false;
    for (i = 0; i < strlen(magazine); i++) {
        hashtable[magazine[i] - 'a']++;
    }

    for (i = 0; i < strlen(ransomNote); i++) {
        hashtable[ransomNote[i] - 'a']--;
        if (hashtable[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}