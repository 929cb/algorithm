#include <stdio.h>

/*
    242. 有效的字母异位词

        给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
        注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/

//  哈希大法：将s自字符串的每个字母存到数组对应位置+1，再通过t字符串的每个字母找到数组对应位置-1，最后判断数组是否还是和初始化时一样
int isAnagram(char* s, char* t)
{
    char record[26] = {0};

    while(*s != '\0')
    {
        record[*s - 97]++;
        s++;
    }

    while(*t != '\0')
    {
        record[*t - 97]--;
        t++;
    }

    for(int i = 0; i < 26; i++)
        if(record[i] != 0)
            return 0;

    return 1;
}

int main()
{


    return 0;
}