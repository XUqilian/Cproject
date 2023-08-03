#include<iostream>
#include<string>
#include<memory>
#include<algorithm>
#include<iterator>
#include<list>
#include<vector>
#include<set>
#include<map>

// 模板使算法不受数据类型限制 泛型编程使算法不受数据结构限制

using namespace std;

template<class T>
void outpt(const T & t)
{
    cout << t << ' ' ;
}

void outmap(pair<const string,int> t)   // template <> void outpt<map<string,int>>(map<string,int> & t)   这传进来的还是一个map 还得改进
{           // 这个是键得用const 要不然出错
    cout << t.first << " " << t.second << endl;
}

string & tolow(string & t)
{
    for(int i = 0 ; i < t.size() ; i++)
    {
        t[i] = (char)tolower(t[i]);
    }
    return t;
}

//***************
char toLow(char ch)
{
    return tolower(ch);
}

string & ToLow(string & t)
{
    transform(t.begin(),t.end(),t.begin(),toLow);
    return t;
}
//********************


int main(void)
{
    {
        string temp;
        cout << "enter a string." << endl;
        while (cin >> temp && temp != "quit")
        {
            sort(temp.begin(),temp.end());
            while(next_permutation(temp.begin(),temp.end()))
            {    
                for_each(temp.begin(),temp.end(),outpt<char>);
                cout << endl;
            }
            cout << endl;
            cout << "please enter another string ,quit to quit." << endl;
        }
    }
    {
        int ar1[10]{50 ,100,60,180,60,210,415,60,188,201};
        list<int> ls1(ar1,ar1+10);
        list<int> ls2(ls1);
        for_each(ls1.begin(),ls1.end(),outpt<int>);
        cout << endl;
        ls1.remove(60);
        cout << "remove 60: ";
        for_each(ls1.begin(),ls1.end(),outpt<int>);
        cout << endl;
        list<int>::iterator it;
        it = remove(ls2.begin(),ls2.end(),60);
        cout << "remove 60: ";
        for_each(ls2.begin(),ls2.end(),outpt<int>);
        cout << endl;
        ls2.erase(it,ls2.end());
        cout << "now remove 60: ";
        for_each(ls2.begin(),ls2.end(),outpt<int>);
        cout << endl;
    }
    {
        {
            string words;
            vector<string> sarr;
            // vector<string> sarr{"hello" , "what" , "is" , "your" , "name" , "what" ,"is" ,"your" , "address"};
            while(cin>> words && words != "quit")
                sarr.push_back(words);
            for_each(sarr.begin(),sarr.end(),outpt<string>);
            cout << endl;

            // vector<string> sar;
            // copy(sarr.begin(),sarr.end(),insert_iterator<vector<string>>(sar,sar.begin())); //这里直接push_back()就好了吧
            // transform(sarr.begin(),sarr.end(),sar.begin(),sort);

            vector<string> sar(sarr);
            transform(sar.begin(),sar.end(),sar.begin(),tolow);
            sort(sar.begin(),sar.end());    //
            for_each(sar.begin(),sar.end(),outpt<string>);
            cout << endl;

            map<string,int> smap;
            for(int i = 0 ; i < sar.size() ; i++)
                smap.insert(pair<string,int>(sar[i],smap[sar[i]]++ ));     // count方法不能增加 +1也不行 只能++  

            for_each(smap.begin(),smap.end(),outmap);    
            // for(auto x : smap)  // 遍历map方法好像只有这种 再加上利用map迭代器. 来使用
            //     cout << x.first << ' ' << x.second << endl;

            cout << endl;
        }
        {   // 比较一下感觉它这个还没我上面那个写的好
            string words;
            vector<string> sarr{"hello" , "what" , "is" , "your" , "name" , "what" ,"is" ,"your" , "address"};
            // vector<string> sarr;
            // while(cin>> words && words != "quit")
            //     sarr.push_back(words);
            for_each(sarr.begin(),sarr.end(),outpt<string>);
            cout << endl;

            set<string> sar;
            transform(sarr.begin(),sarr.end(),insert_iterator<set<string>>(sar,sar.begin()),tolow);
            for_each(sar.begin(),sar.end(),outpt<string>);
            cout << endl;
            map<string,int> smap;
            for(set<string>::iterator it = sar.begin() ; it !=sar.end() ; it++)
                smap[*it] = count(sarr.begin(),sarr.end(),*it);

            for(pair<const string,int> & x : smap)  //for(auto x : smap)
                cout << x.first << ' ' << x.second << endl;
            
            for(map<string,int>::iterator it = smap.begin() ; it !=smap.end() ; it++)
                cout << (*it).first << ' ' << it->second << endl;   // 可以使用* 或者使用->  
            
        }
        
    }
    return 0;
}