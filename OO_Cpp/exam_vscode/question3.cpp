#include <iostream>
using namespace std;
template <typename T>
class MyArray
{
private:
    int size; // 数组中元素的数量
    T *data;  // 数组数据

public:
    MyArray() // 无参构造
    {
        data = NULL;
        size = 0;
    }
    MyArray(int len) // 含参构造
    {
        data = new T[len];
        size = len;
    }
    ~MyArray()
    {
        if (data != NULL)
        {
            delete[] data;
        }
    }
    T &operator[](int &index) // 重载下标运算符
    {
        if (index >= size || index < 0)
        {
            cout << "Index range error" << endl;
            exit(1);
        }
        else
        {
            return data[index];
        }
    }
    // 友元函数重载输出流运算符
    template <typename T> 
    friend ostream &operator<<(ostream &out, MyArray<T> const &obj);
};
template <typename T>
ostream &operator<<(ostream &out, MyArray<T> const &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        out << obj.data[i] << ",";
    }
    return out;
}
int main()
{
    MyArray<int> intArray(10); // 10 is the number of elements in intArray
    for (int i = 0; i < 10; i++)
        intArray[i] = i * i;
    cout << intArray << endl;
    return 0;
}
