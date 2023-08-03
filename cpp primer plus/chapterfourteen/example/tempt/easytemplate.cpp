

template<class T> 
class S{
    private:
        T a;
    public:
        S(){}
};

//#######################################################

// 如果您想要对类模板的所有类型参数都进行具体化,那么您可以使用模板的显式具体化(Explicit Specialization)的技术,也称为模板类的全特化.这种方法需要您为具体化的类型参数重新定义类模板的所有成员变量和成员函数12.

// 例如:如果您想要对类模板 Point<T1, T2> 的类型参数 T1 和 T2 都具体化为 char* 类型,那么您可以这样写:

// template<> class Point<char*, char*>{
//     public:
//         Point(char *x, char *y): m_x(x), m_y(y) { }
//     public:
//         char *getX() const{ return m_x; }
//         void setX(char *x) { m_x = x; }
//         char *getY() const{ return m_y; }
//         void setY(char *y) { m_y = y; }
//         void display() const;
//     private:
//         char *m_x;
//         char *m_y;
// };
// 复制


template<template<class T>class T1>
class N
{
    private:
        T1 aa;
    public:
        N(){}

};

template<> class N<S>
{
    private:
        T aa; // 这个应该怎么声明
        T1 aa;
        S aa;
        S<T> aa;
        S<int> aa; // 必须确定类型吗?
    public:
        N(){}
};

//############################################################

// 如果您只想要对类模板的部分类型参数进行具体化,那么您可以使用模板偏特化(Partial Specialization)的技术,也称为模板类的部分特化.这种方法需要您为没有被具体化的类型参数保留模板参数列表,并为具体化的类型参数重新定义类模板的所有成员变量和成员函数12.

// 例如:如果您想要对类模板 Point<T1, T2> 的类型参数 T1 具体化为 char* 类型,而 T2 保持泛型,那么您可以这样写:

// template<typename T2> class Point<char*, T2>{
//     public:
//         Point(char *x, T2 y): m_x(x), m_y(y) { }
//     public:
//         char *getX() const{ return m_x; }
//         void setX(char *x) { m_x = x; }
//         T2 getY() const{ return m_y; }
//         void setY(T2 y) { m_y = y; }
//         void display() const;
//     private:
//         char *m_x;
//         T2 m_y;
// };
// 复制
// 如果您不想要对类模板的任何类型参数进行具体化,那么您可以直接使用类模板实例化(Instantiation)的方法,也就是在定义对象时指定类型参数的真实类型3.

// 例如:如果您想要用类模板 Point<T1, T2> 定义一个对象 p ,并指定类型参数 T1 为 int 类型,T2 为 char* 类型,那么您可以这样写:

// Point<int, char*> p(10, "E180");

template<template<class T>class T1 , class T2>
class NN
{
    private:
        T1 aa;
    public:
        N(){}

};

template<class T2> class NN<S,T2>
{
    private:
        T aa; // 这个应该怎么声明
        T1 aa;
        S aa;
        S<T> aa;

        S<T2> aa;  //??

        S<int> aa; // 必须确定类型吗?
    public:
        N(S<T2> s){}

};
// ####################################################





// template<class TT> // 接受一个确定 "类型"

template<template<class T>class TT> // 接受一个不确定类型 "模板" 
class Nested 
{
    private:
    //  TT sa;  //标准模板类创建  // 在这里TT只是一个模板类 并不是类对象
        TT<int> stai; // TT<int> 类创建  //这里才是一个类对象
        // 是不是也可以运行时确定使用哪种类型 TT<T> sta;
        TT<double> stad;
    public:
        // Nested(TT t,TT tt) // have error 
        Nested(TT t,TT tt) //接受参数与类成员类型相同 才能给类成员赋值 根据模板声明 此处接受的是模板
            :stai(t),stad(tt){} //此处将模板赋给类成员 

        // 后续就需要根据传入模板来确定使用的函数了
        // 这里先根据头文件引用 确定传入栈模板
        bool push(int a, double b){return stai.push(a) && stad.push(b);} 
        bool pop(){return stai.pop()&& stad.pop();}

};

// ###我理解为 具体化其实就是定义一个新类 表面类似于老类 但内部是所以与老的模板类毫无关系
// ###有关系的仅仅是模板参数相同 具体化的模板参数"参照"老模板 具体化类内的成员"参照"老模板
// ###或许说更类似于 "重载"

// #2
// can use 模板具体化
// template<> class Nested<Stack>
// {
//     private:
//         Stack<int> stai; // it no significance
//         Stack<double> stad;  // here has error. cant identify TT

//     public:
//         bool push(int a, double b){return stai.push(a) && stad.push(b);} 
//         bool pop(){return stai.pop()&& stad.pop();}
// };


// #1  detailed read .\easytemplate.cpp
// template<template<class T>class TT, class Ta ,class Tb> 
// class Nesteds 
// {
//     private:
//         TT<Ta> staa;
//         TT<Tb> stab;  //how to assign Tb.its a type not a type element
//     public:
//         // Nested(TT t,TT tt) // have error 
//         Nesteds(){}
//         Nested(TT t,TT tt) 
//             :staa(t),stab(tt){}

//     // .\..\specia\elementtemplate.cpp  类似于此
//     // 如果此模板在加上一个参数class TTT是不是可以确定使用的栈的类型
//     // template<template<class T>class TT , class TTT>
// };
