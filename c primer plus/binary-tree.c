//二叉树
//这里面有好多我犯错的地方，希望引以为戒
#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int num;
    struct array *up;
    struct array *next;
} ay; //树的结构
typedef struct TREE
{
    int num;
    ay *star;
} Tree; //存放队列个数及队列首尾//数的节点量和顶部位置

ay *create(void);                //创建树
ay *give(ay *temp);              //节点赋值
ay *find(Tree *start, int n);    //查找树
void put(Tree *start);           //遍历树bac
void add(Tree *start, ay *temp); //添加节点(所有位置添加)
//删除节点
void alldelleat(Tree *start); //清空树

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

    temp->up = NULL;
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

ay *find(Tree *start, int n)
{
    ay *t = start->star;
    ay *result = NULL;
    if (t->num == n)
        result = t;
    else if ((t->num) > n)
        result = find(t->up, n);
    else if ((t->num) < n)
        result = find(t->next, n);
    return result;
}

void put(Tree *start)
{

    ay *t = start->star;
    if (t->up)
        put(t->up);
    printf("%4d", t->num);
    if (t->next)
        put(t->next);
}

void add(Tree *start, ay *temp)
{
    ay *t = start->star;
    ay *p = t;
    /*
    if(p->num==temp->num){
        printf("树中已有改值");
        return;
    }else if(p->num>temp->num){
        if(p->up==NULL){
            p->up=temp;
                return;
        }else add(p->up,temp);
    }
    else if(p->num<temp->num){
        if(p->up==NULL){
            p->up=temp;
                return;
        }else add(p->next,temp);
    } 
    */
    while (p)
    {
        if (p->num == temp->num)
        {
            printf("树中已有改值");
            return;
        }
        else if (p->num > temp->num)
            p = p->up;
        else if (p->num < temp->num)
            p = p->next;
    } //这里我陷入过一次矛盾，父为10，左子7，定值为8，该放哪。后来想起左子的右树可以大于左子的
    p = temp;
}

void delleat(Tree *start, ay *temp)
{
    ay *t = NULL; //临时
    ay *d = NULL; //删除的节点后的新顶点

    //将删除节点后项目链接到以d为根的树下
    if (temp->up && temp->next) //如果节点有左右子
    {
        d = temp->up;
        ay *r = temp->next; //右节点
        t = d;              //临时
        while (t->next)     //如果该节点有右子
        {
            t = t->next; //节点指向右子
        }
        t->next = r; //原顶点右子链接至该位置
    }
    else if (temp->up) //如果没有右子
    {
        ay *d = temp->up;
    }
    else if (temp->next) //如果没有左子
    {
        ay *d = temp->next;
    }

    //获取删除节点前一个位置指针
    ay *a = start->star;
    t = a;
    int i = 0;     //判断在左子下还是在右子下
    ay *t1 = NULL; //t的上一个节点
    while (t != temp)
    {
        t1 = t;
        if (t->num > temp->num)
        {
            t = t->up;
            i = 1;
        }
        else
        {
            t = t->next;
            i = 2;
        }
    }

    //将删除后的根树与主树链接
    if (t1) //如果该节点不是根节点
    {
        if (i == 1)
            t1->up = d;
        if (i == 2)
            t1->next = d;
    }
    else //该节点是根节点
    {
        start->star = d;
    }

    //释放删除节点空间
    free(temp);
}

void alldelleat(Tree *start)
{
    ay *t = start->star;
    ay *a = t;
    ay *q = t->up;
    ay *p = t->next;
    free(a);
    alldelleat(q);
    alldelleat(p);
}

//下面是我走的错路，吸取经验，动动手在纸上打打草稿挺不错的
/*    if(temp==p){
        if(p->up)//如果节点有左子
        {
            start=p->up;//将顶点移至节点左子
            q=start;
            while(q->next)//如果该节点有右子
            {
                q=q->next;//节点指向右子
            }
            q->next=p->next;//原顶点右子链接至该位置
        }
        else start=p->next;//顶点没有左子，顶点直接移至右子
    }else while(temp!=p){
        if(temp->num>p->num) p=p->next;
        else if(temp->num<p->num) p=p->up;
    }

    
    if(start->num==0) {
        printf("这是一个空树");
        return;
    }
/*
    if(p->num==temp->num){
         if(p->up)//如果节点有左子
        {
            start=p->up;//将顶点移至节点左子
            q=start;
            while(q->next)//如果该节点有右子
            {
                q=q->next;//节点指向右子
            }
            q->next=p->next;//原顶点右子链接至该位置
        }
        else start=p->next;//顶点没有左子，顶点直接移至右子
        free(p);
    }
    


}
/*    if(star->num==temp->num){
        if(star->up)//如果节点有左子
        {
            star=star->up;//将顶点移至节点左子
            q=star;
            while(q->next)//如果该节点有右子
            {
                q=q->next;//节点指向右子
            }
            q->next=p->next;//原顶点右子链接至该位置
        }
        else star=star->next;//顶点没有左子，顶点直接移至右子
    }
/*
    if(p->num==temp->num){
        de(star,p);
    }
    else if((star->num)>n) result=find(star->up,n);
    else if((star->num)<n) result=find(star->next,n);
    return result;
}
de(ay*star,ay*p){
    ay*q=p;
    if(p->up&&p->next){
        q=p->up;
        while(q->next)q=q->next;
        q->next=p->next;
        star=p->up;
    }else if(p->up){
        star=p->up;
    }else if(p->next) star=p->next;
}*/