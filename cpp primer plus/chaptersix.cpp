#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
//#include<array>

using namespace std;

int six_one(void)
{
    // int temp;
    // cin >> temp;
    // while (char(temp) != '@') //可有可无的类型转换
    // {
    //     if (isupper(temp))
    //         cout << tolower(temp);
    //     else if (islower(temp))
    //         cout << toupper(temp);
    //     else
    //         cout << temp;
    // }

    char temp;
    while(cin>>temp && temp!='@')
    {
        if(isdigit(temp))
            continue;
        else if(isupper(temp))
            cout<<tolower(temp);
        else if(islower(temp))
            cout<<toupper(temp);
        else
            cout<<temp;
    }
    return 0;
}

int six_two(void)
{
    const int Cnt = 10;
    double ary[Cnt] = {0};
    //double ary[Cnt];
    int i = 0;
    int temp=0;

    // cin>>temp;
    // for(;isdigit(temp) && i<Cnt;i++)
    // {
    //     ary[i]=temp;
    //     cin>>temp;
    // }   /有问题,cin 获取不同类型数据时会出现什么现象,用 isdigit 不适合

    //for (; cin >> ary[i] && i < Cnt; i++)
    while(cin >> ary[i] && i < Cnt)
        temp+=ary[i++]; // cin 遇到不符合类型的输入时会返回 false
    //循环后 i 和输入数量一致,因为 i 在每一次循环后都会增加
    
    cout << "have " << i << "digit" << endl;
    
    // int j = i;
    // while (j--)
    // {
    //     temp += ary[j] / i;
    // }

    int j=i;
    int cnt = 0;
    while(ary[--j])
    {
        if(ary[j] > (temp/i))
            cnt++;
    }

    cout << "average is " << temp / i <<",\nhave " << cnt <<"big." << endl;

    return 0;
}

int six_three(void)
{

    char input;
    while (1) // use "break" to end the loop.
    {
        cout << "please enter one of following choices:" << endl;
        cout << "a) carnivore\t\tb) pianist\nc) teee\t\td) game\nq) quit" << endl;
        cout << "please enter a b c d or q:";
        cin >> input;
        switch (input)
        {
        case ('a'):
            cout << "\na maple is carnivore." << endl;
            continue;
        case ('b'):
            cout << "\na maple is pianist." << endl;
            continue;
        case ('c'):
            cout << "\na maple is tree" << endl;
            continue;
        case ('d'):
            cout << "\na maple is game." << endl;
            continue;
        case ('q'):
            cout << "\ngoodbye!" << endl;
            break;
        defaule:
            cout << "\nplease enter same as these." << endl;
        }
    }
    return 0;
}

int six_four(void)
{
    int const Strsize = 100;
    struct bop
    {
        char fullname[Strsize];
        char title[Strsize];
        char bopname[Strsize];
        int prefrence; // 0:fullname 1:title 2:bopname
    };

    int num_of_ary; // let 让 user dicesion 决定 number of people.
    cout << "enter number of people: ";
    cin >> num_of_ary;
    //添加错误输入测试
    bop peopnum[num_of_ary]; // accroding to user enter

    for (int i = 0; i < num_of_ary; i++)
    {
        cout << "\nwhat is you fullname:";
        cin >> peopnum[i].fullname;
        cout << "\nwhat is you bopname:";
        cin >> peopnum[i].bopname;
        cout << "\nwhat is you title:";
        cin >> peopnum[i].title;
        cout << "\nwhat is you prefrence:";
        cin >> peopnum[i].prefrence;
    }

    //根据输入确定输出内容
    char label;
    cout << "a)display by fullname\t\tb)display by title\nc)display by bopname\t\td)bisplay by prefrence\nq)quit" << endl;
    while (cin >> label)
    {
        switch (label)
        {
        case ('a'):
            for (int i = 0; i < num_of_ary; i++)
                cout << peopnum[i].fullname << endl;
            cout << "next choice:";
            continue;
        case ('b'):
            for (int i = 0; i < num_of_ary; i++)
                cout << peopnum[i].title << endl;
            cout << "next choice:";
            continue;
        case ('c'):
            for (int i = 0; i < num_of_ary; i++)
                cout << peopnum[i].bopname << endl;
            cout << "next choice:";
            continue;
        case ('d'):
            for (int i = 0; i < num_of_ary; i++)
            {
                switch (peopnum[i].prefrence)
                {
                case (0):
                    cout << peopnum[i].fullname << endl;
                    break;
                case (1):
                    cout << peopnum[i].title << endl;
                    break;
                case (2):
                    cout << peopnum[i].bopname << endl;
                    break;
                }

                // if (0 == peopnum[i].prefrence)
                //     cout << peopnum[i].fullname << endl;
                // if (1 == peopnum[i].prefrence)
                //     cout << peopnum[i].title << endl;
                // if (2 == peopnum[i].prefrence)
                //     cout << peopnum[i].bopname << endl;
            }
            cout << "next choice:";
            continue;
        case ('q'):
            cout << "goodbye!";
            break;
        default:
            cout << "please enter right options.\nnext choice:";
        }
    }
    return 0;
}

int six_five(void)
{
    double revenue; //收入
    double rate;    //税率
    while (cin >> revenue && revenue > 0)
    {

        // if (revenue <= 5000)
        //     rate = 0;
        // if (revenue > 5000 && revenue <= 1500)
        //     rate = (revenue - 5000) * 0.1;
        // if (revenue > 1500 && revenue <= 3500)
        //     rate = (1000 * 0.1) + (revenue - 1500) * 0.15;
        // if (revenue > 3500)
        //     rate = (1000 * 0.1) + (2000 * 0.15) + (revenue * 0.2);



        if (revenue <= 5000)
            rate = 0;
        else if (revenue <= 1500)
            rate = (revenue - 5000) * 0.1;
        else if (revenue <= 3500)
            rate = (1000 * 0.1) + (revenue - 1500) * 0.15;
        else
            rate = (1000 * 0.1) + (2000 * 0.15) + (revenue * 0.2);
    }
    return 0;
}

int six_six(void)
{
    struct donors //捐款人
    {
        string name;
        double money;
    };

    cout << "please enter how many people donation:";
    int people;
    cin >> people;
    donors *dons[people];

    for (int i = 0; i < people; i++)
    {
        dons[i] = new donors;
        //需要增加空间分配检测
        cout << "\nplease enter donors name:";
        cin >> dons[i]->name;
        cout << "\nplease enter " << dons[i]->name << "donation moneys:";
        cin >> dons[i]->money;
    }

    bool tag=true;

    cout << "\ngrand patrons\n";
    for (int i = 0; i < people; i++)
    {
        if (dons[i]->money > 1000)
        {
            cout << "name:" << dons[i]->name << "\t\tmoney:" << dons[i]->money << endl;
            tag=false;
        }    
    }
    if(tag) 
        cout<<"done!"<<endl;
    
    cout << "\nother patrons\n";
    for (int i = 0; i < people; i++)
    {
        if (dons[i]->money <= 1000)
        {
            cout << "name:" << dons[i]->name << "\t\tmoney:" << dons[i]->money << endl;
            tag=false;
        }   
    }
    if(tag) 
        cout<<"done!"<<endl;
    
    for (int i = 0; i < people; i++)
        delete dons[i]; //释放堆上的存储空间

    return 0;
}

int six_seven(void)
{
    string words;
    int vowel = 0, consonant = 0, other = 0; // vowel 元音  consonant 辅音
    // while (cin >> words)                     // cin>> 会遇到空格等停止读入 ,cin.getline() 不会
    // {
    //     if (words[0] == 'q' && words[1] == '\0')
    //         break;

    //     if ('a' == words[0] || 'e' == words[0] || 'i' == words[0] || 'o' == words[0] || 'u' == words[0])
    //         vowel++;
    //     else if (isalpha(words[0]))
    //         consonant++;
    //     else
    //         other++;
    // }

    while((cin>>words) && (words!="q"))
    {
        if(isalpha(words[0]))
        {
            switch(words[0])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowel++;
                default:
                    consonant++;
                    break;
            }
        }else 
            other++;
    }
    return 0;
}

int six_eight(void)
{
    ifstream file; //以只读方式打开
    string name;
    int cnt = 0;
    char t;

    cout << "enter the file path, filename and suffix:"; // suffix 后缀
    getline(cin, name);                                   //注意观看函数参数
    file.open(name);
    if (!file.is_open())
        exit(EXIT_FAILURE); //没有打开文件检测

    while (file.get(t))
    {
        //if()
        cnt++;
    }
        

    if (file.eof())
        cout << name << "have " << cnt << "words." << endl;
    else
        cout << "have unknow error!!!" << endl; // file.fail()

    file.close();

    return 0;
}

int six_nine(void)
{
    struct donors //捐款人
    {
        string name;
        double money;
    };

    ifstream file; //以只读方式打开
    string name;   //获取文件名
    int people;    //获取捐款人数

    cout << "enter the file path, filename and suffix:"; // suffix 后缀
    getline(cin, name);                                   //注意观看函数参数 io,string
    file.open(name);                                      //打开文件
    if (!file.is_open())
        exit(EXIT_FAILURE); //没有打开文件检测

    file >> people; //获取第一行的人数
    file.get();
    if(people>0)
    {
        donors *dons[people]; //创建结构指针数组用于存储

        for (int i = 0; i < people; i++)
        {
            dons[i] = new donors;
            //需要增加空间分配检测

            getline(file,dons[i]->name); //获取人名行信息
                //遇到空格切换 
            // getline(file,dons[i]->name);              //遇到换行切换
            file >> dons[i]->money; //获取金额行信息
            // getline(file,dons[i]->money);
            file.get();
        }

        cout << "\ngrand patrons\n";
        for (int i = 0; i < people; i++)
        {
            if (dons[i]->money > 1000)
                cout << "name:" << dons[i]->name << "\t\tmoney:" << dons[i]->money << endl;
        }

        cout << "\nother patrons\n";
        for (int i = 0; i < people; i++)
        {
            if (dons[i]->money <= 1000)
                cout << "name:" << dons[i]->name << "\t\tmoney:" << dons[i]->money << endl;
        }

        for (int i = 0; i < people; i++)
            delete dons[i]; //释放堆上的存储空间
        // delete[] dons;   错误的方法,因为 dons 并不是动态分配的,它的元素才是
    }
    
    file.close(); //关闭文件

    return 0;
}

int main(void)
{
    return 0;
}