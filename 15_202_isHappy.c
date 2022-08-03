#include <stdio.h>

/*
    202. 快乐数
        编写一个算法来判断一个数 n 是不是快乐数。

        「快乐数」 定义为：

            对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
            然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
            如果这个过程 结果为 1，那么这个数就是快乐数。

        如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/

int calculateSum(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}


/*
    1、肯定会产生环。(对于非负int型数 0 ~ 2147483647)， 各位数的平方和最大的是 bitSquare（1999999999） 为 9^2 * 9 + 1=730, 20多亿个数的bitSquare会散落在 0 ~ 730之间， 也就是最多730步内会出现环路)；
    2、基于1的结论，快慢指针肯定会相遇（基于同一个出发点，慢指针走一圈，快指针走两圈则相遇； 基于环中不同的出发点，相遇的会更快）；
    3、相遇的点肯定在环中。
    4、相遇点只要不是1， 肯定不是快乐数（如果形成的环中有任一值为1， 则后续的平方和均为1，形成的环也是1的环；相遇点只要不为1， 说明环中的值都不为1， 也就不可能是快乐数）。

*/
int isHappy(int n)
{
    int fast, slow;
    fast = slow = n;

    do  //  当快指针走完两圈、慢指针走完一圈时，它们就会重逢（1不管计算多少次还是1）
    {
        fast = calculateSum(fast);
        fast = calculateSum(fast);
        slow = calculateSum(slow);
    } while (fast != slow);
    

    return fast == 1;
}

int main()
{
    int n = 19;

    printf("%d%sHappy Digit!", n, isHappy(n) == 1 ? " is " : " is not ");

    return 0;
}