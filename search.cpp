#include <bits/stdc++.h>
int search (int* nums, int numSize, int target) {
    int left = 0;
    int right = numSize - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if(nums[middle] < target){
            left = middle + 1;
        }
        else if (nums[middle] > target){
            right = middle - 1;
        }
        else{
            return middle;
        }
    }
    return -1;
 }

int main () {
    int nums[] = {-1,0,3,5,9,12};
    int target = 2;
    int numSize = sizeof(nums)/sizeof(nums[0]);
    int answer = search(nums, numSize, target);
    printf("%d\n", answer);
    return 0;
 }