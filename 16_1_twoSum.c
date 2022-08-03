#include <stdio.h>
#include <stdlib.h>

/*
    1. 两数之和
        给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

        你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

        你可以按任意顺序返回答案。
*/


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* ans = NULL;

    for(int i = 0; i < numsSize; i++)
        for(int j = i + 1; j < numsSize; j++)
            if(nums[i] + nums[j] == target)
            {
                ans = (int*)malloc(sizeof(int) * 2);
                if(!ans) exit(1);
                ans[0] = i, ans[1] = j;
                *returnSize = 2;
                return ans;
            }

    *returnSize = 0;
    return NULL;
}


int main()
{


    return 0;
}