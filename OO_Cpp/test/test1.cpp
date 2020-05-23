#include <iostream>
#include <string>
using namespace std;
class Base
{
public: // Overloading
    virtual int f() const
    {
        cout << "Base::f()\n";
        return 1;
    }
    virtual void f(string a) const 
    {
        cout << a << endl;
    }
    virtual void g() const {}
};

class Derived4 : public Base
{
public:
    int f() const
    {
        cout << "Derived4::f()\n";
        return 4;
    }
};

int main()
{
    Derived4 d;
    d.f();
    d.f("hello")
    return 0;
}