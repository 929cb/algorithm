#include <stdio.h>
#include <stdlib.h>

/*
    1 - 2 - 3
*           |    
    8 - 9   4
    |       |
    7 - 6 - 5
*/
//  给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    int x = 0, y = 0, i, j; //  坐标位置
    int mid = n / 2;    //  当n为奇数，需要填充中心点
    int loop = n / 2;   //  循化圈数，每过一圈边长减2
    int offset = 1; //  偏移量，随当前第几圈而改变
    int count = 1;

     //初始化返回的结果数组的大小
    // *returnSize = n;
    // *returnColumnSizes = (int*)malloc(sizeof(int) * n);

    int** ans = (int**)calloc(n, sizeof(int*));
    if(!ans) exit(1);
    for(i = 0; i < n; i++)
    {
        ans[i] = (int*)calloc(n, sizeof(int));
        //  数组的大小作为 *returnColumnSize 数组返回。
        // (*returnColumnSizes)[i] = n;
    }

    while(loop--)
    {
        i = x;
        j = y;

        //  上侧（左->右）
        for(; j < n - offset; j++)
            ans[x][j] = count++;
        //  右侧（上->下）
        for(; i < n - offset; i++)
            ans[i][j] = count++;
        //  下侧（右->左）
        for(; j > y; j--)
            ans[i][j] = count++;
        //  左侧（下->上）
        for(; i > x; i--)
            ans[i][j] = count++;

        offset++;
        x++;
        y++;
    }

    if(n % 2)
        ans[mid][mid] = count;
    
    return ans;
}


int main()
{
    int** ans = generateMatrix(5, NULL, NULL);

    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", ans[i][j]);
        }
        printf("\n");        
    }

    free(ans);

    return 0;
}