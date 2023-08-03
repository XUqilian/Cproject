#include<iostream>

using std::cout;
using std::endl;

template<class T>
void d();
template<class T>
void dd(T &);

template<class T>
class A
{
    private:
        T temp;
        static int count;
    public:
        A(T t):temp(t){count++;}
        // A(T& t):temp(t){count++;} // have  T = T&. i dont know why not do it
        // i just want run quickly
        // A(const T t):temp(t){count++;}

        void a();
        void aa()const;
        // void aaa(int );
        // void aaaa(int );     

        friend void b();
        // friend void b()const; //友元函数可以被const限定吗? 不可以吧 为什么不报错
        
        friend void c(A<T> &);  // can use this. because it isnt template. cant use T
        // friend void c(A<int> &);  // can do it
        // friend void c(A<double> &);  

        // 约束模板友元函数  在类前声明模板 类中根据类模板参数的类型进行具体化'声明' 类外进行具体化
        
        /* friend void d<A>(); error
        // compile error:
        // .\text.cpp: In instantiation of 'void d() [with T = int]':
        // .\text.cpp:119:12:   required from here
        // .\text.cpp:84:10: error: 'int A<int>::count' is private within this context
        //     cout << A<T>::count << endl;
        //     ~~~~~^~~~~~~
        // .\text.cpp:57:5: note: declared private here
        // int A<T>::count = 0;
        //     ^~~~
        // .\text.cpp: In instantiation of 'void d() [with T = double]':
        // .\text.cpp:120:15:   required from here
        // .\text.cpp:84:10: error: 'int A<double>::count' is private within this context
        //     cout << A<T>::count << endl;
        //     ~~~~~^~~~~~~
        // .\text.cpp:57:5: note: declared private here
        // int A<T>::count = 0;
        //     ^~~~                                 */


        friend void d<T>();     // 声明模板函数使用的类型为 T  据此进行对应的函数具体化声明
        // friend void dd<A>(A<T> &);  显示在<>中声明使用的类型 进行具体化声明
        friend void dd<>(A<T> &);  // 也可以不显示使用 因为函数接受的参数指定了会使用的类型 
        // <> 指出这是在进行模板具体化 

        // 非约束模板友元函数  在类内创建函数模板 类外实现具体化代码
        // template<class T>  不能使用T 会使函数不明白使用A类的T还是e函数的T
        template<class U>
        friend void e();

        template<class U>
        friend void ee(U &);


};

// 模板类内成员静态变量初始化
template<class T>
int A<T>::count = 0;

// 模板类普通函数定义
template<class T>  //模板类限定 确定是哪种模板类
void A<T>::a()      // 模板类确定  确定是哪种模板类中的哪一个模板类
{

}

template<class T>
void A<T>::aa()const
{
    
}


// 模板类普通带参数友元函数
// 初始化方式相同

// 模板类 非模板友元
void b()            // 友元函数并不属于类函数 所以不添加类限定
{
    cout << A<int>::count << endl; // 友元函数必须有实例化的对象才能使用 
                                    // 这里是针对所有A<int>对象 都适用
    cout << A<double>::count << endl; // 针对所有A<double>对象 都可以适用
    // ......
    // 本函数只能对该类模板 创建的 int double 进行操作 如要其他类型需添加
}
// void b(){}  
// 不能创建该函数的重载版本 因为该函数在重载时是没有其他调用参考的 会与上面函数产生二义

// 模板类 非模板带参数友元函数
void c(A<int> & t)      // 非模板函数只能传递实例化对象作为参数
{
    cout << "temp:" << t.temp << endl;
}

// 本函数能重载是因为传递的参数不同A<int> A<double> 在调用的时候可以分辨 不会产生二义性
// 而且函数可以分辨内容 所以只能通过重载才能访问到对应的内容
void c(A<double> & t)  // 这类似于重载 重载的版本基于模板类的对应函数生成的函数 
{                      // 这理解来就是模板类的对应函数的 具体化
    cout << "temp:" << t.temp << endl;
}


// 模板类的模板成员函数定义
// 分为约束模板友元函数和非约束友元函数
// 约束模板友元函数
template<class T>
void d()        // 对类内的约束友元声明进行具体化
{
    cout << A<T>::count << endl;
}

template<class T>
void dd(T & t)
{
    cout << t.temp << endl;
}
// template <> void d<A>(){} this is error
// template <> void d<A<int> >(){cout << A<int>::count << endl;}  ok.but template 没起作用啊


// 非约束模板友元函数
template<class U>
void e()
{
    cout << A<U>::count << endl;
}

template<class U>
void ee(U & t)
{
    cout << t.count << endl;
}


// 使用typedef 和using 简化代码
// typedef A<int> ai; 
// using ad = A<double>;
// using 也可用于其他类型

int main(void)
{
    A<int> tint(11);
    A<double> tdouble(11.1);

    tint.a();
    tint.aa();
    tdouble.a();
    tdouble.aa();

    b();
    c(tint);
    c(tdouble);

    d<int>();           //
    d<double>();
    dd(tint);
    dd(tdouble);

    e<int>();
    e<double>();
    ee(tint);
    ee(tdouble);



    return 0;
}