#include <stdio.h>
#include <stdlib.h>

void quickSort(int* arr, int low, int high)
{
    if(low >= high) return; //  -3, 2, 3, 11, -7

    int i = low, j = high;
    int pivotVal = arr[low];

    while(i < j)
    {
        while(i < j && arr[j] > pivotVal)
            j--;

        if(i < j) arr[i++] = arr[j];

        while(i < j && arr[i] < pivotVal)
            i++;

        if(i < j) arr[j--] = arr[i];
    }

    arr[i] = pivotVal;

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int* sortedSquares(int* nums, int numsSzie, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * numsSzie);
    if(!ans) exit(1);

    *returnSize = numsSzie;

    for(int i = 0; i < numsSzie; i++)
    {
        ans[i] = nums[i] * nums[i];
    }

    quickSort(ans, 0, numsSzie - 1);

    return ans;
}


int* sortedSquares2(int* nums, int numsSize, int* returnSize)
{
    int i = 0, j = numsSize - 1;
    int k = j;

    *returnSize = numsSize;

    int* ans = (int*)calloc(numsSize, sizeof(int));
    if(!ans) exit(1);

    while(i <= j)
    {
        if(nums[i] * nums[i] >= nums[j] * nums[j])
        {
            ans[k--] = nums[i] * nums[i];
            i++;
        }
        else
        {
            ans[k--] = nums[j] * nums[j];
            j--;
        }
    }

    return ans;
}


int main()
{
    int nums2[] = {-4, -1, 0, 3, 10};
    int nums[] = {-7, -3, 2, 3, 11};
     int returnSize;
    int* ans = NULL;

    ans = sortedSquares(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n\n");

    free(ans);
    ans = NULL; 
//  ----------------------------------------------------------------------------
    ans = sortedSquares2(nums2, sizeof(nums2) / sizeof(nums2[0]), &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }

    free(ans);
    ans = NULL; 

    return 0;
}