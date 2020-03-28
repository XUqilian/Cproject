#include<stdio.h>
//this is command  test
int main(int argc,const char *argv[])
{
    for(int i=0;i<argc;i++){
        printf("%-4d",i);//格式化输出美观
        printf("%s\n",argv[i]);
//得出0是文件名及第一个参数
//从1开始是命令行的其他参数
//利用命令行参数来控制程序走向就不解释了
//判断进来的是什么进行什么操作，不正确输入报错就行了
    }
    return 0;
}