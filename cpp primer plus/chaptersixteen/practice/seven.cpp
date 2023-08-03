#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;


vector<int> lotto(int rd, int n)
{
    srand(time(NULL));   
    vector<int> temp(n);
    int i = 0;
    while(n-i)
    {
        int t = rand() % rd;
        bool fr = false;
        for(int j = 0 ; j < temp.size() ; j++)
        {
            if(temp[j] == t) fr = true;
        }
        if(fr) continue;
        temp[i] = t;
        i++;
    }
    return temp;
}

vector<int> lottoo(int rd, int n)
{
    // srand(time(NULL));   
    vector<int> temp(rd);
    for(int i = 0 ; i < temp.size() ; i++)
        temp[i] = i ;
    random_shuffle(temp.begin(),temp.end());
    temp.erase(temp.begin()+n,temp.end());
    return temp;
}

int main(void)
{
    vector<int> ar;
    ar = lotto(51,6);
    for(int x : ar) cout << x << '\t';
    cout << endl;
    ar = lottoo(51,6);
    for(int x : ar) cout << x << '\t';
    
    return 0;
}

    