#include <stdio.h>
#include <stdlib.h>

/*
    142.环形链表II
        给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

        如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
        为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。
        注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
        不允许修改 链表。
*/

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast, *slow;
    fast = slow = head;

    while(fast && fast->next)   //  快指针需要移动两步，所以还需要判断快指针的下一步也不为空
    {
        //  快慢指针相交时，证明有环
        fast = fast->next->next;
        slow = slow->next;
        
        //  有环
        if(fast == slow)
        {
            //  将一个指针指向头指针
            fast = head;

            //  此时两个指针同步走到相交时，就是入环的第一个节点
            while(fast != slow)
                fast = fast->next, slow = slow->next;

            return fast;
        }
    }

    return NULL;
}

int main()
{


    return 0;
}