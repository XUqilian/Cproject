#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

// int reduce2(long ar[], int n) // sort and deduplication 排序与去重
// {
//     vector<long> te(n);
//     copy(ar,ar+n,te.begin());
    
//     set<long> tte(te.begin(),te.end());

//     copy(tte.begin(),tte.end(),te.begin());
//     te.erase(te.begin() + tte.size() , te.end() );  ///

//     sort(te.begin(),te.end());

//     copy(te.begin(),te.end(),ar);

//     for(int i = 0 ; i < tte.size() ; i++)
//         ar[i] = te[i]; /////
//     // transform(te.begin(),te.end(),tte.begin(),istream_iterator<long,long>(tte,tte.begin()));
//     // transfrom(te.begin(),te.end(),tte.begin(),istream_itrator<long,long>())
//     return te.size();
// }

template<class T>
int reduce(T ar[], int n)
{
    vector<T> te(n);
    copy(ar,ar+n,te.begin());
    sort(te.begin(),te.end());
    while(n--)
        ar[n] = 0;
    te.erase(unique(te.begin(),te.end()),te.end());     // 去重加减去多余
    copy(te.begin(),te.end(),ar);
    return  te.size(); 
}

template<class T>
int reduce1(T ar[], int n)
{
    // vector<T> te(n);
    sort(ar,ar+n);
    unique(ar);
    for(int i = 1 ; i < n ; i++)
        if(ar[i] < ar[i-1]) return i;
    // while(n--)
    //     ar[n] = 0;
    // te.erase(unique(te.begin(),te.end()),te.end());     // 去重加减去多余
    // copy(te.begin(),te.end(),ar); 
}

int main(void)
{
    int ar[]{1,2,3,43,4,5,45,63,23,5,13,2,5,34,25,34,2,56,34,2,5,23,5,34,43,24,6,42,5,43,41,2,4};
    cout << reduce(ar,33) << endl;
    for(int i = 0 ; i < 33 ; i ++)
        cout << ar[i] << '\t' ;
    return 0;
}