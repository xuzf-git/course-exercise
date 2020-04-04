#include <iostream>
using namespace std;
class  Count
{
private:
    int id;
    static int count; 
public:
     Count();
    ~ Count();
};
int Count::count = 0;
 Count:: Count()
{
    count++;
    id = count;
    cout << "id: " << id << " created" << endl;
}
 Count::~ Count()
{
    count--;
    cout << "id: " << id << " destroyed" << endl;
}
int main(int argc, char const *argv[])
{
    // 在堆上创建对象
    Count *pCount = new Count;

    // 在堆上创建对象数组
    Count *pArray1 = new Count[3];
    Count *pArray2 = new Count[3];

    // delete 析构对象
    delete pCount;

    // delete 析构对象数组
    delete [] pArray1;
    delete pArray2;
    return 0;
}

/* 输出：
id: 1 created
id: 2 created
id: 3 created
id: 4 created
id: 5 created
id: 6 created
id: 7 created
id: 1 destroyed
id: 4 destroyed
id: 3 destroyed
id: 2 destroyed
id: 5 destroyed
*/

/*
分析：、
1. 通过关键字 new 能够调用构造函数，创建动态对象，存储在堆上
   通过关键字 delete 能够调用析构函数，析构对象
2. 当对象数组通过 delete[] 析构时，能够析构数组中的所有对象
   当对象数组听过 delete 析构时，只有指针直接指向的数组中第一个对象会被析构
*/