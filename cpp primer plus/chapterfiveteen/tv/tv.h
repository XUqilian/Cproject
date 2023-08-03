#ifndef TV_H
#define TV_H

#include<iostream>
using std::cout;
using std::endl;

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

        friend class Remote;
};


class Remote
{
    private:
        int mode;
    public:
        Remote(){}

        void rsetsta(Tv & t){ t.setsta(); }
        void rvolup(Tv & t){ t.volup(); }
        void rvoldown(Tv & t){ t.voldown(); }
        void rsetcha(Tv & t , int num){ if (num < Tv::maxc) t.channel = num; }
        void rchaup(Tv & t){ t.chaup(); }
        void rchadown(Tv & t){ t.chadown(); }
        void rsetin(Tv & t){ t.setin(); }  
};

#endif