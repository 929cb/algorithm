#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

//  203.移除链表元素
//  给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。 
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if(head == NULL)
        return NULL;

    struct ListNode* p, *temp = NULL;

    while(head && head->val == val)
        head = head->next;

    if(!head) return NULL;

    temp = head;

    while(temp->next)
    {
        if(temp->next->val == val)
        {
            p = temp->next;
            temp->next = p->next;
            free(p);
            p = NULL;
        }
        else temp = temp->next;

        //if(!temp) break;
    }

    return head;
}

int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!head)
        return 1;
    struct ListNode* p = head;
    //scanf("%d", &(p->val));

    for(int i = 0; i < 4; i++)
    {
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &(p->next->val));
        p = p->next;
    }
    p->next = NULL;
    
    head = removeElements(head->next, 2);

    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }

    return 0;
}