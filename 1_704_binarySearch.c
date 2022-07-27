#include <stdio.h>

/*      704. 二分查找
    给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/

int BinSearch(int const *nums, int nums_len, int target)
{
    int left, right, mid;

    left = 0;
    right = nums_len - 1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(target > nums[mid])
            left = mid + 1;
        else if(target < nums[mid])
            right = mid - 1;
        else
            return mid;
    }

    return -1;
}

int RecursionBS(const int* nums, int left, int right, int target)
{
    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(nums[mid] == target)
        return mid;
    else if(nums[mid] > target)
        RecursionBS(nums, left, mid - 1, target);
    else
        RecursionBS(nums, mid + 1, right, target);
}

int main()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int target = 12;

    int ret;
    if((ret = BinSearch(nums, sizeof(nums) / sizeof(nums[0]), target)) == -1)    
        printf("Not Found\n");
    else
        printf("%d\n", ret);
//  -----------------------------------------------------------------------------
    if((ret = RecursionBS(nums, 0, sizeof(nums) / sizeof(int), target)) == -1)    
        printf("Not Found\n");
    else
        printf("%d\n", ret);
 
    return 0;
}
