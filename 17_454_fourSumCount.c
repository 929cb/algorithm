#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    454. 四数相加 II
        给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

        0 <= i, j, k, l < n
        nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

#define TB_LEN    256   //  自造hash，可通过TB_LEN调节内存和效率

typedef struct table_node{
    int val;
    int count;
    struct table_node *next;
} TABLE_NODE;

void my_hash_insert(TABLE_NODE *tb[], int val) {
    if (NULL == tb[abs(val % TB_LEN)]) {
        tb[abs(val % TB_LEN)] = (TABLE_NODE*)malloc(sizeof(TABLE_NODE));
        tb[abs(val % TB_LEN)]->val = val;
        tb[abs(val % TB_LEN)]->count = 1;
        tb[abs(val % TB_LEN)]->next = NULL;
    } else {
        TABLE_NODE *p = tb[abs(val % TB_LEN)];
        if (p->val == val) { p->count++; return; }
        while(p->next) {
            p = p->next;
            if (p->val == val) { p->count++; return; }
        }
        p->next = (TABLE_NODE*)malloc(sizeof(TABLE_NODE));
        p->next->val = val;
        p->next->count = 1;
        p->next->next = NULL;
    }
}

int my_hash_find(TABLE_NODE *tb[], int val) {
    TABLE_NODE *p = tb[abs(val % TB_LEN)];
    while(p) {
        if (p->val == val) { return p->count; }
        p = p->next;
    }
    return 0;
}

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    int i, j;
    int count = 0;
    TABLE_NODE *hash_table[TB_LEN] = {0};

    for (i=0; i<nums1Size; i++) {
        for (j=0; j<nums2Size; j++) {
            my_hash_insert(hash_table, nums1[i] + nums2[j]);
        }
    }
    for (i=0; i<nums3Size; i++) {
        for (j=0; j<nums4Size; j++) {
            count += my_hash_find(hash_table, -(nums3[i] + nums4[j]));
        }
    }
    return count;
}


int main()
{


    return 0;
}