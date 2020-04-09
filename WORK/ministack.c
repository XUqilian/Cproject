//栈头文件
//栈需要压栈和弹栈,后入后出
#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int num;
    struct array *next;
} ay; //定义栈结构并将其类型命名

ay *create(void);      //创建一个新栈空间
ay *give(ay *);        //给一个节点内项赋值
void move(ay *, ay *); //压栈
delleat(ay *finda);    //弹栈
fre(ay *last);         //释放整个栈

int main()
{
    int n;
    ay *temp = NULL;   //新建空间指针
    ay *last = NULL;   //栈顶指针
    temp = create();   //创建一个新栈
    temp = give(temp); //获取输入并存入新栈
    move(last, temp);  //压栈
    delleat(last);     //弹栈
    fre(last);         //释放空间
    return 0;
}

ay *create(void)
{
    int bol = 0;
    ay *temp = NULL;
    do
    {
        temp = (ay *)malloc(sizeof(ay));
        bol++;
    } while (temp == NULL);

    if (bol > 5)
    {
        sprintf(stderr, "分配内存未成功");
        exit(EXIT_FAILURE);
    }

    temp->next = NULL;
    return temp;
}

ay *give(ay *temp)
{
    int n;
    scanf("%d", &n);
    temp->num = n;
    while (getchar() != '\n')
    {
        continue;
    }

    return temp;
}

void move(ay *last, ay *temp)
{
    if (last)
    {
        temp->next = last;
        last = temp;
    }
    else
        last = temp;
}

delleat(ay *last)
{
    ay *t = NULL;
    t = last->next;
    free(last);
    last = t;
}

fre(ay *last)
{
    ay *t = NULL;
    while (last->next)
    {
        ay *t = last;
        last = last->next;
        free(t);
    }
    free(last);
}