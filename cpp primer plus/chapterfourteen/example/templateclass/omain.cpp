#include"head.h"

template<class T>  // 利用模板函数调用模板类  感觉还有很多地方还要完善
void fun(T & t)
{
    char ch;
    // T temp; 将变量存入类内部 减少外部操作步骤 
    // 也可放在外部增强实现性 具体取决于个人 置于外部时需与栈类型相同
    while(true){
        cout << "enter a to push,d to delete,enter other to quit:" << endl;
        ch = getchar();
        while(getchar() != '\n');
        switch(ch)
        {
            case 'a':
                cout << "\nenter push element:";
                cin >> t.temp;
                while(getchar() != '\n');
                t.push(t.temp);
                continue;
            case 'd':
                t.pop();
                continue;
            default:
                break;
        }
        break;
    }
}

int main(void)
{
    Stack<string> s(5); // 模板实例化 以string 为模板

    fun(s);

    return 0;
}