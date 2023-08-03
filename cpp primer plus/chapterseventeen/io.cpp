// 输入输出控制
// 重定向 >  < 



// ios_base -> ios -> ostream && istream -> iostream  继承关系 

#include<iostream>

using namespace std;

int main(void)
{
    // cout与cin 是类对象 内部重载了<< >> 的很多版本 会根据传入参数类型选择合适版本调用 以实现自动类型适应

    // 进制
    cout << hex;    hex(cout);      // 接下来以十六进制进行输出
    cout << oct;    oct(cout);      // 接下来以八进制进行输出
    cout << dec;    dec(cout);      // 接下来以十进制进行输出
    cin >> hex;     // cin 也相同

    // cout.put(char) 输出一个字符
    // cout.write(const char * ,int size) 输出字符串中的size个字符 无防越界功能

    // 缓冲区streambuf
    cout << flush;
    flush(cout);    // 刷新缓冲区
    cout << endl;   // 刷新缓冲区并添加换行符

    // 对齐   默认进行右对齐 用空格填充
    // int width() 返回当前宽度
    // int width(int)   接受一个宽度 返回之前的宽度
    // cout .width(int )    接受一个只影响下一次输出的宽度
    // cout.fill(char)      接受一个填充字符 以代替空格填充

    // 精度
    cout.precision(2);  // 接受一个精度参数

    ios_base::fmtflags old = cout.setf(ios_base::showpoint);     //  显示末尾小数点 类似常量调整还有 可返回之前的输出设置参数 类型为ios_base::fmtflags
    ios_base::fmtflags old = cout.setf(ios_base::fixed , ios_base::floatfield); // 第二个是大类 第一个是对大类的操作
    cout.setf(old); // 恢复旧的设置
    // unsetf(ios_base::fmtflags t); 恢复某一项设置的原始状态 与setf()参数相同但起相反的作用
    // cout.setf(0,ios_base::floatfiled) // 使第二参数类控制的恢复默认

    // cin.get(char);  // 不跳过空白和换行
    // cin>>    // 跳过空白以及换行
    // get(char* ,int ,char)    getline(char*,int,char); //获取int个字符存入char* 或者以char为界限
    // ignore(int , char)   读取int个字符或者读取到char字符 将读取到的内容丢弃


    // 流状态
    // eofbit文件尾 badbit坏的流 failbit获取到非预期值 goodbit前三个都是好的
    // eof() bad() fail() good() 返回各自状态   rdstate() 返回整个流状态
    // clear() 清空流并重置流good状态 
    cin.clear();
    // cin.clear(eofbit); // 设置eofbit状态 并将另外两个重置bad/fail
    // setstate() 重置单个状态eof/bad/fail
    // cin.setstate(eofbit) // 设置eofbit状态 不设置另外两个状态
    // 流状态出现问题时 后续的输入将不被接受
    
    return 0;
}
