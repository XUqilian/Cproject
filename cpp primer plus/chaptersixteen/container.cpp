#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<valarray>


// #include<memory>


using namespace std;

struct stt
{
    string str;
    int i;
};

bool operator<(const stt & t1 ,const stt & t2)
{
    if(t1.str > t2.str) return true;
    else if(t1.str == t2.str) 
        return t1.i < t2.i ? true : false;
    else return false;
}

bool compare(const stt & t1 ,const stt & t2)
{
    return t1.i < t2.i ? true : false;
}

bool ipt( stt & temp)
{
    cout << "enter a string:";
    getline(cin,temp.str);
    // while('\n' !=getchar());
    if("quit" == temp.str) return false;
    cout << "enter a int:";
    cin >> temp.i;
    while('\n' !=getchar());
    return true;
    // st.push_back(temp);  
}

void show(const stt & t)
{
    cout << t.i << '\t' << t.str << endl;
}

int main(void)
{
    {
        // vector<string> strarr(5);   // 初始化方法多样
        vector<string> strar = {"one " , "two" , "three" , "four" ,"five"};

        vector<int> intar = { 1,2,3,4,5};

        for(int i = 0 ; i < 5 ; i ++) cout << intar[i] << "\t" << strar[i] << endl;
    }    


    {   // 容器提供迭代器实现 算法通过迭代器完成对容器的操作
        vector<double> intar = { 1,2,3,4,5};
        vector<double> :: iterator pi;      // 创建一个迭代器 

        pi = intar.begin() ; // begin() 返回容器第一个位置的迭代器 end()返回超尾位置迭代器,该迭代器因不属于容器内所以无法操作
        *pi = 10;
        cout << intar[0] << " use iterator " << *pi << endl;
    }

    {
        vector<stt> st;
        
        while(true)
        {
            stt temp;
            cout << "enter a string:";
            getline(cin,temp.str);
            // while('\n' !=getchar());
            if("quit" == temp.str) break;
            cout << "enter a int:";
            cin >> temp.i;
            while('\n' !=getchar());

            st.push_back(temp);              
        }
        if(st.size() > 0)
        {
            cout << "use point" << endl;
            for(int i = 0 ; i < st.size() ; i++ ) cout << st[i].i << '\t' << st[i].str << endl;
            cout << "use iterator" << endl;
            vector<stt>::iterator p;
            for(p = st.begin() ; p < st.end() ; p++) cout << (*p).i << '\t' << (*p).str << endl;
            vector<stt> oldst(st);
            if(st.size() > 3)
            {
                st.erase(st.begin() + 1 ,st.begin() + 3);
                for(p = st.begin() ; p < st.end() ; p++) cout << (*p).i << '\t' << (*p).str << endl;
                st.insert(st.begin(),oldst.begin() +1 ,oldst.begin() + 3);
                for(p = st.begin() ; p < st.end() ; p++) cout << (*p).i << '\t' << (*p).str << endl;
            }
            st.swap(oldst);
            for(p = st.begin() ; p < st.end() ; p++) cout << (*p).i << '\t' << (*p).str << endl;
        }
        else cout << "no enter" << endl;
    }

    {
        vector<stt> st; 
        stt temp;
        while(ipt(temp))
            st.push_back(temp);
        if(st.size() > 0)
        {
            for_each(st.begin(),st.end(),show);
            cout << "use sort" << endl;
            sort(st.begin(),st.end());              // 按重载 < 符号的函数结果排列
            for_each(st.begin(),st.end(),show);
            cout << "compare i" << endl;
            sort(st.begin(),st.end(),compare);      // 按指定函数结果排列
            for_each(st.begin(),st.end(),show); 
            cout << "use random_shuffle" << endl;
            random_shuffle(st.begin(),st.end());    // 随机排列
            for_each(st.begin(),st.end(),show);
            
            for(auto p : st) show(p);               // for() other 
        }
        else cout << "no enter" << endl;
    }

    {
        const int Num = 12;
        valarray<double> valarr(Num);
        for(int i = 0 ; i < Num ; i++)
            valarr[i] = rand() % 10;
        // valarray<bool> vbar = valarr > 5;   // why cant
        for(double x : valarr) cout <<  x << ' ';
        cout << endl;
        valarray<double> valar(valarr[slice(1,4,3)]);
        for(double x : valar) cout <<  x << ' ';
        cout << endl;
        valarr[slice(2,4,3)] = 10;
        for(double x : valar) cout <<  x << ' ';
        cout << endl;
    }

    {

    }
    return 0;
}


