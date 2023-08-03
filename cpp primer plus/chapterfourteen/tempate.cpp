类
is a类公有继承
抽象基类

has a继承
包含：将类的实例化包含在其中，使用类的接口
私有继承：将类模块包含其中，使用类名+域解析运算符访问，访问基类使用强制类型向上转换

多重继承
MI多重继承
	分清虚基类和抽象基类

类模板

类模板实例化：
模板函数的实例化:
类模板显示实例化：
	template class classname<type ...>;
模板函数的显示实例化：
类模板含非类型参数：模板参数中存在固定类型参数
tamplate<typename T1,type T2 ...> class classname{}
函数模板含非类型参数：
tamplate<typename T1 ,type T2 ...> 
returntype functionname(){}
类模板多类型参数：拥有多个可变类型参数
tamplate<typename T1, typename T2 ...>
函数模板多类型参数：
tamplate<typename T1 ...> returnname functionname(){}
半具体化：
模板函数半具体化：
tamelate<typename T1> returnname functionname(type t ...){}
类模板函数半具体化:
tamelate<typename T1> class classname<type t ...>{}
具体化：提供类模板可变类型为固定类型的模板成员变量以及成员函数的定义（更类似于模板的重载）
类模板函数具体化：
tamplate<> class classname<type t1 ...>(...){}
模板函数半具体化：
tamplate<typename T1 ...> returnname functionname(...){}
类模板函数班具体化
tamplate<typename T1 ...> class classname<type t1 ...>(...){}

模板类的普通成员函数 无参无返回 类外定义
无返回 有基本类型参/本模板类对象参
基本返回类型/本模板类对象返回
有返回有参数
定义代码template<class T>class classname<T>::funcname(){}

友元：

普通友元：：
无参无返回
有参
有返回
定义代码template<calss T> returntype funcname(){}

约束友元：：友元的类型取决于类被实例化时的类型
类外模板函数，类内

非约束友元：：友元的所有具体化都是类的每一个具体化的友元
类内的模板函数，适应类变化而具体化