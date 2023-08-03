#include "head.h"
#include <cmath>


//角度=180°/π*弧度  弧度=180°/Π*度数
// atan2(double y,double x) 其中y代表已知点的Y坐标 同理x ,返回值是此点与远点连线与x轴正方向的夹角
// sin(x)返回正弦值(对边比斜边)...依此类推
// sin(o)对边比斜边 cos(o)是临边比斜边 tan(o)对边比临边
// sin(x)和cos(x)的公式  泰勒展开

//构造函数与reset函数代码重复,应该解决一下
//虽然函数析构函数没有实质代码,但定义依旧不能免去

void wanderars::setx()
{
    x = mag * sin(ang);
} //设置x
void wanderars::sety()
{
    y = mag * cos(ang);
} //设置y
void wanderars::setmag()
{
    mag = sqrt(x * x + y * y);
} //设置mag
void wanderars::setang()
{
    if (0 == x && 0 == y)
        ang = 0;
    else
    {
        ang = atan2(x, y);
    }
} //设置ang
void wanderars::setmoder()
{
    mode=rect;
}
void wanderars::setmodep()
{
    mode=pol;
}
wanderars::wanderars()
{
    x=y=mag=ang=0;
    mode=rect;
}
wanderars::~wanderars(){}

wanderars::wanderars(double a, double b, Mode c)
{
    mode=c;  //参数传入与参数赋给成员并不一样,这一步千万不能忘了
    if (c == rect)
    {
        x = a;
        y = b;
        setmag();
        setang();
    }
    else if (c == pol)
    {
        mag = a;
        ang = b;
        setx();
        sety();
    }
    else
    {
        printf("function has error! enum do not constraints(限制)input of type.\n");
    }
}

void wanderars::reset(double a, double b, Mode c)
{
    mode=c;
    if (c == rect)
    {
        x = a;
        y = b;
        setmag();
        setang();
    }
    else if (c == pol)
    {
        mag = a;
        ang = b;
        setx();
        sety();
    }
    else
    {
        printf("function has error! enum do not constraints(限制)input of type.");
    }
    //return this;
}

void wanderars::operator+(const wanderars &t)
{
    x += t.x;
    y += t.y;
    setang();
    setmag();
    //reset(x+t.x,y+t.y);  //显著减少代码量
}

// wanderars& wanderars::operator+(const wanderars&t)
// {
//     return(wanderars(x+t.x,y+t.y));
// }

void wanderars::operator-(const wanderars &t)
{
    x -= t.x;
    y -= t.y;
    setang();
    setmag();
}

std::ostream & operator<<(std::ostream &os, wanderars &t)
{
    if (t.mode == wanderars::rect)//友元函数,这里要在标识符加上类解析才能用到
    {
        os<<"t.x="<<t.x<<"\tt.y"<<t.y;//<<endl;
    }
    else if (t.mode == wanderars::pol)
    {
        os<<"t.mag="<<t.mag<<"\tt.ang"<<t.ang;//<<endl;
    }
    else
    {
        printf("function has error! enum do not constraints(限制)input of type.");
    }
    //os << t.ang << '\t' << t.mag << '\t' << t.x << '\t' << t.y << endl;
    // printf("t.x is %f\tt.y is %f\tt.mag is %f\tt.ang is %f\t.",t.x,t.y,t.mag,t.ang);

    return os;
}
