#ifndef HEAD_H
#define HEAD_H


class list{
    private:

    int x[10];  //解决类参数变动类型，可以是针对浮点，字符，数组等等，

    public:
    list();
    void add(int);//添加
    int isfull();//满  有数据就是满，删除时清楚数据，没有数据就是空
    int isempty();//空
    int find(int);//查  根据内容查
    void visit(void (*pf)(int ));//接受一个外部函数指针来根据函数实现进行操作列表
    
    void visit(void (list::*pf)(int ));//接受一个类内函数指针来根据函数实现进行操作列表

};
void visitone(int);
void visittwo(int);
#endif