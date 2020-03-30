#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // for循环中变量的作用范围
    for (int i = 0; i < 10; i++)
    {
        printf("Hello World\n");
    }

    return 0;
}
// 变量的作用域，存储空间的 分配
// 引用类型可以在两个不同的作用域之间进行信息传递