//指定范围内输出素数
#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    int a[num];
    int cnt = 0;

    for (int j = 0; j < num; j++)
        a[j] = 0; //初始化

    for (int i = 2; (i * i) <= num; i++) //循环小于次方根
    {
        if (a[i] == 1)
            continue;                     //减少部分循环
        for (int k = num / i; k > 1; k--) //清理数组非素数
        {
            if (a[k * i]) //记录多余循环数
                cnt++;
            a[k * i] = 1;
        }
    }
    printf("%d\n", cnt);

    for (int c = 2; c < num; c++) //输出
    {
        if (!a[c])
            printf("%4d", c);
    }
    return 0;
}