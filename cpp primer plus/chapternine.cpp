//编写程序时能使用 c 语法便用 c 语法 (快速响应),但如果复杂就转用 c++
//能不用 using 编译指令 (using namespace ...) 就不用，保证后期兼容性与拓展性，多使用 using 声明 (using std::cin)
//或者直接引入 std::cin

#include <iostream>
#include <string>
#include <string.h>
#include <new>

/////////////////////////////////////////////////////////////////////
////////no.one
////////

// file1
const int Len = 40;
struct golf
{
    char fname[Len];
    int handicp;
};
void setgolf(golf &, char *, int);
int setgolf(golf &);
void handicp(golf &, int);
void showgolf(const golf &);

// file2

//#include"file1.h"  //将头文件 file1 导入
void setgolf(golf &g, char *name, int hc)
{
    strncpy(g.fname, name, Len);
    g.handicp = hc;
}

int setgolf(golf &g)
{
    get_s(g.fname);
    scanf("\t%d", &g.handicp);
}

void handicp(golf &g, int hc)
{
    scanf("\t%d", &g.handicp);
}

void showgolf(const golf &g)
{
    puts(g.fname);
    printf("\t%d", g.handicp);
}

// file3

//#include"file1.h"  //导入头文件 file1
int main_one()
{
    golf aryg[5];
    char str[50];
    int temp;

    for (int i = 4; i; i--)
    {
        get_s(str);
        if (strlen(str))  //str[1] != '\0'
        {
            scanf("%d", temp);
            setgolf(aryg[i], str, temp);
        }
        else
            break;
    }
}

///////no.two

void sumstr(const std::string &str) //使用了域符号
{
    static int sum = 0;
    sum += str.length();
    printf("%d\t%d\t%d", str.length(), sizeof(str), sum); //附带看一下 sizeof 的大小
}

///////////////////////////////////////////////////////////////////////////////////
///////////no.three
///////////

static char buf[1024];

struct chaff
{
    char dross[20];
    int slag;
};

inline void setchaff(chaff &stc, const char *str, int size) //结构简单且调用频繁，使用 inline 将其定为内联函数
{
    strcpy(stc.dross, str);
    stc.slag = size;
}

int mainthree()
{
    chaff *p1 = new chaff;
    chaff *p2 = new (buf) chaff;
    chaff *p3 = new (buf + sizeof(chaff)) chaff;

    setchaff(*p1, "hello", 5);
    setchaff(*p2, "world", 5);
    setchaff(*p3, "every", 5);

    delete p1;

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
// ////////no.four
///////////

// file1
namespace sales_ns
{
    const int Quarters = 4;
    struct sales_st
    {
        double sales_d[Quarters];
        double average;
        double max;
        double min;
    };

    void setsales_st(sales_st &s, const double ar[], int n);

    void setsales_st(sales_st &s);

    void display(const sales_st &s);
}

// file2
namespace sales_ns
{
    // uninteraction version  非交互版本
    void setsales_st(sales_st &s, const double ar[], int n)
    {
        int num = Quarters > n ? n : Quarters;
        s.max = s.min = ar[num - 1];
        s.average = 0;
        for (int i = num - 1; i >= 0; i--)//(int i = num ; i-- ; )
        {
            s.sales_d[i] = ar[i];
            s.average += s.sales_d[i] / Quarters;
            if (s.sales_d[i] > s.max)
                s.max = s.sales_d[i];
            if (s.sales_d[i] < s.min)
                s.min = s.sales_d[i];
        }
        for(int i = num ; i < Quarters ; i++ )
        {
            s.sales_d[i] = 0 ;
            // if (s.sales_d[i] > s.max)
            //     s.max = s.sales_d[i];
            // if (s.sales_d[i] < s.min)
            //     s.min = s.sales_d[i];
        }
    }

    // interactive version 交互版本
    void setsales_st(sales_st &s)
    {
        s.max = s.min = s.average = 0 ;
        for (int i = Quarters - 1; i >= 0; i--)
        {
            scanf("%f\t", &s.sales_d[i]);
            s.average += s.sales_d[i] / Quarters;
            if (0 == s.max && 0 == s.min)    //if (i == Quarters - 1)
                s.max = s.min = s.sales_d[i];
            else
            {
                if (s.sales_d[i] > s.max)
                    s.max = s.sales_d[i];
                if (s.sales_d[i] < s.min)
                    s.min = s.sales_d[i];
            }
        }
        // scanf("\naverage:%f\nmax:%f\nmin:%f\n",&s.average,&s.max,&s.min);
    }

    void display(const sales_st &s)
    {
        for (int i = Quarters; i; i--)
            printf("%f\t", s.sales_d[i]);
        printf("\naverage:%f\nmax:%f\nmin:%f\n", s.average, s.max, s.min);
    }
}

// file3
int main_four()
{

    sales_ns::sales_st x, y;
    double ar[sales_ns::Quarters] = {1, 2, 3, 4};
    sales_ns::setsales_st(x);
    sales_ns::setsales_st(y, ar, 4);

    return 0;
}
