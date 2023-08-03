#include<iostream>
//#include"D:\Code\VSCODE\Cproject\cpp\aheads\cpp.h"
#include<fstream>  //is_open() cin.eof() cin.fail() cin.good() 
#include<cstdlib>

void errcin(void)
{
    if(std::cin.fail())
    {
        std::cin.clear();
        while(std::cin.get()!='\n');
    }
    
}

using std::cin;
using std::cout;
using std::endl;
using std::fstream;

const int Asize=3;

int main(void)
{
    double temp[Asize];

    fstream fe;
    fe.open("t2.txt");
    if(!(fe.is_open()))
    {
        cout<<"the file cant open,done!"<<endl;
        exit(EXIT_FAILURE);
    }

    for(int cnt=0;cnt < Asize;cnt++)
    {
        cout<<"enter number:";
        if(!(cin>>temp[cnt]))
        {
            cnt--;
            errcin();
            cout<<"error enter,please enter again:"<<endl;
        }
    }

    for(int i=0;i<Asize;i++)
    {
        fe<<temp[i]<<' ';
    }

    fe.seekg(0,std::ios::beg);
//     重置文件偏移位置到文件开头向后偏移 0 个字符
//     istream &seekg(streamoff offset,seek_dir origin);   seekg 读取设置
//     ostream &seekp(streamoff offset,seek_dir origin);   seekp 写入设置
//     iOS::beg 开头  iOS::cur 当前位置  iOS::end 结尾位置   streamoff offset 偏移量
    
    double tt;
    for(int i=0;i<Asize;i++)
    {
        if(fe>>tt)
            cout<<tt<<endl;
        else if(fe.eof())
            cout<<"end of file."<<endl;
        else if(fe.fail()){
            cout<<"failled!DONE!"<<endl;
            exit(EXIT_FAILURE);
        }else{
            cout<<"unknow err!DONE!"<<endl;
            exit(EXIT_FAILURE);
        }
    }

    fe.close();
    return 0;
}
