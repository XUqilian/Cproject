// use "https://blog.csdn.net/zmr233/article/details/130965382"

#include<iostream>
#include<typeinfo>

using namespace std;

//这是约束模板友元函数的类前声明:
template<typename U> void counts_();
template<typename U> void show_(U& pt);

template <class T>
class Player
{
private:
  static int count;
  T num;
public:
  Player() {};
  Player(T num_) :num(num_){};
public:
//1.非模板友元函数
  friend void counts();
  friend void show(Player<T>& pt);
public:
//2.约束模板友元函数-U
  friend void counts_<T>();
  friend void show_<>(Player<T>& pt);
public:
//3.非约束模板友元函数-V
  template<typename V>
  friend void counts__();
  template<typename V>
  friend void show__(V & pt);
};
//静态成员初始化:
template <class T>
int Player<T>::count = 101;
template <>
int Player<int>::count = 111;
template <>
int Player<double>::count = 222;
/*---------------------------------------*/
//1.非模板友元函数
void counts()
{
  cout << "#<int>-static:" << Player<int>::count << endl;
  cout << "#<double>-static:" << Player<double>::count << endl;
}
void show(Player<int>& pt)
{
  cout << "#<int>-num:" << pt.num << endl;
}
void show(Player<double>& pt)
{
  cout << "#<int>-num:" << pt.num << endl;
}
/*---------------------------------------*/
//2.约束模板友元函数-U
template<typename U>
void counts_()
{
  U type;
  cout << "#<U>-static:" << typeid(type).name() 
    << "#:" << Player<U>::count << endl;
}
template<typename U>
void show_(U& pt)
{
  U type;
  cout << "#<U>-num:" << typeid(type).name() 
    << "#:" << pt.num << endl;
}
/*---------------------------------------*/
//3.非约束模板友元函数-V
template<typename V>
void counts__()
{
  V type;
  cout << "#<V>-static:" << typeid(type).name() 
    << "#:" << Player<V>::count << endl;
}
template<typename V>
void show__(V& pt)
{
  V type;
  cout << "#<V>-num:" << typeid(type).name() 
    << "#:" << pt.num << endl;
}
/*---------------------------------------*/
int main()
{
  Player<int> zmr(2333);
  //1.非模板友元函数:
  counts();
  show(zmr);
  cout << "-----------------\n";
  //2.约束模板友元函数-U:
  counts_<int>();
  show_(zmr);
  cout << "-----------------\n";
  //3.非约束模板友元函数-V:
  counts__<int>();
  show__(zmr);
  cout << "-----------------\n";

}