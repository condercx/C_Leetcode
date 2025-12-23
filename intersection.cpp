#include <bits/stdc++.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int num1Cnt[1001] = {0};
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* results = (int*)calloc(lessSize, sizeof(int));
    int resultSize = 0;

    for (int i = 0; i < nums1Size; i++) {
        num1Cnt[nums1[i]]++;
    }

    for (int j = 0; j < nums2Size; j++) {
        if (num1Cnt[nums2[j]] > 0) {
            results[resultSize] = nums2[j];
            resultSize++;
            num1Cnt[nums2[j]] = 0;
        }
    }
    *returnSize = resultSize;
    return results;
}