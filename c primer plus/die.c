#include <stdio.h>
int main()
{
    int man[30] = {0};
    int t = 0;//以产生人数
    int k = 0;//总人数
    int j = 0;//循环人数

    while (t < 15)
    {

        if (!man[k])
            j++;
        
        if (j == 9)
        {
            man[k] = 1;
            j = 0;
            t++;
        }

        if (k == 30) 
            k = -1;
        k++;
    }

    for (k= 0; k < 30; k++)
    {
        if (man[k])
            printf("%-4d", k);
    }
}