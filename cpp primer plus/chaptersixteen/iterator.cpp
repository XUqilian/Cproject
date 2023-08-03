#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<list>
#include<set>
#include<map>


// STL 容器 迭代器 算法 函数对象
// 容器     deque、list、queue、priority_queue、stack、vector、map、multimap、set、multiset和bitset（这个是在比特级处理数据的容器）。C++11新增了forward_list、unordered_map、unordered_multimap、unordered_set和unordered_multiset
// 迭代器   输入迭代器input iterator 输出迭代器output iterator   前向迭代器forward iterator   双向迭代器bidirectional iterator   随机访问迭代器random-access iterator
// 函数对象 重载了括号操作符()的类函数
// 算法     常用遍历算法  for_each   transform     常用查找算法   find   find_if   adjacent_find  binary_find   count   count_if    常用排序算法  sort  random_shuffle  merge   reverse   常用的替换算法  swap  replace  replace_if    常用集合算法   set_intersection  set_ union  set_ difference  常用的算术生成算法  accumulate  fill

// 迭代器 作为算法与容器之间的耦合器   让容器能够通过迭代器使用算法
// 函数对象 C++ 标准库主要使用函数对象作为容器和算法内的排序条件。相对于直接函数调用，函数对象有两个优势。 第一个是函数对象可包含状态。 第二个是函数对象是一个类型，因此可用作模板参数。

using namespace std;
/*
struct STT
{
    string str;
    STT * next;
};

class iterator      
{
    // 将此模块内嵌入容器类内部public达到 '容器<..>::iterator' 并且用其生成对象 用对象对容器数据操作 功能实现于类的成员函数

    //      迭代器类型                     容器---算法                成员函数实现功能(通用:迭代器是否相等（==、!=）前置和后置递增运算（++）读取元素的解引用运算符（*）。只能读元素，也就是解引用只能出现在赋值运算符的右边。箭头运算符（->），解引用迭代器，并提取对象的成员。)
    // 输入迭代器input iterator             容器输入(cin)到算法         利用迭代器进行读取 用于单遍扫描算法         只读
    // 输出迭代器output iterator            输出(cout)到容器            利用迭代器进行写入 单遍扫描算法             只写
    // 前向迭代器forward iterator           输出输入                    利用迭代器进行写和读 多遍扫描算法
    // 双向迭代器bidirectional iterator     输出输入                    利用迭代器进行写和读 多遍扫描算法 前置和后置递减运算（- -）,这意味这它能够双向访问
    // 随机访问迭代器random-access iterator 输出输入                    利用迭代器进行写和读 前置和后置递减运算（- -） 比较两个迭代器相对位置的关系运算符（<、<=、>、>=）支持和一个整数值的加减运算（+、+=、-、-=）迭代器上的减法运算符（-），得到两个迭代器的距离 支持下标运算符（iter[n]），访问距离起始迭代器n个距离的迭代器指向的元素 能用于多遍扫描算法。 在支持双向移动的基础上，支持前后位置的比较、随机存取、直接移动n个距离
    
    private:
        STT * t;
    public:
        iterator() : t(0) {}
        iterator(STT * st) : t(st) {}

        iterator & operator++(){}   // 前缀 进行过运算 可返回引用
        iterator operator++(int){}  // 后缀 已经进行过运算 返回旧对象参数是临时所以不能返回引用
        STT & operator*(){}         // 解引用 用于将内容展现出来
};
*/

void outstr(string & t) { cout << t << endl;}
void outint(int t) {cout << t << ' ';}
int main(void)
{
    /* 基本容器 vector list ... */
    {
        int ar[10] = {1,2,3,4,5,6,7,8,9,0};
        vector<int> var(10);
        copy(ar,ar+10,var.begin());
        ostream_iterator<int ,char> opt(cout , " ");
        copy(ar,ar+10,opt);
        copy(ar,ar+10,ostream_iterator<int ,char> (cout , " "));

        copy(var.begin(),var.end(),var.begin());
        vector<int>::iterator p;
        for(p = var.begin() ; p != var.end(); p++)
            cout << *p << endl;
    }
    {
        string s1[4] = {"one", "two" , "three" ,"four"};
        string s2[2] = {"five","six" };
        string s3[2] = {"seven","eight"};

        vector<string> dic(4);
        copy(s1,s1+4,dic.begin());
        for_each(dic.begin(),dic.end(),outstr);      // use arg3 func
        cout  << endl;
        copy(s2,s2+2,back_insert_iterator<vector<string>> (dic));
        for_each(dic.begin(),dic.end(),outstr);
        // for_each(dic.begin(),dic.end(),ostream_iterator<string,char>(cout , " "));      // use arg3 iterator
        cout << endl;
        copy(s3,s3+2,insert_iterator<vector<string>> (dic,dic.begin()));
        for_each(dic.begin(),dic.end(),outstr);

        // copy(s2,s2+2,front_insert_iterator<vector<string>>(dic) );       // cant do  vector not supperted fornt_insert
    }
    {
        // list<int> one = {5,2};
        list<int> one(5,2);
        int ar1[5] = {1,2,3,4,5};
        for_each(one.begin(),one.end(),outint);
        cout << "one" << endl;

        list<int> two;
        two.insert(two.begin(),ar1 ,ar1+5);
        for_each(two.begin(),two.end(),outint);
        cout << "two" <<endl;

        list<int> three(two);
        int ar2[6] = {6,4,2,4,6,5};
        three.insert(three.end(),ar2,ar2+6);
        for_each(three.begin(),three.end(),outint);
        cout << "three = two.end + ar2" <<endl;

        three.remove(2);
        for_each(three.begin(),three.end(),outint);
        cout << "three remove 2" <<endl;

        three.splice(three.begin() , one );
        for_each(three.begin(),three.end(),outint);
        cout << "three splice one" <<endl;

        for_each(one.begin(),one.end(),outint);
        cout << "one" <<endl;

        three.unique();
        for_each(three.begin(),three.end(),outint);
        cout << "three unique" <<endl;

        three.sort();
        three.unique();
        for_each(three.begin(),three.end(),outint);
        cout << "three sort and unique" <<endl;

        two.sort();
        three.merge(two);
        for_each(three.begin(),three.end(),outint);
        cout << "three merge two.sort" <<endl;

        for(auto x : three) cout << x << '\t' << endl;      // new usage
    }

    /* 关联容器 set map ... */
    {
        const int n = 6;
        string sar1[n] = {"one" , "two" , "three" , "four" , "three" , "five"};
        string sar2[n] = {"six" , "seven" , "eight" , "nine" , "ten" , "three"};

        set<string> ssa(sar1 , sar1+n);
        set<string> ssb(sar2 , sar2+n);
        cout << "ssa: ";
        copy(ssa.begin(),ssa.end(),ostream_iterator<string,char>(cout , " "));
        cout << "\nssb: ";
        copy(ssb.begin(),ssb.end(),ostream_iterator<string,char>(cout , " "));
        cout << endl;
        cout << "union ssa and ssb: ";
        set_union(ssa.begin(),ssa.end(),ssb.begin(),ssb.end(),ostream_iterator<string,char>(cout," "));
        cout << endl;
        cout << "intersection ssa and ssb: ";
        set_intersection(ssa.begin(),ssa.end(),ssb.begin(),ssb.end(),ostream_iterator<string,char>(cout," "));
        cout << endl;
        set<string> ssc;
        cout << "union for ssa and ssb to ssc: " << endl;
        set_union(ssa.begin(),ssa.end(),ssb.begin(),ssb.end(),insert_iterator<set<string>>(ssc,ssc.begin()));
        copy(ssc.begin(),ssc.end(),ostream_iterator<string,char>(cout," "));
        cout << endl;
        string str1("eleven");
        cout << "insert str'eleven': ";
        ssc.insert(str1);
        copy(ssc.begin(),ssc.end(),ostream_iterator<string,char>(cout," "));
        cout << endl;
        cout << "use lower_bound and upper_bound: " << endl;
        copy(ssc.lower_bound("four"),ssc.upper_bound("ten"),ostream_iterator<string,char>(cout," "));
    }
    {
        // map<int ,string> map1;       // 一对一
        multimap<int , string> map1;    // 一对多

        map1.insert(pair<int,string>(100,"ab"));
        map1.insert(pair<int,string>(100,"ac"));
        map1.insert(pair<int,string>(200,"bb"));
        map1.insert(pair<int,string>(200,"bc"));
        map1.insert(pair<int,string>(200,"bd"));
        map1.insert(pair<int,string>(300,"ca"));

        // pair<string,int> arrpa[]
        // {
        //     {"porsche",718},
        //     {"porsche",911},
        //     {"bwm",400},
        //     {"bwm",500},
        //     {"audio",6}
        // };
        // copy(arrpa,arrpa+5,insert_iterator<pair<string,int>(map1,map1.begin()));  copy(arrpa,arrpa+5,map1.insert)
        // 好像不能向map批量添加数据

        multimap<int,string>::iterator it;
        for(it = map1.begin();it !=map1.end();it++)
        {
            // cout << (*it).first << '\t' << (*it).second << endl;
            cout << it->first << '\t' << it->second << endl;
        }
        cout << endl;
        // pair<multimap<int,string>::iterator ,multimap<int,string>::iterator >::iterator iit = map1.equal_rang(100); 
        // pair<multimap<int,string>,multimap<int,string>> iit = map1.equal_range(100);
        pair<multimap<int,string>::iterator ,multimap<int,string>::iterator> iit = map1.equal_range(200); 
        for(it = iit.first;it !=iit.second; it++)
        {
            cout << it->second << endl;
        }
    }
    return 0;
} 