#include <stdio.h>
#include <stdlib.h>

/*
    面试题 02.07. 链表相交
        给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
        题目数据 保证 整个链式结构中不存在环。

        注意，函数返回结果后，链表必须 保持其原始结构 。
*/

struct ListNode
{
    int val;
    struct ListNode* next;
};

//  通过对齐长度来求交点
struct ListNode* getInterSectionNode(struct ListNode* headA, struct ListNode* headB)
{
    typedef struct ListNode ListNode;

    ListNode *curA = headA, *curB = headB;
    int lenA = 0, lenB = 0;

    while(curA) //  求链表A的长度
    {
        lenA++;
        curA = curA->next;
    }
    while(curB) //  求链表B的长度
    {
        lenB++;
        curB = curB->next;
    }

    curA = headA, curB = headB;

    int gap = lenA - lenB;  //  求两条链表长度的差，再对齐
    if(lenA > lenB)
    {
        while(gap--)
            curA = curA->next;
    }
    else if(lenA < lenB)
    {
        while(gap++ != 0)
            curB = curB->next;
    }

    while(curA) //  求交点
    {
        if(curA == curB)
            return curA;
        
        curA = curA->next;
        curB = curB->next;
    }

    return NULL;


//  ----------------------------------------------------------------

    //  方法2：
    struct ListNode *h1 = headA, *h2 = headB;

    while (h1 != h2) {
        //  两条链表交替遍历,弥补两条链表的长度差
        h1 = h1 == NULL ? headB : h1->next;
        h2 = h2 == NULL ? headA : h2->next;
    }

    return h1; 
}

int main()
{


    return 0;
}