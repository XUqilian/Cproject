#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// the game is guess words;
const char * const arr[]
{
    "ambition","beautiful", "confidence", "developing", "english",
    "friendly", "grand", "harmonious", "intelligent", 
    "justice", "kungfu","liberal", "moderation", "new", "open", 
    "peacelouing", "quickly", "responsible",  
    "silk",  "tea", "unity", "vast", "wonderful", "xanadu", "young", "zeal" 
};

int main(void)
{
    cout << "if you want play game pleaese enter 'y'(other to quit):";
    char play;

    while(cin >> play && 'y' == tolower(play))
    {
        srand(time(0));
        int num = rand() % (sizeof(arr) / sizeof(&arr[0]));
        const string words = arr[num];
        int times = 5;
        string guew(words.size() , '-');
        string badw;
        cout << "the words has " << words.size() << " elements" << endl;
        while(times && words != guew)
        {
            char tempc;
            cout << "enter a charactor:";
            cin >> tempc;
            // cout << endl;

            if(badw.size()>0 && badw.find(tempc) != -1)
            {   
                cout << "you enter repeat,please try again." << endl;
                continue;
            }
            int lab = words.find(tempc);
            if(badw.find(tempc) == -1 && lab == -1)
            {
                cout << "is a error charactor" << endl;
                times--;
                badw.push_back(tempc);   /////////
            }
            if(lab != -1)
            {
                cout << "great!" << endl;
                while(lab != -1)
                {
                    guew[lab] = words[lab];
                    lab = words.find(tempc,lab+1);
                }
            }
            if(times)
                cout << "now you have " << times << " times can guess,and the words like " << guew << endl << endl;
        }
        if(times > 0 || words == guew)
            cout << "you win." << endl;
        else cout << "you loss,the words is " << words << endl;

        cout << "if you want try again,enter 'y'(other to quit):";
    }

    return 0;
}