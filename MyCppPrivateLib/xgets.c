#include"xcpp.h"

// int xgets(char *array,int count)  
//从输入流获取一段字符串并存入数组 当遇到换行 字符串结尾或最大获取值时 再结尾加上字符串结束标志 函数返回获取字符数量 包括结束字符
// {
//     count--;
//     int i = 0 ;
//     for(i = 0 ; i < count ; i++)
//     {
//         array[i] = getchar();
//         if(array[i] == '\0'|| array[i] == '\n') 
//         {
//             if(array[i] == '\n') 
//                 array[i] = '\0';
//             i--;
//             break;
//         }
//     }
//     if(i == count) array[i] = '\0';
//     return i+1;
// }

int xgets(char *array, int count)   
//从输入流获取一段字符串并存入数组 当遇到换行 字符串结尾或最大获取值时 再结尾加上字符串结束标志
// 函数返回获取字符数量 不包括结束字符
{
    count--;
    int i = 0;
    for (i = 0; i < count; i++)
    {
        array[i] = getchar();
        if (array[i] == '\0' || array[i] == '\n')
        {
            if (array[i] == '\n')
                array[i] = '\0';
            break;
        }
    }
    if (i == count)
        array[i] = '\0';
    return i;
}

int xclearin()          //清理输入流剩下的字符 遇到换行结束
{
    int t;
    while(t = getchar() && t != '\n');
    return 0;
}