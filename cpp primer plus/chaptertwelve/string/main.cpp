#include"head.h"

int text(String s)
{
    cout <<"call text() " << "s is " << s << endl;
    return 0;
}

int main(void)
{
    String a;
    String b = "hello man.";
    String c("world for you.");

    if(!(c==b)) cout << "not equal!" << endl;

    if(c > b) cout << c << "is longer to " << b << endl;
    else cout << b << "is longer to " << c << endl; 

    a = b;
    cout << "a is " << a << endl;
    b = c;
    cout << "b is " << b << endl;

    c = String(a);
    // 下面是运行情况
    // call copy create fun!
    // call assginment fun!
    // call delete fun!
    // 也就是说 先因为 string() 调用拷贝构造函数创建一个临时对象并使用 a 为其赋值 然后再把临时变量赋值给目标变量  再删除临时变量 

    cout << "c is " << c << endl;

    text(a);
    cout << "a is " << a << endl;
    text(b);                       
    cout << "b is " << b << endl;
    text(c);
    cout << "c is " << c << endl;



    cin >> a;

    cout << b <<"have " << b.lenght() << "char!" << endl;
    cout << a << "char[2] is " << a[2] << endl;
    

    //new 类对象时会有两个动作 开辟指定大小的空间创建类 类调用构造函数 
    String *e = new String;
    String *f = new String("how are you!");
    String *g = new String(a);
    //new 运算符不会自动释放类的析构函数
    // delete []e;                      //我愿称之为傻逼行为 离谱
    delete e;
    delete f;
    delete g;


    //指定区域 new 开辟空间
    char * storage = new char[1024];
    String *h = new(storage) String;
    //继续开辟时应防止覆写错误
    String *i = new(storage + sizeof(String)) String("you are good!");
    printf("h:%p,sizeof(String):%d,i:%p\n",h,sizeof(String),i);
    //定位 new 运算符不会调用析构函数 只能手动
    i->~String();
    h->~String();
    //勿忘释放 new 空间
    delete []storage;

    return 0;
}