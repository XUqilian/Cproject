#include"head.h"

int main(void)
{
    String s1(" and i am a c++ student.");
    String s2="please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = "my name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.strsup();
    cout << "the string \n" << s2 << "\ncopntains " << s2.strnumc('A') << " 'A' char acters in it.\n";
    String rgb[3] = {String(s1),String("green"),String("blue")};
    cout << "enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while(cin >> ans )
    {
        ans.strlow();
        for(int i = 0 ; i  < 3 ; i++ )
        {
            if(ans == rgb[i])
            {
                cout << "that's right!\n";
                success = true;
                break;
            }
        }
        if(success) break;
    }
    return 0;
}