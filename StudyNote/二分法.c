//二分法查找已排序数组
#include<stdio.h>

int *num(int p[],int n,int k)//分别是已排序数组，数组大小，待查找值
{
    int *i=NULL;
    n=n/2;
    if(n==0) {
        printf("数组无该数");
        exit();
    }
    if(p[n]>k)i=num(p,n+1,k);
    else if(p[n]<k)i=num(&p[n],n,k);
    else if(p[n]==k) i=&p[n];
    return i;
}
