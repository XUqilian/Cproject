//伪随机
#include <stdio.h>
#include <stdio.h>
#include <time.h>   //提供time原型
#include <stdlib.h> //提供rand原型

int main()
{
    int i;
    srand((unsigned int)time(0)); //初始化种子，将种子设置为当前系统时间
    for (int n = 0; n< 10; n++)
    {
        i = rand() % 10; //获得以时间为种子的伪随机数，并将其模１０得到１０以内的数
        printf("%d　%d\n",n, i);
    }
    return 0;
}