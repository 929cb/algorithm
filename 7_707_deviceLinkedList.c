#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    int val;
    struct LinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(!head) exit(1);

    head->next = NULL;

    return head;    
}

int myLinkedListGet(MyLinkedList* obj, int index) 
{
    MyLinkedList* cur = obj->next;
    for(int i = 0; cur; i++)
    {
        if(i == index)
            return cur->val;
        
        cur = cur->next;
    }

    return -1;  
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(!p) exit(1);

    p->val = val;
    p->next = obj->next;
    obj->next = p;  
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) 
{
    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(!p) exit(1);

    p->val = val;
    while(obj->next)
    {
        obj = obj->next;
    }
    obj->next = p;
    p->next = NULL;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
{
    if(index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if(!p) exit(1);

    p->val = val;

    int i;
    MyLinkedList* cur = obj->next;
    for(i = 1; cur; i++)
    {
        if(i == index)
        {
            p->next = cur->next;
            cur->next = p;
            return;
        }

        cur = cur->next;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
{
    if(index < 0) return;

    // if(index == 0)
    // {
    //     MyLinkedList* p = obj->next;
    //     obj->next = p->next;
    //     free(p);
    //     p = NULL;
    //     return;
    // }


    MyLinkedList* cur = obj;
    
    int i = 0;
    while(cur->next)
    {
        if(i == index)
        {
            MyLinkedList* p = cur->next;
            cur->next = p->next;
            free(p);
            p = NULL;
            return;
        }

        i++;
        cur = cur->next;
    }


    // for(int i = 1; cur && cur->next; i++)
    // {
    //     if(i == index)
    //     {
    //         MyLinkedList* p = cur->next;

    //     }
    // }
}

void myLinkedListFree(MyLinkedList* obj) 
{
    if(obj)
    {
        MyLinkedList* p = obj;
        obj = obj->next;
        free(p);
    }
}


int main()
{


    return 0;
}