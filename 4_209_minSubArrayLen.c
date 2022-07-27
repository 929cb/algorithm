#include <stdio.h>

/*
    给定一个含有 n 个正整数的数组和一个正整数 target 。
    找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 ，并返回其长度。如果不存在符合条件的子数组，返回 0 
*/
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int sum;
    int subLen;
    int ret = __INT32_MAX__;

    for(int i = 0; i < numsSize; i++)
    {
        sum = 0;
        for(int j = i; j < numsSize; j++)
        {
            sum += nums[j];
            
            if(sum >= target)
            {
                subLen = j - i + 1;
                ret = subLen < ret ? subLen : ret;
                break;
            }
        }
    }

    return ret == __INT32_MAX__ ? 0 : ret;
}

//  滑动窗口解法
int minSubArrayLen2(int target, int* nums, int numsSize)
{
    int sum = 0;
    int subLen;
    int ret = __INT32_MAX__;

    for(int i = 0, j = 0; j < numsSize; j++)
    {
        sum += nums[j];
        
        while(sum >= target)
        {
            subLen = j - i + 1; //  取子序列长度
            ret = subLen < ret ? subLen : ret;  //  取更小

            sum -= nums[i++];   //  滑动窗口，满足条件时起始位置右移
        }
    }

    return ret == __INT32_MAX__ ? 0 : ret;
}

int main()
{
    int nums[] = {2, 3, 1, 2, 4, 3};
    int target = 7;

    printf("%d\n", minSubArrayLen(target, nums, sizeof(nums) / sizeof(nums[0])));
//  -----------------------------------------------------------------------------------
    printf("%d\n", minSubArrayLen2(target, nums, sizeof(nums) / sizeof(nums[0])));

    return 0;
}