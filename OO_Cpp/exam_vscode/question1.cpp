#include <iostream>
using namespace std;
class Complex
{
private:
    int real;  // 实部
    int image; // 虚部

public:
    Complex() // 缺省构造函数
    {
        real = 0;
        image = 0;
    }
    Complex(int r, int i) // 重载构造函数
    {
        real = r;
        image = i;
    }
    Complex(Complex const &c) // 拷贝构造函数
    {
        real = c.real;
        image = c.image;
    }
    Complex operator+(Complex const &c) // + 运算符重载
    {
        Complex temp(real + c.real, image + c.image);
        return temp;
    }
    Complex &operator+=(Complex const &c) // += 运算符重载
    {
        real += c.real;
        image += c.image;
        return *this;
    }
    Complex operator=(Complex const &c) // 赋值运算符重载
    {
        if (this != &c)
        {
            real = c.real;
            image = c.image;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, Complex const &c) // 输出流运算符重载
    {
        if (c.image == 0) // 实数
            out << c.real;
        else if (c.real == 0) // 虚数
            out << c.image << "i";
        else // 复数
            out << c.real << "+" << c.image << "i";
        return out;
    }
};
void main()
{
    Complex C1(1, 2), C2;
    Complex C3 = C2;
    cout << " C3 = " << C3 << endl;
    C2 = C1 + C3;
    cout << " C2 = " << C2 << endl;
    C2 += C1;
    cout << " C2 = " << C2 << endl;
}
