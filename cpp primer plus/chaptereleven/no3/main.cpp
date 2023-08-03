#include "head.h"
#include <time.h>   //提供时间参数
#include <stdlib.h> //引入rand srand 函数进行模拟随机

using std::cout;
using std::endl;

int main()
{
    static int distance;
    static int buchang;
    static int bushu = 0;

    srand(time(0)); //利用系统时间做参数提供给伪随机种子函数做种子
    wanderars man;

    // scanf("%d",&distance); //获取需要的长度
    // scanf("%d",&buchang); //获取一步长度
    distance = 50;
    buchang = 30;
    //输入的参数应该有检查才能使用
    int n = 10, min = 0, max = 0, average = 0;
    // scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
	man.reset(0,0);
	bushu=0;
	while (man.backmag() < distance)
        {
            bushu++;
            man.operator+(wanderars(buchang, rand() % 360, wanderars::pol));
            // man+=(wanderars(buchang,rand()%360,wanderars::pol));  //这里需要重载=号才能使用
            // printf("%d:",bushu);
            cout << bushu << ":" << man << endl;
        }
        average += bushu;
        if (bushu > max)
            max = bushu;
        if (0 == i)
        {
            min = bushu;
        }
        else if (min > bushu)
        {
            min = bushu;
        }
    }
    printf("the %d times,min is %d,max is %d,average is %f.",n,min,max,(double)average/n);
    return 0;
}
