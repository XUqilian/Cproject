#include <iostream>

using namespace std;

double seven_one(double fast, double second)
{
    double rt = 0;
    while (cin >> fast && cin >> second)
    {
        if (0 == fast && 0 == second)
        {
            cout << "you enter 0,fun is done!" << endl;
            break;
        }

        rt = 2.0 * fast * second / (fast + second);
    }

    if (cin.fail())
    {
        cout << "input error" << endl;
        cin.clear();
        while (cin.get() != '\n')
            ;
    }

    return rt;
}

int seven_two(void)
{
    cout << "enter ten times golf grades:";
    // double unsigned golf[10]={0};
    //浮点数是不能用 unsigned来规范的。unsigned 的意思就是把内存中的数据第一位也用来表示数据，而不用于表示符号位。
    //而浮点数规定内存中数据的第一位必须是符号位。因此两者之间是互相矛盾的，这也就是为什么浮点数不会有unsigned类型。
    double golf[10] = {0};

    // double *func1(golf,10);
    int i = 0;
    for (; i < 10 && cin >> golf[i]; i++)
        ;
    if (cin.fail())
    {
        cin.clear();
        while (cin.get() != '\n')
            ;
    }
    // return golf;

    // double func2(golf,i);
    double k = 0;
    int j = 0;
    while (j++ != i)
    {
        k += golf[j];
    }
    cout << k / j << endl;
    // return k/j;

    // int fun3(golf,i);
    while (i--)
        cout << golf[i] << "\t";

    return 0;
}

int seven_three(void)
{
    struct box
    {
        char makes[40];
        float height;
        float width;
        float length;
        float volume;
    };

    box i;

    // int func1(box i);
    cout << i.makes << "\t" << i.height << "\t" << i.length << "\t" << i.width << "\t" << i.volume << endl;

    // int func2(&i);
    box *j = &i;
    j->volume = j->height * j->length * j->width;

    // int func3(box i)
    // func1(i);
    // func2(&i);

    return 0;
}

int seven_four(void)
{
    //     cout<<"enter range:";
    //     int fast_range_max,fast_range_min;
    //     cin>>fast_range_max>>fast-range_min;

    //     cout<<"enter special range:";
    //     int last_range_max,last_range_min;
    //     cin>>last_range_max>>last_range_min;

    int cnt, rangemax, special; //次数 最大范围 特殊范围
    cout << "enter times and range max and special range:";
    cin >> cnt >> rangemax >> special;
    if (cnt > rangemax)
    {
        cout << "enter error!" << endl;
        exit(EXIT_FAILURE);
    }
    double rt = 0;
    while (cnt)
    {
        rt *= (rangemax-- / cnt--);
    }
    rt *= (1 / special);

    return 0;
}

int seven_five(int temp)
{
    long long sum = 1;
    while (temp)
        sum *= temp--;
    cout << sum;
    return 0;
}

int seven_six(void)
{
    int size;
    double ary[size];

    // func1(ary,size)
    int i = size;
    while (i-- >= 0 && cin >> ary[i])
        ;
    if (cin.fail()) //直接把cin当条件也可以
    {
        cout << "enter error!" << endl;
        cin.clear();
        while (cin.get() != '\n')
            ;
    }
    int back = size - i + 1;

    // func2(ary,back)
    while (back--)
        cout << ary[back] << '\t';

    // func3(ary ,back)
    back = size - i + 1;
    int j = size - back; // int j=0;不能符合最后调用，故更换
    while (back > j)
    {
        double temp;
        temp = ary[j++];
        ary[j] = ary[--back];
        ary[back] = temp;
    }

    // func1
    // func2
    // func3
    // func2
    // func3(ary,back-1)

    return 0;
}

int seven_seven(double *ary, double *tail)
{
    double *head = ary;
    double *temp;

    // double* func1(double *ary,double *tail)
    while (head != tail && cin >> *(head++))
        temp = head - 1;
    if (cin.fail()) //直接把cin当条件也可以
    {
        cout << "enter error!" << endl;
        cin.clear();
        while (cin.get() != '\n')
            ;
    }
    // temp

    // func2(double *ary,double *tail)
    head = ary;
    while (head++ != temp)
        cout << *head << '\t';

    // func3(double *ary,double *tail)
    double mul;
    head = ary;
    cout << "enter multiple:";
    cin >> mul;
    while (head++ != temp)
        *head *= mul;

    return 0;
}

int seven_eight(void)
{
    const char *chs[4] = {"1", "2", "3", "4"};
    int size;
    cin >> size;
    double ary[size];

    struct temp
    {
        char name[10] = {0};
        double num;
    };

    // func1(ary,size)
    int i = size;

    while (i-- >= 0 && cin >> ary[i])
        cout << chs[i] << ary[i] << endl;
    if (cin.fail()) //直接把cin当条件也可以
    {
        cout << "enter error!" << endl;
        cin.clear();
        while (cin.get() != '\n')
            ;
    }
    int back = size - i + 1;

    // func2(ary,back)
    double cnt;
    while (back--)
        cnt += ary[back];
    cout << chs[back] << endl;

    temp tp[size - i + 1];
    // while (++back != (size - i + 1))
    // {
    //     tp[back].name = chs[back];
    //     tp[back].num = ary[back];
    // }

    for (back; ++back != (size - i + 1);)
    {

        tp[back].num = ary[back];
        // tp[back].name = chs[back];  //name是一个数组，数组是不能被赋给数组的只能一个一个element赋值
        for (int j = 0; ary[j]; j++)
            tp[back].name[j] = chs[back][j];
    }

    return 0;
}

int seven_nine(void)
{
    const int Slen = 30;
    struct stu
    {
        char fullname[Slen];
        char hobby[Slen];
        int ooplevel;
    };
    int num; // stu个数
    stu stu_tp[num];

    // getinfo(stu_t,num)
    int i = num;
    while (i--)
        cin >> stu_tp[i].fullname >> stu_tp[i].hobby >> stu_tp[i].ooplevel;
    // if(!cin) exit();

    // display1(stu_tp[1])
    cout << stu_tp[1].fullname << stu_tp[1].hobby << stu_tp[1].ooplevel << endl;

    // display2(stu_tp)
    cout << stu_tp[1].fullname << stu_tp[1].hobby << stu_tp[1].ooplevel << endl;

    // display3(const stu stu_tp,int i)
    while (++i != num)
        cout << stu_tp[i].fullname << stu_tp[i].hobby << stu_tp[i].ooplevel << endl;

    return 0;
}

double seven_ten_o(double x, double y, double (*pf)(double, double))
{
    return pf(x, y);
}
double (*seven_ten_s[4])(double, double); //创建4个同返回类型同参数的函数 分管加减乘除
int ten(void)
{
    // double seven_ten_o(double x,double y,double (*seven_ten_s[1])(double,double));
    // double seven_ten_o(double x,double y,double (*seven_ten_s[2])(double,double));
    // double seven_ten_o(double x,double y,double (*seven_ten_s[3])(double,double));
    // double seven_ten_o(double x,double y,double (*seven_ten_s[4])(double,double));
    double x, y;

    for (int i = 0; i < 4; i++)
        // double seven_ten_o(double x, double y, double (*seven_ten_s[i]));
        // double seven_ten_o(double x,double y,double (*seven_ten_s[i])(double,double));
        seven_ten_o(x, y, *seven_ten_s[i]); //调用函数居然加返回类型不是傻吗？真亏了自己

    return 0;
}

int main(void)
{
    return 0;
}