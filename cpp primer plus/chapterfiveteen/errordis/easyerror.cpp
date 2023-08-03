#include<iostream>

using std::cout;
using std::cin;
using std::endl;

bool test(double a, double b , double & ret)
{
    if(a == -b){
        throw "the argment have a = -b is invailed.";   // 抛出字符串异常  // 如果没有接收异常的语句 win平台会调用 abort() 中断主程序
        return false;
    }else
    {
        ret = a * b / (a + b);
        return true;
    }
}

int main(void)
{
    double a , b , c ;
    cout << " enter two argment run function:" ;
    // while(cin >> a >> b )
    // {
    //     if(test(a,b,c)) cout << "a , b , c :" << a << b << c << endl;
    //     else abort();       // abort()函数会直接结束主程序
    // }

    while(cin >> a >> b )
    {
        try
        {
            test(a,b,c);
            cout << "a , b , c :" << a << b << c << endl;
        }
        catch(const char *s)        // 捕获抛出的异常 如异常与参数一致进入块 对异常进行处理
        {
            cout << s << endl;
            continue;               // 重新执行异常函数代码
            // break;                  // 调用 abort() 函数中断主函数
        }  
    }

    return 0;
}