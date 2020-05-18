#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    double salary;

public:
    Employee(string &sname, double exsalary = 0)
    {
        salary = exsalary;
        name = sname;
    }
    virtual double pay()
    {
        return salary;
    }
    string getname()
    {
        return name;
    }
};

class Manager : virtual public Employee
{
public:
    Manager(string sname, double exsalay = 7000) : Employee(sname, exsalay){};
    virtual double pay()
    {
        cout << " Manager.pay() calling ";
        return salary;
    } 
};

class Technician : virtual public Employee
{
private:
    double work_time;     // 工作时长
    double hourly_salary; // 时薪

public:
    Technician(string sname, double exwork_time, double exhourly_salary = 100)
        : Employee(sname, exhourly_salary * exwork_time)
    {
        work_time = exwork_time;
        hourly_salary = exhourly_salary;
    };
    virtual double pay()
    {
        cout << " Technician.pay() calling ";
        return hourly_salary * work_time;
    }
};

class Salesperson : virtual public Employee
{
private:
    double sales;
    double rate;

public:
    Salesperson(string sname, double exsales, double exrate = 0.05)
        : Employee(sname, exsales * exrate)
    {
        sales = exsales;
        rate = exrate;
    }
    virtual double pay()
    {        
        cout << " Salesman.pay() calling ";
        return sales * rate;
    }
};

class Salesmanager : public Salesperson, public Manager
{
private:
    double to_sales;
    double rate;
    double base_salary;

public:
    Salesmanager(string sname, double exto_sales, double exsalary = 4000, double exrate = 0.005)
        : Employee(sname, exsalary + exto_sales * exrate),
          Salesperson(sname, exto_sales, exrate),
          Manager(sname, exsalary)
    {
        to_sales = exto_sales;
        rate = exrate; 
        base_salary = exsalary;
    }
    virtual double pay()
    {        
        cout << " Salemanager.pay() calling ";
        return base_salary + to_sales * rate;
    }
};

int main(int argc, char const *argv[])
{
    Employee *ptr;
    Manager p1("manager");
    Technician p2("Technician", (21 - 9) * 6);
    Salesperson p3("salesman", 100000);
    Salesmanager p4("salesmanager", 10000);
    ptr = &p1;
    cout << ptr->pay() << endl;
    ptr = &p2;
    cout << ptr->pay() << endl;
    ptr = &p3;
    cout << ptr->pay() << endl;
    ptr = &p4;
    cout << ptr->pay() << endl;
    return 0;
}
/* output
 Manager.pay() calling 7000
 Technician.pay() calling 7200
 Salesman.pay() calling 5000
 Salemanager.pay() calling 4050
*/
/* 分析说明
派生类Manager、Technician、Salesperson、Salesmanager，对基类中的虚函数 pay() 进行 override。
声明的派生类对象中，包含虚函数列表指针，不同派生类中虚函数 pay() 经过重写
当用基类对象指针指向派生类对象时（upcast），能够通过虚函数列表，动态绑定当前类重写的虚函数 pay()，
因此能够调用指针的动态类型的虚函数，座椅会有这样的输出。
*/