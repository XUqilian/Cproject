#ifndef TV_H
#define TV_H

#include<iostream>
using std::cout;
using std::endl;

// class Remote;

// class Tv{
//     private:
//         enum{off, on};
//         enum{minv = 0 , maxv = 20};
//         enum{minc = 1 , maxc = 100};
//         enum{tv , cd};
//         int statu;
//         int volume;
//         int channel;
//         int input;
//     public:
//         Tv(int s = off, int v = minv , int c = minc , int i = tv):statu(s) , volume(v) , channel(c) , input(i) {}
//         ~Tv(){}

//         void setsta(){ statu = (statu == on)? off : on ;}
//         void volup(){ if(volume < maxv) volume++;}
//         void voldown(){ if(volume > minv) volume--;}
//         void chaup(){ channel++; if(channel > maxc ) channel = minc; }
//         void chadown(){ channel--; if(channel < minc ) channel = maxc; }
//         void setin(){ input = (input == tv)? cd : tv ;}
//         void show()const {if (statu == on) cout << "input:" << input << "\nvolume:" << volume << "\nchannel:" << channel  << endl;}        

//         friend void Remote::rsetcha(Tv & , int );   // cant do it 
//         // friend void rsetcha(Tv & , int );
// };


// class Remote
// {
//     private:
//         int mode;
//     public:
//         Remote(){}

//         void rsetsta(Tv & t){ t.setsta(); }
//         void rvolup(Tv & t){ t.volup(); }
//         void rvoldown(Tv & t){ t.voldown(); }
//         void rchaup(Tv & t){ t.chaup(); }
//         void rchadown(Tv & t){ t.chadown(); }
//         void rsetin(Tv & t){ t.setin(); }  

//         // friend void rsetcha(Tv & , int );    //如果这个声明为友元,那这个存在的意义就没有了
//         void rsetcha(Tv & t , int num){ if (num < t.maxc) t.channel = num; }    //已经是友元了为什么不能访问成员变量呢
// };


// void rsetcha(Tv & t , int num){ if(num < t.maxc) t.channel = num; }

// 实现这个的最佳办法就是将所有的函数放在类声明外 或者多文件 那样能最少照顾交叉部分 但代码量肯定会增加 
class Tv;

class Remote
{
    private:
        int mode;
        // enum{off, on};
        // enum{minv = 0 , maxv = 20};
        // enum{minc = 1 , maxc = 100};
        // enum{tv , cd};
    public:
        Remote(){}

        void rsetsta(Tv & t);       //不在这里定义是因为该函数会调用Tv类成员函数 而在这里Tv类还没有定义该函数
        void rvolup(Tv & t);
        void rvoldown(Tv & t);
        void rsetcha(Tv & t , int num);
        void rchaup(Tv & t);
        void rchadown(Tv & t);
        void rsetin(Tv & t); 
};

class Tv{
    private:
        enum{off, on};
        enum{minv = 0 , maxv = 20};
        enum{minc = 1 , maxc = 100};
        enum{tv , cd};
        int statu;
        int volume;
        int channel;
        int input;
    public:
        Tv(int s = off, int v = minv , int c = minc , int i = tv):statu(s) , volume(v) , channel(c) , input(i) {}
        ~Tv(){}

        void setsta(){ statu = (statu == on)? off : on ;}
        void volup(){ if(volume < maxv) volume++;}
        void voldown(){ if(volume > minv) volume--;}
        void chaup(){ channel++; if(channel > maxc ) channel = minc; }
        void chadown(){ channel--; if(channel < minc ) channel = maxc; }
        void setin(){ input = (input == tv)? cd : tv ;}
        void show()const {if (statu == on) cout << "input:" << input << "\nvolume:" << volume << "\nchannel:" << channel  << endl;}        

        friend void Remote::rsetcha(Tv & , int );
};


inline void Remote::rsetsta(Tv & t){ t.setsta(); }      //加上inline 说明是内联函数  //这里能用是因为那些成员函数已经在上面定义过了
inline void Remote::rvolup(Tv & t){ t.volup(); }
inline void Remote::rvoldown(Tv & t){ t.voldown(); }
inline void Remote::rsetcha(Tv & t , int num){ if (num < Tv::maxc) t.channel = num; }
inline void Remote::rchaup(Tv & t){ t.chaup(); }
inline void Remote::rchadown(Tv & t){ t.chadown(); }
inline void Remote::rsetin(Tv & t){ t.setin(); }

#endif