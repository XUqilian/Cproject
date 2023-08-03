#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>

// #include<memory>


using namespace std;

struct stt
{
    string str;
    int i;
    double price;
};

bool operator<(const shared_ptr<stt> t1 ,const shared_ptr<stt> t2)
{
    if(t1->str > t2->str) return true;
    else return false;
}

bool compare(const shared_ptr<stt> t1 ,const shared_ptr<stt> t2)
{
    return t1->i < t2->i ? true : false;
}

bool comprice(const shared_ptr<stt> t1 ,const shared_ptr<stt> t2)
{
    return t1->price < t2->price ? true : false;
}

shared_ptr<stt> inpt()
{
    cout << "enter a string:";
    shared_ptr<stt> temp(new stt);
    getline(cin,temp->str);
    // while('\n' !=getchar());
    if("quit" == temp->str) return NULL;
    cout << "enter a int:";
    cin >> temp->i;
    cout << "enter price:";
    cin >> temp->price;
    while('\n' !=getchar());
    return temp;
    // st.push_back(temp);  
}

void show(const shared_ptr<stt> t)
{
    cout << t->i << '\t' << t->str << '\t' << t->price << endl;
}

bool choose(void)
{
    printf("please enter num for do something\n\
    1.display\n\
    2.according to name lower\n\
    3.according to name upper\n\
    4.according to rating lower\n\
    5.according to rating upper\n\
    6.according to price lower\n\
    7.according to price upper\n\
    other to quit.\n");
    return true;
}

int main(void)
{
    vector<shared_ptr<stt>> sst;
    shared_ptr<stt> sp;
    while(sp = inpt())
        sst.push_back(sp);
    if(sst.size() > 0)
    {   
        int play;
        while(choose() && cin >> play)
        {
            switch(play)
            {
                case(1):
                    for_each(sst.begin(),sst.end(),show);
                    continue;
                case(2):  
                    sort(sst.begin(),sst.end());              // 按重载 < 符号的函数结果排列
                    for_each(sst.begin(),sst.end(),show);
                    continue;
                case(3):  
                    sort(sst.begin(),sst.end());              // 按重载 < 符号的函数结果排列
                    for_each(sst.rbegin(),sst.rend(),show);
                    continue;
                case(4):
                    sort(sst.begin(),sst.end(),compare);     // 按指定函数结果排列
                    for_each(sst.begin(),sst.end(),show);
                    continue;
                case(5):
                    sort(sst.begin(),sst.end(),compare);     // 按指定函数结果排列
                    for_each(sst.rbegin(),sst.rend(),show);
                    continue; 
                case(6):
                    sort(sst.begin(),sst.end(),comprice);    // 随机排列
                    for_each(sst.begin(),sst.end(),show);
                    continue;
                case(7):
                    sort(sst.begin(),sst.end(),comprice);    // 随机排列
                    for_each(sst.begin(),sst.end(),show);
                    continue;   // continue 与外面循环配合 switch 只与break配合
                // default:
                //     break;
                // case(1):
                //     for(auto p : sst) show(p);               // for() other 
                //     continue;
            }
        }
    }
    else cout << "no enter" << endl; 
    
    return 0;
}


