#include <stdio.h>
#include <stdlib.h> //提供rand原型

typedef struct NODE
{                      //结构
    int num;           //结构数字
    struct NODE *next; //指向下一个结构的指针
} node;                //typedef更换的结构类型名
int main()
{
    int numb;          //结构内数值
    node *star = NULL; //开始链表指针
    node *last = star;
    while (scanf("%d", &numb) == 1)
    {

        node *p = (node *)malloc(sizeof(node) * 1);
        //创建一个自动分配的内存,确保每个都是单独的
        p->num = numb;  //将输入值赋给结构变量
        p->next = NULL; //将下一个位置初始化为空
        node *temp = last;
        //创建一个结构体变量等于最后一个链表结构
        if (temp)
        {
            temp->next = p; //链表指向下一个

            last = p;//获得最后一个链表位置
        }
        else
        {
            star = p;
            last = star;
        }
    }
    return 0;
}