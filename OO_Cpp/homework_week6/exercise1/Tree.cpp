#include <iostream>
using namespace std;
class Tree
{
    int H;

public:
    Tree(int treeHeight = 0)
    {
        H = treeHeight;
        cout << "Tree(): " << H << endl;
    }
    void print() { cout << H << endl; }
    ~Tree()
    {
        cout << "~Tree(): " << H << endl;
    }
};
Tree outObj(10); // 全局对象
int main()
{
    Tree inObj(20);            // 局部对象
    static Tree staticObj(30); // 静态对象
    Tree* t = new Tree(40);    // 动态对象
    cout << "outObj " << &outObj << endl;
    cout << "staticObj " << &staticObj << endl;
    cout << "inObj " << &inObj << endl;
    cout << "t points " << &(*t) << endl;
    delete t;
    return 0;
}
/*
输出：
Tree(): 10
Tree(): 20
Tree(): 30
Tree(): 40
outObj 00EBF2D8
staticObj 00EBF2DC
inObj 00B3FAE4
t points 0108D9E0
~Tree(): 40
~Tree(): 20
~Tree(): 30
~Tree(): 10
*/

/*
分析：
1. outObj 是全局对象，存储在静态存储空间中, 地址是 00EBF2D8
2. staticObj 是静态对象，存储在静态存储空间中，地址是 00EBF2DC
3. inObj 是局部对象，存储在栈中，地址是 00B3FAE4
4. t 指向一个动态对象，存储在堆中，地址是 0108D9E0
*/