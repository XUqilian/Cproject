#include"trycatch.h"
#include<cmath>

bool test(double a, double b , double & ret)
{
    if(a == -b){
        throw erone(a,b);   // 抛出类异常 利用类承载错误  此处用参数初始化类  
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
        throw ertwo(a,b);   // 抛出类异常 利用类承载错误  此处用参数初始化类  
        return false;
    }else
    {
        ret = sqrt(a*b);
        return true;
    }
}

void ttestt(double a,double b ,double c)
{               // throw会根据调用顺序逐渐向上级函数查找try块 当达到主函数还未发现相应块时 就会调用abort函数中断函数
    try{        
        test(a,b, c);
        cout << "a , b , c :" << a << b << c << endl;
        testt(a,b,c);
        cout << "a , b , c :" << a << b << c << endl;
    }
    catch(erone & eo)   // 本级会拦下已出现并符合参数的异常 不符合的将继续向上一级寻找合适的处理
    {
        eo.edis();
        throw;      // 异常在本级处理完后继续向上一级抛出 如没有上一级块将会调用abort函数中断主函数执行
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
            ttestt(a, b, c);
        }
        catch(erone & eo)       // 接收抛出的相应类 使类可用
        {
            eo.edis();// cout << s << endl;
            continue;
        }
        catch(ertwo & et)
        {
            cout << et.edis() << endl;
            break;
        } 
    }

    return 0;
}