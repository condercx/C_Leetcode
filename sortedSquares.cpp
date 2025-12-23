#include <bits/stdc++.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = numsSize;
    
    int right = numsSize - 1;
    int left = 0;
    
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for (int k = numsSize - 1; k >= 0; k--)
    {
        if(nums[right] + nums[left] > 0)
        {
            ans[k] = nums[right] * nums[right];
            right--;
        }
        else{
            ans[k] = nums[left] * nums[left];
            left++;
        }
    }

    return ans;
}


int main()
{
    int nums[] = {-7,-3,2,3,11};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* ans = sortedSquares(nums, numsSize, &returnSize);
    for (int i = 0;i < numsSize;i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    free(ans);
    return 0;
}