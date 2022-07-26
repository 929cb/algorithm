#include <stdio.h>

/*      27. 移除元素
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

int removeElement(int *nums, int numsSize, int val)
{   
    for (int i = 0; i < numsSize; )
    {
        if (nums[i] != val)
        {
            //  需要移除的数相邻出现时，需要在同一个位置判断两次。这里以条件不满足时才移动指针
            i++;    
            continue;
        }

        for (int j = i + 1; j < numsSize; j++)
        {
            nums[j - 1] = nums[j];
        }

        numsSize--;
    }

    return numsSize;
}

//  双指针法
//      快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
//      慢指针：指向更新为新数组下标的位置
int remove2(int* nums, int numsSize, int val)
{
    int fastIndex = 0, slowIndex = 0;

    for(; fastIndex < numsSize; fastIndex++)
    {
        if(nums[fastIndex] != val)
        {
            nums[slowIndex++] = nums[fastIndex];
        }
    }

    return slowIndex;
}

int main()
{
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    int ret;
    ret = removeElement(nums, sizeof(nums) / sizeof(nums[0]), val);

    printf("%d\n", ret);

    for (int i = 0; i < ret; i++)
        printf("%d ", nums[i]);
//  -------------------------------------------------------------------
    ret = remove2(nums, sizeof(nums) / sizeof(nums[0]), val);

    printf("\n\n%d\n", ret);

    for (int i = 0; i < ret; i++)
        printf("%d ", nums[i]);

    return 0;
}