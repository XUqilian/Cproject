//memory allocation动态分配内存
#include<stdio.h>
#include<stdlib.h>//用于提供malloc原型
int main()
{
    //使用动态内存分配要记住一点，你是借来的内存，要还
    unsigned int n;
    int *i=NULL;
    i=(int*)malloc(n*sizeof(int));//动态分配ｎ个int内存
    i=(int*)calloc(n,sizeof(int));//动态分配ｎ个int内存,并讲其中的元素值全变为０
    realloc(i,n*sizeof(int));//将ｉ里面容纳元素的范围增大到ｎ个
    free(i);//借完就要还
    return 0;
}