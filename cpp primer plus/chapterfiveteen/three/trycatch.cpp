#include"trycatch.h"

#include<cmath>

bool test(double a, double b , double & ret)
{
    if(a == -b){
        throw erone(a , b);   // 抛出类异常 利用类承载错误  此处用参数初始化类  
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
        throw ertwo(a , b);   // 抛出类异常 利用类承载错误  此处用参数初始化类  
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
        catch(errf & le)       // 接收抛出的相应类 使类可用
        {
            // if(typeid(erone) == typeid(le))
            //     le.dis();// cout << s << endl;
            // else if(typeid(ertwo) == typeid(le))
            //     le.dis();// cout << s << endl;


            if(erone * eo = dynamic_cast<erone *>(&le))
                eo->dis();// cout << s << endl;
            else if(ertwo * et = dynamic_cast<ertwo *>(&le))
                et->dis();// cout << s << endl;
            break;
        }
        cout << " enter two argment run function:" ;
    }

    return 0;
}