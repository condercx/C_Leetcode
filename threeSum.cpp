#include <bits/stdc++.h>
int cmp(const void* ptr1, const void* ptr2) {
    return *(int*)ptr1 - *(int*)ptr2;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ans = (int**)malloc(sizeof(int*) * (numsSize * numsSize / 2));
    int anscount = 0;
    if (numsSize < 3) {
        *returnSize = 0;
        return ans;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int i, sum;
    for (i = 0; i < numsSize -2; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1;
        int right = numsSize - 1;

        while (right > left) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            }
            else if (sum > 0) {
                right--;
            }
            else {
                int* arr = (int*)malloc(sizeof(int) * 3);
                arr[0] = nums[i];
                arr[1] = nums[left];
                arr[2] = nums[right];

                ans[anscount++] = arr;

                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;

                left++;right--;
            }
        }
    }

    *returnSize = anscount;
    *returnColumnSizes = (int*)malloc(sizeof(int) * anscount);
    for (i = 0; i < anscount; i++) (*returnColumnSizes)[i] = 3;
    return ans;
}