#include <iostream>
#include <array>
#include <vector>
#include <cstring>

using namespace std;

int five_one(void)
{
    int first, second;
    cout << "enter two inter number please:";
    cin >> first;
    cin >> second;
    cin.get(); //清除输入流换行符

    int swap;

    if (first > second)
    {
        swap = first;
        first = second;
        second = swap;
    }

    for (swap = 0; first <= second; first++)
    {
        swap += first;
    }

    cout << "\nsum number of you enter:\t" << swap << endl;

    return 0;
}

int five_two(void)
{
    const int Count = 100;

    array<long double, Count> aryld;
    aryld[0] = 1;

    cout << "0:" << aryld[0] << endl;
    for (int temp = 1; temp <= Count; temp++)
    {
        aryld[temp] = aryld[temp - 1] * temp;
        cout << temp << ":" << aryld[temp] << endl;
    }

    return 0;
}

int five_three(void)
{
    cout << "enter number,I can help you statistics and compute they." << endl;
    double input, sum = 0, count = 0;
    while (cin >> input && input != 0)
    {
        sum += input;
        count++;
        cout << "you enter " << count << "numbers,sum of they is: " << sum << ".\n"
             << endl;
    }

    cout << "Is done!" << endl;

    return 0;
}

int five_four(void)
{
    const int raw = 100;
    int first = raw, count = 0;
    double second = raw;
    while (second <= first)
    {
        count++;
        first += 10;
        second += (second * 0.05);
    }
    cout << "need " << count << " year." << endl;

    return 0;
}

int five_five(void)
{
    // char *month[12]={};
    const int Count = 12;
    string const month[Count] =
        {
            "january", "february", "march", "april", "may", "june",
            "july", "august", "september", "october", "november", "december"};
    int sales[Count]; // sales销售量
    int sum = 0;

    cout << "enter " << month[0] << "mouth sales." << endl;
    for (int i = 0; cin >> sales[i] && i <= Count; i++)
    {
        sum += sales[i];
        cout << "enter " << month[i] << "mouth sales." << endl;
    }

    cout << "this year sales is " << sum << "." << endl;

    return 0;
}

int five_six(void)
{
    const int Count = 12;
    string const month[Count] =
        {
            "january", "february", "march", "april", "may", "june",
            "july", "august", "september", "october", "november", "december"};
    string const year[3] = {"one", "two", "three"};
    int sales[Count][Count]; // sales销售量
    int yearsum = 0, sum[3] = {0};

    cout << "enter " << month[0] << "mouth sales." << endl;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; cin >> sales[j][i] && i <= Count; i++)
        {
            sum[j] += sales[j][i];
            cout << "enter " << month[i] << "mouth sales." << endl;
        }
        cout << year[j] << " year sales is " << sum[j] << "." << endl;
        yearsum += sum[j];
    }

    cout << "three year sales is " << yearsum << "." << endl;

    return 0;
}

int five_seven(void)
{
    struct car
    {
        string name;
        int year;
    };

    int count;
    cout << "enter how many car there are:";
    cin >> count;
    car *cars[count]; //如果这个地方不选用指针数组的话，就会直接在栈上分配一个空间用于存储
                      //这样就会使new无意义，已经有空间了，何必再从堆上分配内存
    for (int i = 0; i < count; i++)
    {
        car *p = new car;
        cin >> p->name;
        cin >> p->year;
        cars[i] = p;
    }

    for (int i = 0; i < count; i++)
    {
        cout << cars[i]->name << ':' << cars[i]->year << endl;

        delete cars[i];
    }

    return 0;

    // vector<car> cars;
    // int i = 0;
    // char t = 'y';
    // for (i; (cars[i] = new car) != NULL &&t = 'y'; i++)/错误的使用方法
    // {
    //     cout << "\nenter car name:";
    //     cin >> cars[i].name;
    //     cout << "\nenter car year of production:";
    //     cin >> cars[i].year;
    //     cout << "do you need continue? enter y or n:";
    //     cin >> t;
    //     while (cin.get() != '\n')
    //         ;
    // }

    // for (int j = 0; j <= i; j++)
    // {
    //     cout << "name:" << cars[j].name << endl;
    //     cout << "year:" << cars[j].year << endl;
    // }

    return 0;
}

int five_eight(void)
{
    // vector<char*> chary;
    // char **temp=new char*;       //错了
    // chary[0]=new char;

    // vector<char*> words;
    // char temp[100];
    // int i=0;
    // while(cin>>temp)
    // {
    //     char **p = new char*;
    //     words.back()=*p;
    //     i++;
    // }

    // char(*str)[20];
    // char temp[20];
    // cin >> temp;
    // int i = 0;
    // for (; strcmp(temp, "done"); i++)
    // {
    //     strcpy(str[i], temp);/不安全的使用方法,你不知道他会不会填充掉有用的数据
    //     cin >> temp;
    // }
    // while (cin.get() != '\n')
    //     ;
    // cout << i << "words!" << endl;

    char temp[100];
    int count = 0;
    cin >> temp;
    while (strcmp(temp, "done"))
    {
        cin >> temp;
        count++;
    }

    cout << "you enter " << count << "words!" << endl;

    return 0;
}

int five_nine(void)
{

    // vector<string> strs;
    // string temp;
    // int i=0;
    // while(cin>>temp)
    // {
    //     string *p = new string;
    //     strs.back() = *p;//特别注意将指针解引用，因为数组不是指针数组
    //     i++;
    // }

    // string *str;
    // string s;
    // cin >> s;
    // int i = 0;
    // while ("done" != s)
    // {
    //     *(str + i) = s;/不安全的使用方法,你不知道他会不会填充掉有用的数据
    //     cin >> s;
    //     i++;
    // }

    string temp;
    int count = 0;
    cin >> temp;
    while (temp != "done")
    {
        cin >> temp;
        count++;
    }

    cout << "you enter " << count << "words!" << endl;

    return 0;
}

int five_ten(void)
{
    int in;
    cin >> in;
    for (int i = 1; i <= in; i++)
    {
        for (int j = in - i; j; j--)
            cout << '.';
        for (int j = i; j; j--)
            cout << '*';
    }
    return 0;
}

int main()
{
    return 0;
}