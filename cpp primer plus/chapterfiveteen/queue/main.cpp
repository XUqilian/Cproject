#include"queue.h"
#include<string>

using std::cin;
using std::string;
int main(void)
{
    string temp;
    Queue<string> qs(5);
    
    while(!qs.isfull())
    {
        cout << "\nenter name:";
        cin >> temp;
        cout << "1" << endl;
        qs.push(temp);
        cout << "1" << endl;
    }

    while(!qs.isempty())
    {
        getline(cin,temp);
        qs.pop();
    }
    
    return 0;
}