#include <iostream>
using namespace std;
class B1
{
    int b;

public:
    B1(int i) : b(i) { cout << "Constructor B1:" << b << endl; }
    ~B1() { cout << "Des B1:" << b << endl; }
};

class B2
{
    int b;

public:
    B2(int i) : b(i) { cout << "Constructor B2:" << b << endl; }
    ~B2() { cout << "Des B2:" << b << endl; }
};

class Y : public B1, public B2
{
    B1 x1, x2;
    B1& x3;
    const int num1;  // 常量成员
    static int num2; // 静态成员

public:
    Y(int i, int j, int m, int n, int s) : x2(i), x1(j), B2(m), B1(n), x3(x2), num1(s)
    {
        cout << "Constructor Y:" << endl;
        cout << "num1: " << num1 << endl;
        cout << "num2: " << num2 << endl;
    }
    ~Y() { cout << "Des Y:" << endl; }
};
int Y::num2 = 0;

int main(int argc, char const* argv[])
{
    Y(1, 2, 3, 4, 5);
    return 0;
}
/*
输出：
Constructor B1:4
Constructor B2:3
Constructor B1:2
Constructor B1:1
Constructor Y:
num1: 5
num2: 0
Des Y:
Des B1:1
Des B1:2
Des B2:3
Des B1:4
*/