//链表头文件
#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int num;
    struct array *next;
} ay; //定义链表结构并将其类型命名

ay *create(void);          //创建一个新链表空间
ay *give(ay *);            //给一个节点内项赋值
move(ay *, ay *);          //链接一个节点到链表结尾
putdg(ay *);               //递归输出
ay *findb(ay *, int);      //查找当前
ay *finda(ay *, int);      //查找
addb(ay *findb, ay *temp); //添加一个节点
delleat(ay *finda);        //删除某一个节点
fre(ay *star);             //释放整个链表

int main()
{
    int n;
    ay *star = NULL;       //链表开始指针
    ay *temp = NULL;       //新建空间指针
    ay *last = star;       //链表尾部指针
    ay *find = NULL;       //查找指针
    temp = create();       //创建一个新链表
    temp = give(temp);     //获取输入并存入新链表
    move(last, temp);      //链接链表
    put(star);             //输出链表元素
    find = findb(star, n); //查找搜索
    find = finda(star, n); //查找
    addb(findb, temp);     //添加链表到新的地方
    delleat(finda);        //删除链表
    fre(star);             //释放空间
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

put(star)
{
    ay *p = star;
    ;
    for (p; p; p = p->next)
    {
        int count = 1;
        printf("第%d个链表：", count++);
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

ay *findb(ay *star, int n)
{
    ay *f = star;
    while (f->num != n)
    {
        f = f->next;
    }
    return f;
}

ay *finda(ay *star, int n)
{
    ay *f = star;
    while (f->next->num != n)
    {
        f = f->next;
    }
    return f;
}

addb(ay *findb, ay *temp)
{
    //ay* temp=NULL;
    //temp=give( create() );
    if (findb->next)
    {
        ay *t = NULL;
        t = findb->next;
        findb->next = temp;
        temp->next = t;
    }
    else
    {
        sprintf(stderr, "这个节点是尾部节点，如需添加请用move函数。");

        /*联合move函数创建一个新完整的添加函数
        ay*last=findb;
        if (last)
        {
            last->next = temp;
            last = temp;
        }
        else
        {
            last = temp;
        }
        */
    }
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