#include <bits/stdc++.h>
int cmp(const void* arg1, const void* arg2) {
    return *(int*)arg1 > *(int*)arg2;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int** ans = (int**)malloc(sizeof(int*) * (numsSize * numsSize * numsSize / 6));
    int ans_count = 0;
    int i, j;
    
    for(i = 0; i < numsSize - 3; i++) {
        if ((nums[i] >= 0) && (nums[i] > target)) break;
        if ((i > 0) && (nums[i] == nums[i - 1])) continue;

        for(j = i + 1; j < numsSize - 2; j++) {
            if ((nums[j] >= 0) && (nums[i] + nums[j] > target)) break;
            if ((j > (i + 1)) && (nums[j] == nums[j - 1])) continue;

            int left = j + 1;
            int right =numsSize - 1;

            while (left < right) {
                long long res = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (res > target) right--;
                else if (res < target) left++;
                else {
                    int* tmp = (int*)malloc(sizeof(int) * 4);
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = nums[left];
                    tmp[3] = nums[right];
                    ans[ans_count++] = tmp;

                    while ((right > left) && (nums[right] == nums[right - 1])) right--;
                    while ((right > left) && (nums[left] == nums[left + 1])) left++;

                    left++; right--;
                }
            }
        }
    }

    *returnSize = ans_count;
    int* column = (int*)malloc(sizeof(int) * ans_count);
    for (i = 0; i < ans_count; i++) column[i] = 4;
    *returnColumnSizes = column;
    return ans;
}