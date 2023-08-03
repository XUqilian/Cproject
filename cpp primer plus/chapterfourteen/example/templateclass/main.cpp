#include"head.h"

int main(void)
{
    Stack<char *> t(5); // 模板实例化 以string 为模板
    // string temp;
    char ch;
    // T temp; 将变量存入类内部 减少外部操作步骤 
    // 也可放在外部增强实现性 具体取决于个人 置于外部时需与栈类型相同
    char * ar[10]{
        "haha","hehe","hoho","jiji","kuku",
        "baba","titi","yyyy","iiii","oooo"
    };
    int i = 0 ;
    while(i < 10){
        cout << "enter a to push,d to delete,enter other to quit:" << endl;
        ch = getchar();
        while(getchar() != '\n');
        switch(ch)
        {
            case 'a':
                t.push(ar[i++]);
                continue;
            case 'd':
                t.pop();
                continue;
            default:
                break;
        }
        break;
    }

    return 0;
}