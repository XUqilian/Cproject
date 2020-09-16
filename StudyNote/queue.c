//队列头文件
#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int num;
    struct array *next;
} ay; //定义队列结构并将其类型命名

typedef struct Queue
{
    int num;
    ay *star;
    ay *end;
} queue; //存放队列个数及队列首尾

void grant(queue *); //对队列项进行固定
ay *create(void);    //创建一个新队列空间
ay *give(ay *);      //给一个节点内项赋值
move(ay *, ay *);    //链接一个节点到队列结尾
put(ay *);           //输出
putdg(ay *);         //递归输出
ay *find(ay *, int); //查找当前
delleat(ay *finda);  //删除某一个节点
fre(ay *star);       //释放整个队列

int main()
{
    int n;
    queue *start;                 //队列元素
    grant(start);                 //限制队列长度
    ay *temp = NULL;              //新建空间指针
    ay *finda = NULL;             //查找指针
    temp = create();              //创建一个新队列
    temp = give(temp);            //获取输入并存入新队列
    move(start->end, temp);       //链接队列
    put(start->star);             //输出队列元素
    finda = find(start->star, n); //查找搜索
    delleat(finda);               //删除队列
    fre(start->star);             //释放空间
    return 0;
}

void grant(queue *start)
{
    printf("你需要队列长度最长为：");
    scanf("%d", start->num);
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

move(ay *last, ay *temp)
{

    if (last)
    {
        last->next = temp;
        last = temp;
    }
    else
    {
        last = temp;
    }
}

put(ay *star)
{
    ay *p = star;

    for (p; p; p = p->next)
    {
        int count = 1;
        printf("第%d个队列：", count++);
        printf("%d", p->num);
    }
    //putdg(p);
}

putdg(ay *p)
{
    if (p->next)
    {
        p = p->next;
        putdg(p);
    }
    printf("%d", p->num);
}

ay *find(ay *star, int n)
{
    ay *f = star;
    while (f->num != n)
    {
        f = f->next;
    }
    return f;
}

delleat(ay *finda)
{
    ay *t = NULL;
    t = finda->next->next;
    free(finda->next);
    finda->next = t;
}

fre(ay *star)
{
    ay *t = NULL;
    while (star->next)
    {
        ay *t = star;
        star = star->next;
        free(t);
    }
    free(star);
}