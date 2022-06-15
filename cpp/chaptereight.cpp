#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/////// no_one
// void showstr(const char *buf)
// {
//     while(*buf)
//     {
//         putchar(*buf);
//         buf++;
//     }
//     cout<<endl;//putchar('\n');
// }

// void showstr(const char *buf,int cnt=one_cnt)
// {
//     one_cnt++;
// while(cnt--)
// {
//     while(*buf)
//     {
//         putchar(*buf);
//         buf++;
//     }
//     cout<<endl;//putchar('\n');

// }

// }

void showstr(const char *buf, int cnt = 0)
{
    static int one_cnt = 0; //将其限制在本函数 内部静态存储区 静态变量不会因为多次调用被重新赋值
    one_cnt++;

    int oc = one_cnt;

    if (!cnt)
    {
        putchar(*buf);
        buf++; //也可以用for思路就是指向下一位置
    }
    else
    {
        int oc = one_cnt;
        while (oc--)
        {
            while (*buf)
            {
                putchar(*buf);
                buf++;
            }
            cout << endl; // putchar('\n');
        }
    }
}

////////  no_two

//少用c++多用c

struct stt
{
    char *sttname;
    double weight;
    int heat;
};

void getstt(stt &st, char *buf = "millennium munch", double wt = 2.85, int ht = 350)
{
    st.sttname = buf;
    st.weight = wt;
    st.heat = ht;
}

void showstt(const stt &st)
{
    // int i=0;
    // while(st.sttname[i])
    //     putchar(st.sttname[i++]);
    // putchar('\n');
    puts(st.sttname);
    putchar('\n');
    printf("%f \t  %d", st.weight, st.heat);
}

///////no.three

void upstr(string &str)
{
    for (int i = 0; str[i] != '\0'; i++) // Ansic码 0:32 \0:48  0:48
    {
        str[i] = toupper(str[i]);
    }

    cout << str;
}

/////////no.four
struct stringy
{
    char *str; //字符串
    int ct;    //字符串长度
};

void set(stringy &stry, const char *s)
{
    // 从堆上获取一块与传入字符串大小相同的内存并将传入字符串存入
    // 将这块内存地址赋给结构成员str
    // 设置成员ct

    int i = 0;
    while (s[i++] != '\0')
        ;                   //获取字符串大小
    stry.str = new char(i); //获取一个刚好适合的空间大小
    //勿忘delete[]

    strcpy(stry.str, s); // copy字符串
    stry.ct = i;
}

void showstr(const stringy *stry, int times = 1)
{
    if (times > -1)
        while (times--)
            puts(stry->str);
}

void showstr(const char *str, int times = 1)
{
    if (times > -1)
        while (times--)
            puts(str);
}

//模板可免去冗余代码
// template <typename T> void showt(T & str,int times)   //不行，结构需要使用成员符号

////////no.five

template <typename T>
T max(T ary[])
{
    int i = 5;
    T temp;

    while (i--)
    {
        if (ary[i] > temp)
            temp = ary[i];
    }

    return temp;
}

/////////no.six

template <typename T>
T maxn(T ary[], int i)
{
    T temp;

    while (i--)
    {
        if (ary[i] > temp)
            temp = ary[i];
    }

    return temp;
}

template <>
char *maxn<char *>(char *ary[], int i)
{
    char *temp;

    while (i--)
    {
        if (strcmp(ary[i], temp) > 0)
            strcpy(temp, ary[i]);
    }

    return temp;
}

////////no.seven

struct sttt
{
    char *name[50];
    double f;
};

template <typename T>
T sumarray(T ary[], int times)
{
    T temp = 0;
    while (times--)
        temp += ary[times];
    return temp;
}

template <typename T>
double sumarray<sttt>(sttt ary[], int times)
{
    double temp = 0;
    while (times--)
        temp += ary[times].f;
    return temp;
}
