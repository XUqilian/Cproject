#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
– 查找字符串中存在的最大回文子字符串的长度并打印回文字符串。
– 连续有 100 扇门，所有门最初都关闭。一个人多次穿过所有门，并通过以下方式切换（如果打开则关闭;如果关闭则打开）它们：
在第一次行走中，该人切换每扇门。 在第二次行走中，该人每隔一扇门切换一次，即第 2 扇、第 4 扇、第 6 扇、第 8 扇门等。 在第三次步行中，该人每三扇门切换一次，即第 3 扇、第 6 扇、第 9 扇门等。 等等... 在第 100 步中，该人切换第 100 扇门。 到底哪些门是敞开的？
*/

int main(void)
{
    int limit; // 字符串长度

    char str[limit];// string
    // init str

    char * p ,* pl,* pr; // 当前以及前后指针
    int amonst = 0;     //字符串字数
    char * head = NULL;     // 字符串头部位置
    


    for(int i = 0 ; i < limit && amonst < limit - i ; i++)	// 应该有更简单的方法 不从开头读取
    {
        if(str[i] == str[i+1])
        {
            int cnt = 0;
            int l = i ;
            for(int r = i + 1 ; l > -1 && r < limit ; l-- ,r++ )
            {
                cnt++;
                if(str[l] != str[r]) break;
            }
            if(amonst < cnt*2) 
            {
                head = &(str[l]);
                amonst = cnt;
            }
            
        }
        if(str[i] == str[i+2])
        {
            int cnt = 0;
            int l = i ;
            for(int r = i + 1 ; l > -1 && r < limit ; l-- ,r++ )
            {
                cnt++;
                if(str[l] != str[r]) break;
            }
            
            if(amonst < cnt*2+1) 
            {
                head = &(str[l]);
                amonst = cnt;
            }
        }
    }
    printf("%p : %d", head , amonst);

    return 0;
}


int main(void)
{
    bool ar[100]{0};

    for(int person = 2 ; person < 101 ; person++)
    {
        for(int dol = person ; dol < 101; dol += person)
            ar[dol] = ar[dol] == true ? false : true;
    } 
    return 0;
}
