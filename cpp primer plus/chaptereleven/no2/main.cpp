#include"head.h"
#include<time.h>  //提供时间参数
#include<stdlib.h>  //引入rand srand 函数进行模拟随机

using std::cout;
using std::endl;

int main()
{
    static int distance;
    static int buchang;
    static int bushu=0;

    srand(time(0)); //利用系统时间做参数提供给伪随机种子函数做种子
    wanderars man;
 
    // scanf("%d",&distance); //获取需要的长度
    // scanf("%d",&buchang); //获取一步长度
    distance=50;
    buchang=30;
    //输入的参数应该有检查才能使用

    while(man.backmag()<distance)
    {
        bushu++;
        man.operator+(wanderars(buchang,rand()%360,wanderars::pol));
        //printf("%d:",bushu);
        cout<<bushu<<":"<<man<<endl;
    }
    printf("after %d times,the man has move more than %d.\n",bushu,distance);
    //printf("(x,y) =(%f,%f)\nor\n(mag,ang)=(%f,%f).\n",man.backx(),man.backy(),man.backmag(),man.backang());
    cout<<man<<"\nor"<<endl;
    man.setmodep();
    cout<<man<<endl;
    printf("ratio of bushu to distance:%f.\n",bushu/double(distance));  //整数除以整数会被截断小数部分

    return 0;
}