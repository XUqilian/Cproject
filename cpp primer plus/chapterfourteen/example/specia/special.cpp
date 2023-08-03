// #ifndef HEAD_H
// #define HEAD_H

#include<iostream>
// #include<string>
// using std::string;
using std::cout;
using std::endl;


// 模板
template<class T1,class T2>
class Spe
{
    public:
        void show();
};
// 模板函数
template<class T1,class T2>
void Spe<T1,T2>::show()
{
    cout << "use unexpilict specialization." << endl;
}


// 显示实例化  在编译时就在内存中实现该类型 可以在运行时加快
template class Spe<int,int>;  
// 此处是针对int的实例化



// 部分具体化 对模板部分参数限定
template<class T2> // 其中<>中是没有具体化的参数 没有前后顺序 T1 T2 都可以 
class Spe<T2,char>  // 没有前后顺序
{
    public:
        void show();
};
// 部分具体化函数
template<class T1>
void Spe<T1,char>::show()
{
    cout << "use part specialization." <<endl;
}


// 模板显示具体化 
// 无需在模板括号加入类型参数 因为该模板脱胎于已存在模板 只需要标明具体化类型就好
template<> class Spe<char *,char*>
{
    public:
        void show();
};
// 具体化函数 无需加上模板限定
void Spe<char*,char*>::show()
{
    cout << "use specialization." << endl;
}

//  和函数模板一样 模板将寻求最优符合模板 
// 当最优不存在时再进行最相似匹配 对自身参数进行强制转换匹配


int main(void)
{
    Spe<double,double> generl; // 通用模板generel template
    Spe<int ,int> a; //  use explicit specia
    Spe<int , char> b;  // use part specia
    Spe<char* ,char*> c;  // use all specia
    generl.show();
    a.show();
    b.show();
    c.show();
    return 0;
}




// #endif