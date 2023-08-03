#ifndef HEAD_H
#define HEAD_H
#include<iostream>
using std::cin;
using std::cout;
using std:: endl;
using std::ostream;
 class Times
 {
    private:
        int hours;
        int minutes;
        // inline int htom()const {return hours*60;};
    public:
        Times(){hours = minutes = 0;};
        Times(int ,int);
        void addh(int);
        void addm(int);
        void reset(){hours = minutes = 0;};

        friend Times operator+(Times &,Times &);
        friend Times operator-(Times &,Times &);
        friend Times operator*(Times &,int );
        friend Times operator*(int ,Times &);
        friend ostream & operator<<(ostream &os,Times & t)
        {
            os << "hours:" << t.hours << "\tminutes:" << t.minutes << endl;
            return os;
        }
 };


#endif
