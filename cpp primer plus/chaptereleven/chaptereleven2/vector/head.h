//
#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cmath>

namespace Vtr{

    using std::ostream;
    using std::endl;
    using std::cout;

    //π圆周率,α角度,l 弧度
    //l = α * π / 180
    //α = 180 * l / π
    const double Atr = 3.1415926 / 180;     //angle to radian
    const double Rta = 180 / 3.1415926;     //radian to angle

    class Vector
    {
        public:
            enum Mode{coo,vec};     //mode

            //const static 和 static const 一样,都不能在类内直接初始化非整形常量,可以修饰 int,bool,char,但不能修饰其他类型 (如 double,float)
        private:
            double x;       //x coordinate
            double y;       //y coordinate
            double ang;     //lenth
            double mag;     //angle

            Mode md;
            //bool setx();
            //bool sety();

            //sin(x) 对边/斜边      
            //cos(x) 临边/斜边      
            //tan(x) 对边/临边

            void setcoo() ;  
            void setvec() ;

        public:
            Vector(){x=y=ang=mag=0;}
            Vector(double, double ,Mode m = coo);

            double valx()const {return x;}
            double valy()const {return y;}
            double valmag()const {return mag;}
            double valang()const {return ang;}
            
            void setmdc() {md = coo;}       // set mode coordinate
            void setmdv() {md = vec;}       // set mode vector

            Vector operator + (Vector &t)const ;
            Vector operator - (Vector &t)const ;
            Vector operator - ();
            Vector operator * (double t)const;

            friend Vector operator * (double f, Vector &t) ;

            //ostream & operator << (ostream &os){ os << "x value:"<< x << "y value:" << y << endl;}        //   t << cout no!
            friend ostream & operator << (ostream & os , Vector & t);   //{ os << "x value:"<< t.x << "y value:" << t.y << endl;}  //need output by mode

    };
};

#endif