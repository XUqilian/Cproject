#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
    {
        // set<string> mat;
        // set<string> pat;
        vector<string> mat;
        vector<string> pat;
        string str;
        cout << "enter mat's friends . 'q' to quit." << endl;
        while(cin >> str && str != "q")
            mat.push_back(str);
        sort(mat.begin(),mat.end());    
        
        cout << "enter pat's friends . 'q' to quit." << endl;
        while(cin >> str && str != "q")
            pat.push_back(str);
        sort(pat.begin(),pat.end());
        
        set<string> sum(mat.begin(),mat.end());
        for(string t : pat)
            sum.insert(t);
        for(string t : sum)
            cout << t << '\t';
    }

    set<string> mat;
    set<string> pat;
    string str;
    cout << "enter mat's friends . 'q' to quit." << endl;
    while(cin >> str && str != "q")
        mat.insert(str);
    sort(mat.begin(),mat.end());    
    
    cout << "enter pat's friends . 'q' to quit." << endl;
    while(cin >> str && str != "q")
        pat.insert(str);
    sort(pat.begin(),pat.end());
    
    set<string> sum(mat.begin(),mat.end());
    // for(string t : pat)
    //     sum.insert(t);
    sum.insert(pat.begin(),pat.end());

    for(string t : sum)
        cout << t << '\t';
        
    return 0;
}