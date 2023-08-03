#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>

using namespace std;
// 多文件命令行读取 采用argc argv[] 读取命令行参数  读取完一个文件流后需要用clear清空缓冲区 最后需要使用close关闭流

// 出现不同类型的输入输出时需要将缓冲流清空以保证读取到正确的内容 while(getchar() ! = '\n');
// seekg() 接受一个参数 将输出流定位到该处
// seekp() 接受一个参数 将输入流定位到该处

const char * const ARGV[]{"","all file charactor count.","write the file.","app write file.","binary write file",\
"binary app write file" , "output in txt","output in binary","q to quit"};

const int ARGC = sizeof(ARGV) / sizeof(char *);

enum Mode{in = 1 , app , bin , bapp}; // 写入文件的方式 截断/添加/二进制截断/二进制添加
enum Omd{tx = 1 , obin};     // 读取文件方式 文本/二进制

void putnumc(const char c , int n)  //输出一定数量指定字符,结尾加上换行并刷新输出缓冲区
{
    while(n--)  putchar(c);
    putchar('\n');
    fflush(stdout);
}

// 该函数优化为接受argc/argv类似参数打印选择列表  而且还可以使用map<>容器进行操作
// bool dischooes()    // 输出选择列表
// {   
//     // use setf()
//     cout.width(43);
//     cout.fill('*');
//     // ios_base::fmtflags dft = cout.setf(ios_base::internal , ios_base::adjustfield);
//     ios_base::fmtflags dft = cout.setf(ios::right);
//     cout << "chooes";
//     putnumc('*' , 37);
//     cout.fill(' ');
//     cout.setf(ios_base::left , ios_base::adjustfield);
//     cout.width(40);
//     cout << "1.all file charactor count.";
//     ios_base::fmtflags lft = cout.setf(ios_base::right , ios_base::adjustfield);
//     cout.width(40);
//     cout <<"2.dsxxtgfcjhvkujbknlim." << endl;
//     ios_base::fmtflags rit = cout.setf( dft, ios_base::adjustfield);
//     // use <iomanip>    // 为了涉及知识点,我抛弃了美学..
//     cout << std::left << setw(40) << "3.fgyhjkl;guhujyhgfkujh."
//         << std::right << setw(40) << "4.gdhrfthkjlferwakislh." << endl;
//     cout << std::left << setw(40) << "5.tgdxrfdcyhfvujkgblnhkj."
//         << std::right << setw(40) << "6.jhkcasdgdkfjfhgawffasdjh\n"
//         << std::right << setw(43) << "q to quit" << endl;    
//     return true;
// }

bool dischooesplus(int ac , const char* const av[])
{
    printf("%43s\n","chooes");
    for(int i = 1 ; i < ac ; i++)
    {
        printf("%-d:%-40s\t",i,av[i]);
        if(!(i % 2)) putchar('\n');
    }
    putchar('\n');
    fflush(stdout);
    return true;
}

int fcount(int argc , const char * const argv[])  // 接受命令行参数 对传入的文件 进行统计文件内字符数量
{
    int count = 0;
    while(--argc)
    {
        ifstream fi;
        fi.open(argv[argc],ios_base::out);
        if(fi.is_open())
        // if(fi)    if(!fi.fail())   if(fi.good)   
        {
            while(!fi.eof())
            {
                char c;
                fi.get(c);
                // cout << c ;
                count++;
            }
            fi.clear();
            fi.close();
        }
        else
        {
            cout << "cant open " << argv[argc] << endl;
            exit(0);
        }
    }
    printf("have %d charactors in all files.\n\n" , count);
    fflush(stdout);
    return count;
}

// 写入文件和追加文件
int fin(int argc , const char * const argv[],Mode mode)
{
    // for(int i = 1 ; i < argc ; i++)
    // {
    //     printf("%d:%s\t",i,argv[i]);
    //     if(!(i % 2)) putchar('\n');
    // }
    // putchar('\n');
    // printf("enter number for file,we trans it.\n");
    // fflush(stdout);
    
    dischooesplus(argc,argv);
    int play;
    cin >> play;

    ofstream fo;
    if(1 == mode)
        fo.open(argv[play],ios::in | ios::trunc);   // ios::in | ios::trunc 是默认的   // 截断整个文件
    if(2 == mode)
        fo.open(argv[play],ios::in | ios::app);
    if(3 == mode)
        fo.open(argv[play],ios::in | ios::binary);  // 从文件开始覆写(盖)文件
    if(4 == mode)
        fo.open(argv[play],ios::in | ios::binary | ios::app);
    if(fo.is_open())
    {
        printf("eof to quit:(windows:ctrl + z / linux:ctrl+d)\n");
        char ch;
        while(EOF != (ch=getchar()) && fo.put(ch));     // put()函数根据文件打开方式选择 文本输入/二进制输入
        fflush(stdin);
        fo.clear();
        fo.close();

        // string str,temp;
        // while(cin >> temp)
        // {
        //     str += temp;
        // }
        // if(1 == mode || 2 == mode)
        //     fo << str;
        // if(3 == mode)
        //     fo.write(str.c_str(),str.size()); // sizeof str
        // fo.clear();
        // fo.close();
    }
    else
    {
        printf("cant open %s file.",argv[play]);
        return 1;
    }
    return 0;
}

int fout(int argc , const char * const argv[],Omd mode)
{
    dischooesplus(argc,argv);
    int play;
    cin >> play;

    ifstream fi;
    if(1 == mode)
        fi.open(argv[play],ios::out);
    if(2 == mode)
        fi.open(argv[play],ios::out | ios::binary );
    if(fi.is_open())
    {
        // printf("eof to quit:(windows:ctrl + z / linux:ctrl+d)\n");
        char ch;
        while(fi.get(ch) && ch != EOF) putchar(ch);     // put()函数根据文件打开方式选择 文本输入/二进制输入
        putchar('\n');
        fflush(stdout);
        fi.clear();
        fi.close();

        // string str,temp;
        // // getline(fi,temp,'\n');
        // // getline(fi,temp);
        // while(fi >> temp)       
        // {
        //     str += temp;
        // }
        // cout << str << endl;
        // fi.clear();
        // fi.close();
    }
    else
    {
        printf("cant open %s file.",argv[play]);
        return 1;
    }
    return 0;
}

int main(int argc,char* argv[])
{   
    if(1 == argc)
    {   
        cout << "need " << argv[0] << " + filename ." << endl;
        exit(0);
    }
    
    int play = -1;
    while(dischooesplus(ARGC,ARGV) && cin >> play)
    {
        switch(play)
        {
            case 1 :
                fcount(argc,argv);
                continue;
            case 2 :
                fin(argc,argv,in);
                continue;
            case 3 :
                fin(argc,argv,app);
                continue;
            case 4 :
                fin(argc,argv,bin); //会覆盖前面的内容
                continue;
            case 5 :
                fin(argc,argv,bapp);
                continue;    
            case 6 :
                fout(argc,argv,tx);
                continue;
            case 7 :
                fout(argc,argv,obin);
                continue;    
        }
    }
    return 0;
}
