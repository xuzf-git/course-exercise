#include <iostream>
#include <string>
using namespace std;

class Traveler
{
public:
    string str;

    Traveler(string exstr) { str = exstr; }
    Traveler(const Traveler& extraveler) { str = extraveler.str; }

    Traveler operator=(const string exstr)
    {
        str = exstr;
        return (*this);
    }
    Traveler operator=(const Traveler extraveler)
    {
        str = extraveler.str;
        return (*this);
    }
};

class Pager
{
private:
    string str;

public:
    Pager(string exstr) { str = exstr; }
    Pager(const Pager& extpager) { str = extpager.str; }

    Pager operator=(const string exstr)
    {
        str = exstr;
        return (*this);
    }
    Pager operator=(const Pager expager)
    {
        str = expager.str;
        return (*this);
    }
    string getstr() { return this->str; }
};

class BusinessTraveler : public Traveler
{
private:
    Pager page;

public:
    // 构造函数
    BusinessTraveler() : Traveler(""), page("") {};
    BusinessTraveler(string tstr, string pstr) : Traveler(tstr), page(pstr) {};
    // 复制构造函数
    BusinessTraveler(BusinessTraveler& ex) : Traveler(ex.str), page(ex.page) {};
    // 赋值运算符重载
    BusinessTraveler operator=(BusinessTraveler& ex)
    {
        str = ex.str;
        page = ex.page;
        return (*this);
    }
    // 输出流运算符重载
    friend ostream& operator<<(ostream& out, BusinessTraveler& temp)
    {
        int flag1 = 0, flag2 = 0;
        if (temp.str == "")
        {
            cout << "member string str is NULL" << endl;
            flag1++;
        }
        if (temp.page.getstr() == "")
        {
            cout << "member string page.str is NULL" << endl;
            flag2++;
        }
        if (flag1 == 0)
            cout << "str: " << temp.str << endl;
        if (flag2 == 0)
            cout << "page.str: " << temp.page.getstr() << endl;
        return out;
    }
};

int main()
{
    BusinessTraveler b1("Joe BusinessMan", "Pager 1");
    cout << b1 << endl;
    BusinessTraveler b2("Jane BusinessWoman", "Pager 2");
    cout << b2 << endl;
    BusinessTraveler b3;
    cout << b3 << endl;
    BusinessTraveler b4(b1);
    cout << b4 << endl;
    b3 = b2;
    cout << b3 << endl;
    return 0;
}
/*
输出：
str: Joe BusinessMan
page.str: Pager 1

str: Jane BusinessWoman
page.str: Pager 2

member string str is NULL
member string page.str is NULL

str: Joe BusinessMan
page.str: Pager 1

str: Jane BusinessWoman
page.str: Pager 2
*/