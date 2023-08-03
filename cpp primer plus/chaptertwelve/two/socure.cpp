#include "head.h"

int xgets(char *array, int count)
{
    count--;
    int i = 0;
    for (i = 0; i < count; i++)
    {
        array[i] = getchar();
        if (array[i] == '\0' || array[i] == '\n')
        {
            if (array[i] == '\n')
                array[i] = '\0';
            break;
        }
    }
    if (i == count)
        array[i] = '\0';
    return i;
}

int xclearin()
{
    int t;
    while (t = getchar() && t != '\n');
    return 0;
}

int suptolow()
{
    return 'a' - 'A';
}

void low(char *strl)
{
    int i = 0;
    while(strl[i])
    {
        if(strl[i] <= 'z' && strl[i] >= 'a')    
            strl[i] -= suptolow();
        i++;
    }
}

void sup(char *strl)
{
    int i = 0;
    while(strl[i])
    {
        if(strl[i] <= 'Z' && strl[i] >= 'A')    
            strl[i] += suptolow();
        i++;
    }
}

String::String()
{
    printf("call create fun!\n");
    // str = new char;
    // str[0] = '\0';
    str = NULL;  //C++ 的 NULL 0 nullptr 相同 都是空指针
    slenght = 0;
}

String::String(const char *strl)
{
    printf("call str create fun!\n");
    slenght = strlen(strl);
    str = new char[slenght+1];
    strcpy(str, strl);
}

String::String(const String &strl)
{
    printf("call copy create fun!\n");
    slenght = strl.slenght;
    // delete []str;
    str = new char[strl.slenght + 1];
    strcpy(str, strl.str);
}

String::~String()
{
    printf("call delete fun!\n");
    delete[] str;
    str = NULL;
}

String &String::operator=(const String &strl)
{
    printf("call assginment fun!\n");
    if(*this == strl) return *this;
    
    slenght = strl.slenght;
    char *tempstr = new char[strl.slenght + 1];
    strcpy(tempstr, strl.str);
    delete[] str;
    str = tempstr;
    return *this;
}

ostream &operator<<(ostream &os, const String &strl)
{
    printf("%s\n",strl.str);
    return os << strl.str << endl;
}
istream &operator>>(istream &os, String &strl)
{
    delete[] strl.str;
    strl.str = NULL;

    cout << "enter a string:";
    int l = 100;
    char temp[l];
    if (xgets(temp, l) == l)
        xclearin();

    for (strl.slenght = 0; temp[strl.slenght] != '\0'; strl.slenght++);
    // strl.slenght = i + 1;

    strl.str = new char[strl.slenght + 1];
    strcpy(strl.str, temp);
    return os;
}

const char String::operator[](int t) const
{
    if (t > slenght)
        return -1;
    return this->str[t];
}

bool String::operator>(const String &s) const
{
    if (strcmp(str, s.str) > 0)
        return 1;
    else
        return 0;
}

bool String::operator<(const String &s) const
{
    return s > *this;
}

bool String::operator==(const String &s) const
{
    if (slenght != s.slenght)
        return 0;
    int i = slenght;
    for (; i >= 0; i--)
        if (str[i] != s.str[i])
            return 0;

    return 1;
}

String String::operator+(const String & strl)
{
    String t;
    t.str = new char[slenght + strl.slenght + 1];
    strcpy(t.str,str);
    strcat(t.str,strl.str);
    t.slenght = strlen(t.str);
    cout << "t.slenght:" << t.slenght << endl;
    return t;
}

String operator+(const char * s ,const String & strl)
{
    String t;
    t.str = new char[strlen(s) + strl.slenght + 1];
    strcpy(t.str,s);
    strcat(t.str,strl.str);
    t.slenght = strlen(t.str);
    cout << "t.slenght:" << t.slenght << endl;
    return t;
}

void String::strsup()
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] <= 'z' && str[i] >= 'a')    
            str[i] -= suptolow();
        putchar(str[i]);
        i++;
    }
}

void String::strlow()
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] <= 'Z' && str[i] >= 'A')    
            str[i] += suptolow();
        i++;
    }
}

int String::strnumc(char c)
{
    int i = 0;
    int cnt = 0;
    while(str[i])
    {
        if(str[i] == c) cnt++;
        i++;
    }
    return cnt;
}