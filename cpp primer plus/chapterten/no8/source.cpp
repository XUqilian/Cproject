#include "head.h"

void list::add(int y)
{
    if (!isfull())
    {
        int i = 0;
        while (!(x[i]))
        {
            i++;
        }
        x[i] = y;
    }
} //添加
int list::isfull()
{
    return x[9];
}//满  有数据就是满，删除时清楚数据，没有数据就是空
int list::isempty()
{
    return x[0];
} //空
int list::find(int y)
{
    int i = 0;
    while (x[i] != y)
        i++;
    return i;
} //查  根据内容查
void visit(void (*pf)(int ))
{

}//接受一个外部函数指针来根据函数实现进行操作列表
void list::visit(void (list::*pf)(int )){

} //接受一个外部函数指针来根据函数实现进行操作列表
void visitone(int y){

}
void visittwo(int y){

}