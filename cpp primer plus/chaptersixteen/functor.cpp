#include<iostream>
#include<string>
#include<memory>
#include<list>
#include<algorithm>
#include<iterator>
#include<functional>
#include<vector>

// 函数对象(函数符/仿函数)  就是类内重载了() 使类无需 . 调用成员函数  形似普通函数

using namespace std;

// typedef void (*pfun)(int);  //这里是将pfun定义为一个类型 这个类型接受函数指针 但函数必须是返回值void 接受一个int参数

// 生成器 一元函数  二元函数
// 谓词 二元谓词
template<class T>
class tobig
{
    private:
        T n;
    public:
        tobig(T t) : n(t){}

        bool operator()(T & t){return t > n; }
};

// template<class T ,const double * n = 0>  // 还可以把第一个模板参数设置为函数指针 可以对多参数函数进行转换  后文模板产生了无法匹配参数问题
// T funx( T & t)                           // 函数指针也可以放到这一行的函数参数上 但并不好感觉
// {
//     return t * (*n);
// }

template<class T>
void outpt(T & t)
{
    cout << t << '\t' ;
}
// void outint(int & t){cout << t << ' ';}
// void outdb(double & t){cout << t << ' ';}

int main(void)
{
    {
        tobig<int> t1(100);
        int ar1[]{50 ,100,90,180,60,210,415,88,188,201};
        list<int> ls1(ar1,ar1+10);
        list<int> ls2(ar1,ar1+10);
        cout << "ls1: ";
        // for_each(ls1.begin(),ls1.end(),ostream_iterator<int,char>(cout , " "));  // for_each第三参数类型为函数或者伪函数 类重载()后 类对象名就是伪函数
        for_each(ls1.begin(),ls1.end(),outpt<int>);     // 模板不是会根据传入类型自动生成实例化吗
        cout << "\nls2: ";
        for_each(ls2.begin(),ls2.end(),outpt<int>);
        cout << endl;
        ls1.remove_if(t1);
        ls2.remove_if(tobig<int>(200));
        cout << "ls1: ";
        for_each(ls1.begin(),ls1.end(),outpt<int>);
        cout << "\nls2: ";
        for_each(ls2.begin(),ls2.end(),outpt<int>);
        cout << endl;
    }
    {
        double ar1[]{50 ,100,90,180,60,210,415,88,188,201};
        double ar2[]{150 ,130,190,280,160,212,115,188,81,101}; 

        vector<double> va1(ar1,ar1+10);
        vector<double> va2(ar2,ar2+10);

        cout << "va1: ";
        for_each(va1.begin(),va1.end(),outpt<double>);
        cout << "\nva2: ";
        for_each(va2.begin(),va2.end(),outpt<double>);
        cout << endl;

        vector<double> va3(10);
        vector<double> va4(10);

        transform(va1.begin(),va1.end(),va2.begin(),va3.begin(),plus<double>());
        // transform(va1.begin(),va1.end(),va2.begin(),va4.begin(),funx<double,&(2.5)>());     // funx模板函数 在这解决不了参数匹配问题
        transform(va1.begin(),va1.end(),va4.begin(),bind1st(multiplies<double>(),2.5));

        cout << "\nva3: ";
        for_each(va3.begin(),va3.end(),outpt<double>);
        cout << "\nva4: ";
        for_each(va2.begin(),va2.end(),outpt<double>);
        cout << endl;
    }
    return 0;
}

