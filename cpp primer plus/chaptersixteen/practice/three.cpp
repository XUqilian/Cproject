#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;

// the game is guess words;
// const char * const arr[]
// {
//     "ambition","beautiful", "confidence", "developing", "english",
//     "friendly", "grand", "harmonious", "intelligent", 
//     "justice", "kungfu","liberal", "moderation", "new", "open", 
//     "peacelouing", "quickly", "responsible",  
//     "silk",  "tea", "unity", "vast", "wonderful", "xanadu", "young", "zeal" 
// };

int main(void)
{
    char play;

    // string filestrarr[0];
    // vector<string> filestrarr;

    ifstream filestr("strfile.txt",std::ios::out);
    if(!filestr.is_open())
    {
        cout << "file cant open,please check file." << endl;
        exit(EXIT_FAILURE);
    }
    // FILE * file = fopen("strfile.txt" , "r");

    // srand(time(0));
    // int num = rand() % (sizeof(arr) / sizeof(&arr[0]));
    string words;
    while(filestr >> words)  // 需要添加非单词区分 
    {
        string stemp;
        for(int i = 0 ; i < words.size() ; i++)
        {   
            if(!isalpha(words[i])) continue;
            stemp.push_back(words[i]);
        }
        if(stemp[0] == '\0') continue;
        words = stemp;

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
        cin >>  play;
        if(play != 'y') break;
    }
    // if(filestr.end()) cout << "end the file." << endl;
    if(filestr.eof())  cout << "end the file." << endl;
    filestr.close();
    return 0;
}