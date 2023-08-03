#include"head.h"

double & Stu::operator[](int t)
{
    return valarray<double>::operator[](t);
    // 使用时需用无名类的类型加域解析运算符调用
}

ostream & operator << (ostream & os,const Stu & t)
{
    // 友元函数并不是类成员函数 无法使用基类函数 因为基类是私有继承
    os << "name:" << (string &)t << endl;
    // 第一种方法 强制转换该类型到父类以使用  向上强制转换
    // 原以为这种方法会受限 但转换的父类只要单一 string 类 不会受到子类影响
    // 想想又觉得不对 万一不是标准的父类 内含多种参数又该怎么转换
    // 而且子类两个成员如果近似 如 string  char* 该怎么转换

    for(int i = 0 ; i < t.valarray<double>::size() ; i++ )
    // 第二种方法 类型名加域解析运算符
    {
        // 第三种方法  using 将基类(这里是valarray)的类函数引入
        // using std::valarray<double>::operator[]; // 这里类方法引入无需加括号 只是引入一个声明
        // 在这里好像不能用 先加进头文件了
        // os << t.valarray<double>::operator[](i) << "\t";
        // 下面可以了
        os << t[i] << "\t";
    }
    return os << endl;
}

istream & operator>>(istream & is,Stu & t)
{
    cout << "now name is:" << (const string &)t << "\nenter name:";
    
    //is >> t;  // 这里应该是隐式向上转换了 谁知道存到 string 还是valarray 如果传错 还会入错参数的情况
    is >> (string &)t;  // 上面错了 显示强制转换还是可以用的 大概可以理解要用哪个类型就向哪个类型强制转换

    while (getchar() != '\n');

    cout << "have " << t.valarray<double>::size() << "element,need add please enter(dont want enter yuanlai size)" << ":";
    int n;
    is >> n;
    while (getchar() != '\n');
    
    t.valarray<double>::resize(n);
    cout << endl;    
    for(int i = 0 ; i < t.valarray<double>::size() ; i++)
    {
        is >> t[i];  //这里使用了头文件中的 using
    }
    cout << endl;
    return is;
}

