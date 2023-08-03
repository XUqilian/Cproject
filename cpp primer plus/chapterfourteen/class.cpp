// 类
class classname{};

// is a类公有继承
class classnameA:public classname {};

// 抽象基类
class classnameB{ public: virtual void vir() = 0;  };


// has a继承
// 包含:将类的实例化包含在其中,使用类的接口
class classnameC{ classname T;};

// 私有继承:将类模块包含其中,使用类名+域解析运算符访问,访问基类使用强制类型向上转换
class classnameD:private classname{};

// 多重继承
class classnameE:public classnameA{}; //e - a - ..

// MI多重继承 
class classnameF : public virtual classname{};
class classnameG : public classnameF ,public classnameE{};

// 	分清虚基类和抽象基类 //不可创建对象 实现类规范接口  //继承者加入virtual限定 多继承只会有一个对象





// 模板知识包含以下,可多种类搭配 每添加一种就更复杂
// 类模板
// 函数模板
// 类模板函数   //类模板内的成员函数
// 类模板函数模板   //模板类内的成员函数是函数模板
// 类模板友元函数  // 友元类外定义时无需添加类指定
// 类模板约束友元函数   //类前声明 类内友元 类外定义依据声明  为特定类型指定的模板类似具体化
// 类模板非约束友元函数     //类内友元声明 类外依据声明定义
// 类模板友元模板函数   //......
// 非类型参数      // 提供了部分固定模板参数类型  使模板初始化时可接收指定类型参数初始化模板
// 显示实例化   //template classname<type>; 提供针对type类的声明 只为加快运行速度
// 部分具体化   //所有具体化方面:具体化的参数不存在于<>中的 需要在函数名或类名后用<>指定
// 具体化   //全具体化<>没有参数 参数具体化在后面<>中
// 类模板参数为类模板   //......




//类模板
template<typename T> class classnameH
{
    T a;
    public:
        void fun();
};
// 类模板实例化:  创建对象隐式实例化 classnameH<type> t;
// 模板函数的实例化:  创建对象隐式实例化
// 类模板显示实例化:    // 	
template class classnameH<int>; // 声明为此类型创建实例化  代码自动生成

// 模板函数的显示实例化:    
template void classnameH<int>::fun(); // 声明为此类型创建实例化  代码自动生成

// 类模板含非类型参数:模板参数中存在固定类型参数
template<typename T1,int n> class classnameI{
    public:
// 函数模板含非类型参数:
        template<typename T,int nn> void fun();
};  //等于给类内增加一个运行时确定的变量

// 函数模板含非类型参数怎么定义:
template<template T1,int n>     // 类模板声明 指定一级类的模板类型
    template<template T,int nn>     //函数模板声明 指定二级的模板类型
        void classnameI<T1,n>::fun<T,nn>(){}; // classname<type>才是类型 确定一级模板是类 ()确定二级是函数

//  类模板函数模板的定义
template<typename T> class classnameJ
{
    public:
        template<typename TT>   void fun();
};

template<typename T>
    template<typename TT>
        void classnameJ<T>::fun<TT>(){}

// 类模板多类型参数:拥有多个可变类型参数
// template<typename T1, typename T2 ...>

// 函数模板多类型参数:
// template<typename T1 ...> returnname functionname(){}

// 具体化:提供类模板可变类型为固定类型的模板成员变量以及成员函数的定义(更类似于模板的重载)
// 具体化时需要重新声明和定义模板内的所有内容
// 模板具体化: template<...> class classname<...>{}
// 函数具体化: template<...> returntype functionname<>(){}

// 部分具体化:  具体化的参数不存在于<>中 需要在函数名或类名后用<>指定
// 部分具体化还是模板,但具体化已经是确定类或者函数

// 函数模板部分具体化:
// tamelate<typename ...> returnname functionname(type t ...){}
// 类模板函数部分具体化:
// temelate<typename ...> class classname<type t ...>{}
// 类模板函数模板部分具体化
// template<typename ...>  template<typename ...>   returntype classname<...>::funtion<...>(){}

// 类模板具体化:    不存在于<>中的类型或参数 需要在类名后用<>指定 全具体化时<>为空
// template<> class classname<type t1 ...>(...){}
// 类模板函数具体化:
// temelate<> class classname<type t ...>{}
// 类模板函数模板具体化

// 模板类的普通成员函数 无参无返回 类外定义
// 无返回 有基本类型参/本模板类对象参
// 基本返回类型/本模板类对象返回
// 有返回有参数
// 定义代码template<class T>class classname<T>::funcname(){}

// 友元:

// 普通友元::
// 无参无返回
// 有参
// 有返回
// 类外定义代码template<calss T> returntype funcname(){} //友元无需添加classname<>:: 限定

// 约束友元::友元的类型取决于类被实例化时的类型
// 类外模板函数,类内

// 非约束友元::友元的所有具体化都是类的每一个具体化的友元
// 类内的模板函数,适应类变化而具体化