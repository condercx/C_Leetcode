#include <bits/stdc++.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int ans = 1e9;
    int i = 0;
    int sum = 0;
    int sumlength = 0;
    for (int j = 0; j < numsSize; j++)
    {
        sum += nums[j];
        while(sum >= target)
        {
            sumlength = j - i + 1;
            ans = ans < sumlength ? ans : sumlength;
            sum -= nums[i++];
        }
    }
    return ans == 1e9 ? 0 : ans;
}

int main()
{
    int target = 11;
    int nums[] = {1,1,1,1,1,1,1,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int ans = minSubArrayLen(target, nums, numsSize);
    printf("%d\n", ans);
}