#include<iostream>
#include<string>
#include<memory>

// using std::cout;
// using std::endl;
// using std::cin;
// using std::string;
// using std::auto_ptr;

using namespace std;

class Report
{
    private:
        string str;
    public:
        Report(const char * s) : str(s) { printf("use create func.\n");}
        ~Report(){ printf("use ~create func.\n");}
        void dis() { printf("use dis func.\n");}
};

int main(void)
{
    {
        // 智能指针会自己释放指针 调用析构函数
        // 但当存在多个指针指向同一个智能指针时会有不同情况 因为可能会出现释放一处空间两次
        {
            auto_ptr<Report> ps (new Report(" using auto_ptr."));
            ps->dis();
            // auto_ptr<Report> pss;
            // pss = ps;  // 这样会让已存在的指针失效 产生段错误  因为有一个指针处于'悬挂'状态 未指向安全的位置 
            // 根据建立所有权概念 同一时刻自能有一个指针可以拥有 当产生拥有转移时 旧的指针将不允许再指向其 
        }
        {
            unique_ptr<Report> ps2 (new Report("using unique_ptr."));
            ps2->dis();
            // unique_ptr<Report> pss;
            // pss2 = ps2;  // 这样会让已存在的指针失效 产生段错误 一个指针处于悬挂状态 未指向安全的位置
            // 根据建立所有权概念 同一时刻只能有一个指针可以拥有 当产生拥有转移时 旧的指针将不允许再指向其
            // 并且unique更严格 会在编译时就报错
        }
        //  以上两种智能指针只有当不会产生悬挂状态时才可以进行使用 
        // 类似于函数返回的对象或者返回的同类型指针/临时对象 : return class_t;  return auto_ptr<type> ps ... 等
        // 无智能指针指向的对象/临时对象 auto_ptr<type> (new T("...")); 
        // move()函数可对智能指针进行调整 使其可以重新赋值或切换指向同类型对象
        {
            shared_ptr<Report> ps1 (new Report("using share_ptr."));
            ps1->dis();

            shared_ptr<Report> pss1;
            pss1 = ps1;  // 允许
            // shared 创建的是智能更高指针 采用一个常量记录指向的指针数量 当剩余最后一个时才会进行释放指针
        }
        // 选用智能指针: 
        // 新标准不建议使用auto_ptr  如果是旧项目可能不支持新的智能指针(shared/unique)
        // 如果需要多个智能指针指向某个对象时采用 shared
        // 其他可采用unique

    }


    return 0;
}