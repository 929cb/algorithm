#include <stdio.h>
#include <stdlib.h>

/*
    349. 两个数组的交集
        给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

    Note: The returned array must be malloced, assume caller calls free().
*/

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int nums[1000] = {0}, retIndex = 0;
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* ans = (int*)malloc(sizeof(int) * lessSize);
    if(!ans) exit(1);

    //  先将其中一个数组的值作为下标赋值
    for(int i = 0; i < nums1Size; i++)
        nums[nums1[i]]++;

    //  通过判断之前赋值过的数组元素是否大于0
    for(int i = 0; i < nums2Size; i++)
    {
        if(nums[nums2[i]] > 0)
        {
            ans[retIndex++] = nums2[i];
            //  清零避免重复
            nums[nums2[i]] = 0;
        }
    }

    *returnSize = retIndex;

    return ans;
}

int main()
{


    return 0;
}