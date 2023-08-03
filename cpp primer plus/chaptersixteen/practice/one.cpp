#include<iostream>
#include<algorithm>

using namespace std;

bool hwone(string & str)
{ 
    for(int i = 0 , j = str.size() - 1; i < j ; i++ , j--)
    {
        if(tolower(str[i]) != tolower(str[j])) return false;
    }
    return true;
}

// bool hw(string & str)
// {
//     string::const_iterator it;
//     string::const_iterator is = str.end();      // string::reverse_iterator is = str.rbegin();
//     is--;
//     for(it = str.begin();it != str.end() ; it++ ,is--)      //  这个循环一半就可以了 还可以优化
//     {
//          if(it < is )
//             if(*it != *is) 
//                  return false;
//          else break;
//     }
//     return true;
// }

bool hwtwo(string & str)
{
    for(int i = 0 , j = str.size() - 1; i < j ;)
    {
        if(!isalpha(str[i]))
        {
            i++;
            continue;
        }
        if(!isalpha(str[j]))
        {
            j--;
            continue;
        }
        if(tolower(str[i]) != tolower(str[j])) return false;
        i++,j--;
    }
    return true;
}

int main(void)
{

    return 0;
}