#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

int main(void)
{
    const int len = 100000;
    srand(time(0));
    vector<int> vi0(len);
    for(int i = 0 ; i < len ; i++)
        vi0[i] = rand() % 32766;

    vector<int> vi(vi0);
    
    clock_t start = clock();
    sort(vi.begin(),vi.end());
    clock_t end = clock();
    long double vit = (double) (end - start) / CLOCKS_PER_SEC;

    list<int> li(vi0.begin(),vi0.end());
    start = clock();
    li.sort();
    end = clock();
    long double lit = (double) (end - start) / CLOCKS_PER_SEC;

    li.assign(vi0.begin(),vi0.end());
    start = clock();
    vi.assign(li.begin(),li.end());
    sort(vi.begin(),vi.end());
    li.assign(vi.begin(),vi.end());
    end = clock();
    long double lmit = (double) (end - start) / CLOCKS_PER_SEC;

    cout << vit << '\t' << lit << '\t' << lmit << endl;

    return 0;
}