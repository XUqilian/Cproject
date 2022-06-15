#include "head.h"

int main()
{
    golf aryg[5];
    char str[40];
    int temp;

    for (int i = 4; i; i--)
    {
        fgets(str,40,stdin);
        //这个版本的c++还是什么已经不支持gets()函数了  给我整麻了 淦  最后换fgets
 
        if (str[1] != '\0')
        {
            scanf("%d", temp);
            aryg[i].setgolf(str, temp);
        }
        else
            break;
    }
    return 0;
}
