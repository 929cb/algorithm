#include <stdio.h>
#include <stdlib.h>

//  给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
//  示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{   
    typedef struct ListNode ListNode;

    ListNode *cur, *pre, *temp;

    pre = NULL;
    cur = head;

    while(cur)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}


//  递归法
struct ListNode* reverse(struct ListNode* pre, struct ListNode* cur)
{
    if(cur == NULL)
        return pre;

    struct ListNode* temp = cur->next;
    cur->next = pre;

    return reverse(cur, temp);
}

struct ListNode* reverseList2(struct ListNode* head)
{
    return reverse(NULL, head);
}

int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!head) return 1;

    struct ListNode* p = head;

    for(int i = 0; i < 5; i++)
    {
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(!(p->next)) return 1;

        scanf("%d", &(p->next->val));

        p = p->next;
    }

    p = reverseList2(head->next);

    while(p)
    {
        printf("%d\t", p->val);
        p = p->next;
    }

    free(head);
    head = NULL;

    return 0;
}