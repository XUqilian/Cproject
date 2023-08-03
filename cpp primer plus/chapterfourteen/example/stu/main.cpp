#include"head.h"

int main(void)
{
    Stu a;
    // Stu a();  // 使用这个的话与上面不一样 不知道为什么  操作数类型为:std::istream >> Stu ()

    Stu b("tom");
    // 如果有 b = " jery" 就会将 b 变为一个名为 的对象 还会把已存在的 cores 变为 0 个
    Stu c(2);
    // 如果有 c=4 就会出现 c.scores.size 变成 4 个 改变了原对象  而且还会改变原对象的 name 成员
    
    Stu d(c);
    Stu e(2,3);
    
    Stu f("jary", 2);
    double arr[5]{1,2,3,4,5};
    Stu g(arr,2);

    // test different create fun.how to assignment element 'name' approach 
    // the class dont declare how to alter element 'name' , but operator>> can do it

    cout << "add name and scores" << endl;
    cin >> a; // why dont use in vscode ? i compile can do it but run have error
    cout << a;

    cout << "add scores" << endl;
    cin >> b;
    cout << b;

    cout << "add name and scores" << endl;
    cin >> c;
    cout << c;

    cout << "inherited in c , add name and scores" << endl;
    cin >> d;
    cout << d;

    cout<< "add name" << endl;
    cin >> e;
    cout << e;

    cout << "add scoress" << endl;
    cin >> f;
    cout << f;

    cout << "add name" << endl;
    cin >> g;  
    cout << g;

    // test different create fun.how to assignment element 'scores' approach
    double num = e[2];  // operator[] return type is Stu&. can be left and right value 
    e[2] = 10 ;

    return 0;
}