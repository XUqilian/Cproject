//位操作练习
#include<stdio.h>

int num(int);//接受int返回打开位数
int figures(int,int);//int参数向左旋转指定位
int move(int,int);//给定指定数和指定位查看是否打开

int main()
{
    return 0;
}

int num(i){
    int cnt=0;
    while(i){
        if(i&1)cnt++;
        i>>=1;//这里其实向左更好，避免负数i&128
    }
    return cnt;
}

int figures(int i,int j){
    //也可以间接用-1：11111111来运算
    int t=8-j;//获取另一边，如果不是256以内就不要用8了
    int kleft;
    kleft=i<<t;//将i后面的位移动指定个到前面了
    i>>=j;//将i向后移动指定个
    i=kleft&i;//想与也不怕负数左加的是1了
    return i;
}

int move(int i,int j){
    int k=1;//0001
    k<<=j;//移动到指定位
    return i&k;//想与得出结果
}