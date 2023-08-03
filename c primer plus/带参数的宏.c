#include<stdio.h>
#define m(i) ((i)*(i)) //将该类似函数定义成
#define n1(i) (i)*12 
#define n2(i) (i*12 )//这两个是为了展示括号
//宏定义里面每个参数必须都带上括号
//要不然结果会运算失误

int main()
{
    printf("%d",m(5));    //结果是25，即((5)*(5))
    printf("%d",n1(5+2)); //结果是84,(5+2)*12
    printf("%d",n2(5+2)); //结果是29，(5+2*12)
    return 0;   
}