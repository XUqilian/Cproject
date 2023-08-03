#include"except.h"
#include<cmath>

bool test(double a, double b , double & ret)
{
    if(a == -b){
        throw erone();   // 抛出类异常 利用类承载错误  此处用参数初始化类  
        return false;
    }else
    {
        ret = a * b / (a + b);
        return true;
    }
}

bool testt(double a , double b , double & ret)
{
    if(a <0 && b <0 ){
        throw ertwo();   // 抛出类异常 利用类承载错误  此处用参数初始化类  
        return false;
    }else
    {
        ret = sqrt(a*b);
        return true;
    }
}

int main(void)
{
    double a , b , c ;
    cout << " enter two argment run function:" ;

    while(cin >> a >> b )
    {
        try
        {
            test(a,b,c);
            cout << "a , b , c :" << a << b << c << endl;
            testt(a,b,c);
            cout << "a , b , c :" << a << b << c << endl;
        }
        catch(erone & eo)       // 接收抛出的相应类 使类可用
        {
            cout << eo.what() << endl;// cout << s << endl;
            continue;               // 这个continue 服务于 while循环

        }
        catch(ertwo & et)
        {
            cout << et.what() << endl;
            break;              // 这个break 服务于 while循环
        } 
        catch(exception & t)        // 基类可接收所有子类的引用参数 这类似于default  但这个不能放在前面 因为它会匹配所有选项并使其他的没用
        {
            break;
        }
    }

    return 0;
}