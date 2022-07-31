#include <stdio.h>
#include <stdlib.h>

/*
    19. 删除链表的倒数第 N 个结点
        给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

struct ListNode
{
    int val;
    struct ListNode* next;
};  

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *fast, *slow;
    struct ListNode* temHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!temHead) exit(1);

    temHead->next = head;
    fast = slow = temHead;

    n++;    //  让快指针先走n+1步，然后快慢指针同时走、当快指针指向空时、慢指针就指向了待删除节点的前一个
    for(; fast; fast = fast->next)
    {
        if(n-- <= 0)
        {
            slow = slow->next;
        }
    }
    slow->next = slow->next->next;

    head = temHead->next;
    free(temHead);

    return head;
}

int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode *p = head;

    for(int i = 2; i <= 5; i++)
    {
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val = i;
        p = p->next;
    }
    p->next = NULL;

    p = removeNthFromEnd(head, 2);

    while(p)
    {
        printf("%d ", p->val);
        p = p->next;
    }

    return 0;
}