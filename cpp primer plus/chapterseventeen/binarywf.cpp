#include<iostream>
#include<fstream>
#include<string>

using namespace std;
// seekg(streampos) 文件读取流 位置 定位读取流中的位置
// seekg(streamoff,ios::seekdir) 偏移量,固定标签位置(有文件开头,当前位置,文件结尾)
// seekp(streampos) 写入文件流 位置 定位写入流中的位置
// seekp(streamoff,ios::seekdir) 偏移量,固定标签位置(有文件开头,当前位置,文件结尾)

struct stt
{
    int a;
    double b;
    char s[32]; // string cant do error : 'munmap_chunk(): invalid pointer Aborted'
};

void fin(fstream & fio)
{
    fio.seekp(0);  //fio.seekp(0,ios::beg); 相同效果 beg开头 cur当前位置 end结尾
    char play;
    while(cout << "enter y to next:(other to quit)"  && cin >> play && play == 'y')
    {
        stt temp;
        cout << "enter int double string:";
        cin >> temp.a >> temp.b >> temp.s;
        // cin >> temp.a >> temp.b ;
        // cin.getline(temp.s,32);
        if(! fio.write((char*)&temp , sizeof(temp)))
        {
            cout << "write error!" << endl;
            exit(0);
        }
    }
    fio.clear();
}

int fout(fstream & fio)
{
    fio.seekg(0);
    stt t;
    int i = 0;
    while(fio.read((char*)&t , sizeof(stt)))    //read()提取在文件结尾停止，在这种情况下，函数调用 setstate(failbit)
    {
        cout << ++i << " : ";
        cout << t.a << '\t' << t.b << '\t' << t.s << endl;
    }
    fio.clear();        // 这里因为读取到文件末尾设置了failbit 需要清除才能再接下来的程序中读取
    // if(fio.eof()) 
    //     return i;
    // if(fio.fail() || fio.bad() )    
    // {
    //     cout << "error read." << endl;
    //     exit(0);
    // }
    cout << endl;
    return i;
}

void modify(fstream & fio)
{
    int n,t; 
    n = fout(fio);
    while(n > 0 && cout << "\nenter you wangt change struct num(q to quit) :"  && cin >> t && t <= n)
    {
        fio.seekg(sizeof(stt) * (t-1));
        stt temp;
        // fio >> temp.a >> temp.b >> temp.s;
        fio.read((char*)&temp ,sizeof(temp));   // 取temp地址再将其指针属性转为char*  
        cout << "now change this struct " << "a:" << temp.a << "\tb:" << temp.b << "\ts:" << temp.s << endl;
        cout << "enter change int a & double b & string s:";
        cin >> temp.a >> temp.b >> temp.s;
        fio.seekp(sizeof(stt) * (t-1));
        fio.write((char*)&temp ,sizeof(temp));
        fio.clear();
    }
    cout << endl;
    cout << " now file like this:" << endl;
    fout(fio);
}


int main(void)
{
    fstream fio;
    fio.open("test" , ios_base::in | ios_base::out | ios::binary | ios::trunc);
    if(!fio)
    {
        cout << "cant open 'test' file." << endl;
        exit(0);
    }

    fin(fio);
    fout(fio);
    modify(fio);

    fio.clear();
    fio.close();
    return 0;
}