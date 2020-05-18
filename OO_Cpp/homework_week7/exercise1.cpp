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
    double pay()
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
    Manager(string sname, double exsalay = 70000) : Employee(sname, exsalay){};
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
};

class Salesmanager : public Salesperson, public Manager
{
private:
    double to_sales;
    double rate;

public:
    Salesmanager(string sname, double exto_sales, double exsalary = 4000, double exrate = 0.005)
        : Employee(sname, exsalary + exto_sales * exrate),
          Salesperson(sname, exto_sales, exrate),
          Manager(sname, exsalary)
    {
        to_sales = exto_sales;
        rate = exrate; 
    }
};

int main(int argc, char const *argv[])
{
    Salesmanager p1("狗蛋", 10000);
    cout << p1.getname() << ": " << p1.pay() << endl;
    return 0;
}
