#ifndef HEAD_H
#define HEAD_H
#include <iostream>

class wanderars // wanderars  漫步者
{
public:
    enum Mode
    {
        rect,
        pol
    }; //标识

private:
    double x;   //横坐标
    double y;   //纵坐标
    double mag; //向量长度
    double ang; // angle角度
    Mode mode;  //标识

    void setx();   //设置x
    void sety();   //设置y
    void setmag(); //设置mag
    void setang(); //设置ang

public:
    wanderars();
    ~wanderars();
    wanderars(double, double, Mode c = rect);
    void reset(double, double, Mode c = rect); //重新设置

    void operator+(const wanderars &); //重载+
    // wanderars operator+(const wanderars&);
    void operator-(const wanderars &); //重载-

    void setmoder(); //将模式设置为坐标
    void setmodep(); //将模式设置为矢量

    friend std::ostream &operator<<(std::ostream &, wanderars &); //类友元函数重载输出<<符号
    // std::ostream & operator<<(std::ostream &);  //类成员函数重载输出<<符号会出现 t<<cout 违反了函数库初衷 应是cout<<t

    double backx() const { return x; };     //返回x值
    double backy() const { return y; };     //返回y值
    double backmag() const { return mag; }; //返回mag值
    double backang() const { return ang; }; //返回ang值
};

#endif