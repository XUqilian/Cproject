#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

void inline flushclear(){while('\n' != getchar());}     // 清除输入缓冲区剩余字符 直到遇见换行 读取并抛弃换行

class Abstr
{
    private:
        string fname;
        string lname;
        string job;
    public:
        Abstr(){}
        Abstr(const string & f , const string & l , const string & j) : fname(f) , lname(l) , job(j) {}
        virtual void show() {cout << fname << ' ' << lname << ' ' << job << endl;}
        virtual void set()
        {
            cout << "enter fname:";
            cin >> fname;
            cout << "\nenter lname:";
            cin >> lname;
            cout << "\nenter job:";
            cin >> job;
            // 下面这两句看项目重要性添加
            while('\n' != getchar());
            cin.clear();
        }
        friend ostream & operator << (ostream & op , const Abstr & ab);
        virtual ~Abstr() = 0;

        virtual void writefile(ostream & op)
        {
            // op.write((char*)this , sizeof(Abstr));  // 能得到类名字符串typeid(...).name 或者类名比较出对错typeid(...)
            op << fname.c_str() << endl << lname.c_str() << endl << job.c_str() << endl;
        }

        virtual void readfile(ifstream & ip)
        {
            ip >> fname >> lname >> job ;
        }
};

Abstr::~Abstr(){}   // 抽象基类的纯虚函数可以不用定义 但当前纯虚函数是析构函数 涉及析构对象 必须定义

class Empl : public Abstr{
    public:
        Empl(){}
        Empl(const string & f , const string & l , const string & j) : Abstr(f,l,j) {}
        virtual void show() override  {Abstr::show();}
        virtual void set()   {Abstr::set();}
        
        virtual void writefile(ostream & op)
        {
            // op.write((char*)this , sizeof(Empl));  
            op << 4 << endl;
            Abstr::writefile(op);
        }

        virtual void readfile(ifstream & ip)
        {
            Abstr::readfile(ip);
        }
};

class Manager : virtual public Abstr
{
    private:
        int icef;
    protected:
        int & valicef(){return icef;}
    public:
        Manager(){}
        Manager(const string & f , const string & l , const string & j , int i = 0) : Abstr(f,l,j) , icef(i) {}        
        Manager(const Abstr & abs , int i = 0) : Abstr(abs) , icef(i) {}
        virtual void show() override
        {
            Abstr::show(); 
            cout << "icef:" << icef << endl;
        }
        virtual void set()
        {
            Abstr::set(); 
            cout << "enter icef value:"; 
            cin >> icef ; 
        }

        virtual void writefile(ostream & op)
        {
            // op.write((char*)this , sizeof(Manager));
            op << 1 << endl;
            Abstr::writefile(op);
            op << icef << endl;
        }

        virtual void readfile(ifstream & ip)
        {
            Abstr::readfile(ip);
            ip >> icef;
        }
};

class Fink : virtual public Abstr
{
    private:
        string report;
    protected:
        string & valrep(){return report;}
    public:
        Fink(){}
        Fink(const string & f , const string & l , const string & j , const string & r) : Abstr(f,l,j) , report(r) {}
        Fink(const Abstr & abs,const string & r) : Abstr(abs) , report(r) {}
        virtual void show() override
        {
            Abstr::show();
            cout << "report:" << report << endl;
        }
        virtual void set()
        {
            Abstr::set();
            cout << "enter a string for report:";
            cin >> report;
        }

        virtual void writefile(ostream & op)
        {
            // op.write((char*)this , sizeof(Fink)); 
            op << 2 << endl; 
            Abstr::writefile(op);
            op << report << endl;
        }

        virtual void readfile(ifstream & ip)
        {
            Abstr::readfile(ip);
            ip >> report;
        }
};

class Hightf : public Manager ,public Fink
{
    public:
        Hightf(){}
        Hightf(const string & f , const string & l , const string & j , const string & r ,int i = 0) : Abstr(f,l,j) ,Fink(f,l,j,r) , Manager(f,l,j,i) {}
        Hightf(const Abstr & abs , const string & r , int i = 0) :Abstr(abs) , Fink(abs,r) , Manager(abs,i) {}
        Hightf(const Manager & m , const string & r) : Abstr(m) , Fink(m , r) , Manager(m) {}
        Hightf(const Fink & f , int i = 0) : Abstr(f) , Fink(f) , Manager(f,i) {}
        virtual void show() override
        {
            Abstr::show();
            cout << "icef:" << Manager::valicef() << "\nreport:" << Fink::valrep() << endl;
        }
        virtual void set()
        {
            Abstr::set();
            cout << "enter icef:";
            cin >> Manager::valicef();
            while('\n' != getchar());
            cout << "\nenter a string for report:";
            cin >> Fink::valrep();
        }

        virtual void writefile(ostream & op)
        {
            // op.write((char*)this , sizeof(Hightf)); 
            op << 3 << endl; 
            Abstr::writefile(op);
            op << Manager::valicef() << endl << Fink::valrep() << endl;         
        }

        virtual void readfile(ifstream & ip)
        {
            Abstr::readfile(ip);
            ip >> Manager::valicef() >> Fink::valrep();
        }
};

ostream & operator<<(ostream & op , Abstr & abs)  // show() 已经完善的很好 无需再进行重复的代码 ostream& 仅仅为了拼接cout
{
    abs.show();
    return op;
}

// run at no1 ,need user input date
// dis date
// save date to file
// run at second or other times
// read file date and dis it
// user need input date to file
// dis date
// have a class b array manager date

bool chooes()
{
    cout << '\n' << setw(20) << right <<"chooes" << endl;
    cout << "1:manager obj" << "\n2:fink obj" <<  "\n3:hightf obj" <<  "\n4:empl obj"<<endl;
    cout << setw(22) << right << "q to quit" << endl;
    return true;
}

/*
    //  我想直接将类对象数据以二进制或文本方式存入文件 初步是打算void* 数组存储指针地址 
    //  ((Abstr*) & ar[n]) 可将地址转换回来 ,利用类虚函数特性以达到访问类目的 
    //  测试已知数组内的地址与对象this地址一致
        // void * ar = (void* ) (new Empl);
        // cout << (void *)ar << endl;
        // ((Abstr*) ar)->writefile(cout);
    // 现卡在写入时类大小如何确定 
    // op.write((void*)this , sizeof(???));  // 能得到类名字符串typeid(...).name 或者类名比较出对错typeid(...)
    // 忽然发现调用对象不就是对象类型嘛 然后调用又是通过虚函数定位到指定类的指定函数 我只要在哪个类里面用哪个类型就好了
    // 怎么从文件读取 每个类大小是不一样的 无法确定读取是采用哪个类型
    // ip.read((void*)this , sizeof(???));  读取是从文件读取到指定指针 无法利用指针判断其到底是什么类型 就无法指定读取块大小

*/


int main(void)
{
    const int lim = 10;     // 文件容纳极限

    Abstr * ar[lim]; // 容纳对象指针数组
    int play = 0;  // 需要写入文件的对象类型确认标签
    int cnt = 0 ;    // 当前存在类对象个数标记
    int cntt = 0;     // 写入对象个数标记
    int di = 0 ;    // 读取文件中的区分对象标签
    
    // fstream fio("six" , ios::in | ios::out | ios::app | ios::binary);
    // 以读的方式打开文件
    ifstream fi("six" , ios::in);
    if(fi) // ifstream 不会创建文件 如果文件不存在 返回错误
    {
        // in
        // in type


        // 读取文件内的对象数据
        fi.seekg(0);       // 因为以iOS：:app打开 所以读取时先将读取位置置于开始
        while(fi >> di)
        {   
            Abstr * p = nullptr;
            switch(di)
            {
                case 1:
                    p =  new Manager;
                    // // ((Manager*)ar[cnt++])->readfile(fio); //无发将基类指针指向子类
                    // ar[cnt++]->readfile(fio); // 还好该指针类型在上面分配就已经确定了 可以利用虚函数
                    break;      // 这就是抢先 再其变成Abstr* 前先用 用完再赋给数组就能确保调用时是正确数据
                case 2:
                    p =  new Fink;
                    // ar[cnt++]->readfile(fio);
                    break;
                case 3:
                    p =  new Hightf;
                    // ar[cnt++]->readfile(fio);
                    break;
                case 4:
                    p =  new Empl;
                    // ar[cnt++]->readfile(fio);
            }
            p->readfile(fi);
            ar[cnt++] = p;
            // switch(di)
            // {
            //     case 1:
            //         ar[cnt] =  new Manager;
            //         // ((Manager*)ar[cnt++])->readfile(fio); //无发将基类指针指向子类
            //         ar[cnt++]->readfile(fio); // 还好该指针类型在上面分配就已经确定了 可以利用虚函数
            //         continue;
            //     case 2:
            //         ar[cnt] =  new Fink;
            //         ar[cnt++]->readfile(fio);
            //         continue;
            //     case 3:
            //         ar[cnt] =  new Hightf;
            //         ar[cnt++]->readfile(fio);
            //         continue;
            //     case 4:
            //         ar[cnt] =  new Empl;
            //         ar[cnt++]->readfile(fio);
            // }

        }

        fi.clear();    // 读取到结尾流会设置流状态 将状态清除确保能继续读取
        fi.close();
            
        // 将已有对象进行显示
        while(cnt > 0 && cntt < cnt )
        {
            ar[cntt++]->show();
        }
    }

    // 选择并写入对象
    while(chooes() && cin >> play && cnt < lim)
    {
        // cntt = cnt  ;
        flushclear();
        switch(play)
        {
            case 1 :
                ar[cnt]= new Manager;
                // ar[cnt++]->set();
                // ((Abstr*)&ar[cnt++])->set();  利用转换为void的指针重新转换回来依旧会出现问题
                break;
            case 2 :
                ar[cnt]= new Fink;
                break;
            case 3 :
                ar[cnt]= new Hightf;
                break;
            case 4 :
                ar[cnt]= new Empl;
        }
        ar[cnt++]->set();
    }

    // 显示当前已有及待写入对象
    int i = cntt;
    while(cnt > 0 && i < cnt )
    {
        cout << i << ':';
        ar[i++]->show();
    }

    // 以写入方式打开文件
    ofstream fo("six" , ios::out | ios::app);
    if(!fo)
    {
        cout << "file cant open." << endl;
        exit(0);
    }

    // 向文件写入对象数据
    fo.seekp(0,ios_base::end);  // 再次确保位置正确 不会覆盖之前数据
    while(cnt > 0 && cntt < cnt)
    {
        ar[cntt++]->writefile(fo);
    }
    fo.clear();
    fo.close(); 

    return 0;
}


/*

// 参考网页: https://blog.csdn.net/leowinbow/article/details/86477506

6. 考虑14章的编程练习5中的类定义。如果还没有完成这个练习，请现在就做，然后完成下面的任务。

编写一个程序，它使用标准C++I/O、文件I/O以及14章的编程练习5中定义的employee、manager、fink和highfink类型的数据。该程序应包含程序清单17.17中的代码行，即允许用户将新数据添加到文件中。该程序首次被运行时，将要求用户输入数据，然后显示所有的数据，并将这些信息保存到一个文件中。当该程序再次被运行时，将首先读取并显示文件中的数据，然后让用户添加数据，并显示所有的数据。差别之一是，应通过一个指向employee类型的指针数组来处理数据。这样，指针可以指向employee对象，也可以指向从employee派生出来的其他三种对象中的任何一种。使数组较小有助于检查程序，例如，您可能将数组限定为最多包含10个元素：（后面题目省略）

关于第14章的编程练习5请点击这里

本题比较复杂，我们首先来说第14章的编程练习5。该题提供头文件定义类，由基类派生出来的派生类有4种，每一种代表一个工作职业，其中manager需要指明该职业管理多少人，多一个int类型的inchargeof变量；fink类型需要指明向谁汇报，多一个string对象reportsto。在此基础上，本题要求我们添加两个公有方法，一个是虚函数setall()，用来提示用户输入相应的数据，一个是虚函数writeall()，用来将数据保存到文件中。

所以我们在头文件中每一个派生类都添加这两个方法。

因此头文件emp.h代码如下所示：

#ifndef EMP_H_
#define EMP_H_
 
#include <iostream>
#include <string>
#include <fstream>
enum classkind { Zero, Employee, Manager, Fink, Highfink };
class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;
};
 
class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string & ln, const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};
 
class manager : virtual public abstr_emp
{
private:
    int inchargeof;
protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }
public:
    manager();
    manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};
 
class fink : virtual public abstr_emp
{
private:
    std::string reportsto;
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};
 
class highfink : public manager, public fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};
 
#endif
 
有了头文件之后，我们来处理实现文件。由于头文件中，我们在5个类中都添加了两个公有方法，那么这里就是我们需要对这些公有方法给出定义。

实现文件emp.cpp代码如下所示：

// emp.cpp -- contains the functions' definition
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "emp.h"
using namespace std;
 
abstr_emp::abstr_emp()
{
    fname = "None";
    lname = "None";
    job = "None";
}
 
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
{
    fname = fn;
    lname = ln;
    job = j;
}
 
void abstr_emp::ShowAll() const
{
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
}
 
void abstr_emp::SetAll()
{
    cout << "Please enter the first name: ";
    getline(cin, fname);
    cout << "Please enter the last name: ";
    getline(cin, lname);
    cout << "Please enter the job: ";
    getline(cin, job);
}
 
void abstr_emp::setall(std::ifstream &fin)
{
    getline(fin, fname);
    getline(fin, lname);
    getline(fin, job);
}
 
void abstr_emp::writeall(std::ofstream &fout)
{
    fout << fname << endl << lname << endl << job << endl;
}
 
std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << endl;
    os << "First name: " << e.fname << endl;
    os << "Last name : " << e.lname << endl;
    return os;
}
 
abstr_emp::~abstr_emp()
{
}
 
employee::employee() : abstr_emp()
{
}
 
employee::employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn, ln, j)
{
}
 
void employee::ShowAll() const
{
    cout << "\nEmployee: " << endl;
    abstr_emp::ShowAll();
}
 
void employee::SetAll()
{
    cout << "Employee: " << endl;
    abstr_emp::SetAll();
}
 
void employee::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
}
 
void employee::writeall(std::ofstream &fout)
{
    fout << Employee << endl;
    abstr_emp::writeall(fout);
}
 
manager::manager() : abstr_emp()
{
    inchargeof = 0;
}
 
manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{
}
 
manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico)
{
}
 
manager::manager(const manager & m) : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}
 
void manager::ShowAll() const
{
    cout << "\nManager: " << endl;
    abstr_emp::ShowAll();
    cout << "In charge of " << inchargeof << " employees.\n";
}
 
void manager::SetAll()
{
    cout << "Manager: " << endl;
    abstr_emp::SetAll();
    cout << "In charge of: ";
    cin >> inchargeof;
    cin.ignore();
}
 
void manager::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
    fin >> inchargeof;
    fin.ignore();
}
 
void manager::writeall(std::ofstream &fout)
{
    fout << Manager << endl;
    abstr_emp::writeall(fout);
    fout << inchargeof << endl;
}
 
fink::fink() : abstr_emp()
{
    reportsto = "None";
}
 
fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
}
 
fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo)
{
}
 
fink::fink(const fink & f) : abstr_emp(f)
{
    reportsto = f.reportsto;
}
 
void fink::ShowAll() const
{
    cout << "\nFink: " << endl;
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}
 
void fink::SetAll()
{
    cout << "Fink: " << endl;
    abstr_emp::SetAll();
    cout << "Reports to: ";
    getline(cin, reportsto);
}
 
void fink::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
    fin >> reportsto;
    fin.ignore();
}
 
void fink::writeall(std::ofstream &fout)
{
    fout << Fink << endl;
    abstr_emp::writeall(fout);
    fout << reportsto << endl;
}
 
highfink::highfink() : abstr_emp(), manager(), fink()
{
}
 
highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}
 
highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}
 
highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{
}
 
highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{
}
 
highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h)
{
}
 
void highfink::ShowAll() const
{
    cout << endl;
    cout << "Highfink: " << endl;
    abstr_emp::ShowAll();
    cout << "In charge of: " << manager::InChargeOf() << endl;
    cout << "Reports to: " << fink::ReportsTo() << endl;
    cout << endl;
}
 
void highfink::SetAll()
{
    cout << "Highfink: " << endl;
    abstr_emp::SetAll();
    cout << "In charge of: ";
    cin >> manager::InChargeOf();
    cin.ignore();
    cout << "Reports to: ";
    getline(cin, fink::ReportsTo());
}
 
void highfink::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
    fin >> manager::InChargeOf();
    fin.ignore();
    fin >> fink::ReportsTo();
    fin.ignore();
}
 
void highfink::writeall(std::ofstream &fout)
{
    fout << Highfink << endl;
    abstr_emp::writeall(fout);
    fout << manager::InChargeOf() << endl;
    fout << fink::ReportsTo() << endl;
}
其中setall()函数主要是从文本文件中去读取信息，而writeall()主要是把输入的信息写入到文本文件中去。实现文件开头的枚举是为了在测试文件中使用switch语句的方便。

接下来对于测试文件，题目要求第一次运行时，要求用户输入数据然后显示，并保存到一个文件中；而第二次运行时，将首先读取并显示文件中的已有信息，然后让用户添加数据，最后显示所有的数据。所以测试文件应该分三部分，第一部分打开文件并读取，第二部分添加新内容，第三部分显示所有数据，其中第一次运行时，第一部分将会跳过执行。

这里我的处理方法是首先不去新建文本文件，这样fin.is_open()函数在第一次运行时就会返回false，而之后fout.open()函数在没有该文本文件时会自动创建一个，于是第二次运行时fin.is_open()函数就会返回true了。

其他的具体操作可以看代码，测试文件17.6.cpp代码如下所示：

 
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "emp.h"
 
const int MAX = 10;
const char * file = "staff.txt";
 
int main()
{
    using namespace std;
    abstr_emp *pc[MAX];
 
    //打开文件并读取
    ifstream fin;
    int classtype;
    int i = 0;
    char ch;
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
                case Employee: pc[i] = new employee; break;
                case Manager: pc[i] = new manager; break;
                case Fink: pc[i] = new fink; break;
                case Highfink: pc[i] = new highfink; break;
                default: cerr << "Warning: Type error!\n"; break;
            }
            pc[i]->setall(fin);
            pc[i]->ShowAll();
            i++;
        }
        fin.close();
    }
 
    //添加新内容
    ofstream fout(file, ios::out | ios::app);  //打开写入，只追加
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        system("pause");
        exit(EXIT_FAILURE);
    }
    int index = 0;
    cout << "\nPlease enter the class type of your input:\n";
    cout << "1)Employee\t2)Manager\t3)Fink\t\t4)Highfink\tq)Quit\n";
    while (cin >> classtype && index < MAX)
    {
        cin.ignore();
        switch (classtype)
        {
        case 1:
            pc[index] = new employee;
            pc[index]->SetAll();
            break;
        case 2:
            pc[index] = new manager;
            pc[index]->SetAll();
            break;
        case 3:
            pc[index] = new fink;
            pc[index]->SetAll();
            break;
        case 4:
            pc[index] = new highfink;
            pc[index]->SetAll();
            break;
        default:
            cerr << "Warning: Type error!\n";
            break;
        }
        index++;
        cout << "\nPlease enter the class type of your input:\n";
        cout << "1)Employee\t2)Manager\t3)Fink\t\t4)Highfink\tq)Quit\n";
    }
    cout << "Input over.\nThank You!\n";
    cout << "Begin to write into the file...\n";
    cout << "Writing...\n";
    for (i = 0; i < index; i++)
        pc[i]->writeall(fout);
    fout.close();
    cout << "Write over.\n";
 
    //显示所有数据
    fin.clear();
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
                case Employee: pc[i] = new employee; break;
                case Manager: pc[i] = new manager; break;
                case Fink: pc[i] = new fink; break;
                case Highfink: pc[i] = new highfink; break;
                default: cerr << "Warning: Type error!\n"; break;
            }
            pc[i]->setall(fin);
            pc[i]->ShowAll();
            i++;
        }
        fin.close();
    }
 
    system("pause");
    return 0;
}
/**/