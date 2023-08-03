#include "head.h"

int main(void)
{
    Array<int> inter; // 使用默认参数

    for(int i ; i < 5 ; i++)
        inter[i] = i;
    
    for(int i = 5 ; i > 0 ; i--)
        cout << inter[i-1] << "\t";
    cout << endl;

    Array<double ,3> avg; // 自定义参数

    Array< Array<double,4> ,3 > dim; // 嵌套/递归 模板实例
    
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {   
            dim[i][j] = i*j; 
        }
        avg[i] = 0;
    }

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            // cout.width(2);
            cout << dim[i][j] << '\t';
            avg[i] += dim[i][j]; 
        }
        cout << "avg:" << avg[i] << endl;
    }



    Stct<string , int> a;

    Stct<string,int> people[4]{
        Stct<string,int>("jiji",14),
        Stct<string,int>("mimi",15),
        Stct<string,int>("yiyi",16),
        Stct<string,int>("hihi",17)
    };

    int ct = sizeof(people) / sizeof(Stct<string,int>);  // sizeof  Stct<string,int> 才是一个类型

    for(int i = 0; i < ct ; i++)
    {
        a.vala() = people[i].vala();
        a.valb() = people[i].valb();

        cout << i << ": " << a.vala() << "\t" << a.valb() << endl;
        
    }

    return 0;
}