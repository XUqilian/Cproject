#include"trycatch.h"
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
    if(a <=0 || b <=0 ){
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
            cout << "a , b , c :" << a << "\t" << b << "\t" << c << endl;
            testt(a,b,c);
            cout << "a , b , c :" << a << "\t" << b << "\t" << c << endl;
        }
        catch(erone & eo)       // 接收抛出的相应类 使类可用
        {
            cout << " in catch 1" << endl;
            cout << eo.what() << endl;;// cout << s << endl;
            continue;

        }
        catch(ertwo & et)
        {
            cout << " in catch 2" << endl;
            cout << et.what() << endl;
            break;
        } 
        cout << " enter two argment run function:" ;
    }

    return 0;
}