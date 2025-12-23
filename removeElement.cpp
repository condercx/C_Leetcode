#include <bits/stdc++.h>

int removeElement(int* nums, int numsSize, int val) {
    int slowIndex = 0;
    for (int flastIndex = 0; flastIndex < numsSize; flastIndex++){
        if (val != nums[flastIndex]){
            nums[slowIndex++] = nums[flastIndex];
        }
    }
    return slowIndex;
}

int main (){
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int answer = removeElement(nums, numsSize, val);
    printf("%d\n", answer);
    return 0; 
}