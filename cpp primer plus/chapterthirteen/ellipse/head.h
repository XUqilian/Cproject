#ifndef HEAD_H
#define HEAD_H

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class ABC
{
    private:
        double x;
        double y;

    protected:
        const double Pi = 3.1415926;
        void move(double a,double b){x=a;y=b;}

    public:
        ABC(double a = 0 , double b = 0){x = a; y = b;}
        virtual ~ABC(){}
        virtual double area()=0;
        friend ostream& operator<<(ostream& op,ABC& t)
            {return op << "x:" << t.x << "\ty:" << t.y << endl;}

};

class Ellipse : public ABC
{
    private:
        double major;
        double minor;
        double angle;
    public:
        Ellipse(double ma,double mi,double an = 0 ,double x = 0,double y = 0) : ABC(x,y) 
            {major = ma; minor = mi;angle = an;}
        virtual ~Ellipse(){}
        
        virtual double area(){return ABC::Pi * major *minor;}

        void altang(double ang){angle = ang;}

        friend ostream& operator<<(ostream& op,Ellipse& t)
        {   
            // op << (ABC&) t;
            return op << (ABC&)t << "major:" << t.major << "\tminor:" << t.minor << "\tangle:" << t.angle << endl;
        }

};

class Circle : public ABC
{
    private:
        double axis;
    public:
        Circle(double a,double x = 0 , double y = 0) :ABC(x,y) {axis = a;}
        virtual ~Circle(){}
        
        virtual double area(){return ABC::Pi * axis *axis;}
        
        friend ostream& operator<<(ostream& op,Circle& t)
        {   
            // op << (ABC&) t;
            return op << (ABC&)t << "axis:" << t.axis << endl;
        }
};

#endif