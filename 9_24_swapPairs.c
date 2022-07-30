#include <stdio.h>
#include <stdlib.h>

/*
    24. 两两交换链表中的节点
        给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    //  直接返回NULL或头节点
    if(!head || head->next == NULL)
        return head;

    //  设置多个指针，分别指向当前待交换的前一个、下一次待交换的前一个、虚拟头节点
    struct ListNode *temp1 = NULL, *temp2 = NULL, *cur = NULL;
    struct ListNode* temHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    temHead->next = head;
    cur = temHead;

    while(cur->next && cur->next->next)
    {
        temp1 = cur->next;  //  指向当前待交换组的第一个节点
        temp2 = temp1->next->next;  //  指向下一组待交换的第一个节点

        cur->next = temp1->next;
        cur->next->next = temp1;

        temp1->next = temp2;    //  此时temp1指向的是当前组的第二个，将下一个指向下一组的第一个
        cur = temp1;    //  更新cur
    }

    return temHead->next;
}

int main()
{


    return 0;
}