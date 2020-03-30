#include <iostream>
#include <cmath>
using namespace std;

class CAngle
{
private:
    double m_dAlpha;

public:
    CAngle(void);            //缺少构造函数
    CAngle(double a);        //构造函数
    CAngle(const CAngle &a); //拷贝构造函数
    double GetAlpha(void);   //返回角的角度值（弧度）
    double GetSin(void);     //返回角的正弦值
    double GetCos(void);     //返回角的余弦值
};

CAngle::CAngle(void)
{
    m_dAlpha = 0;
}

CAngle::CAngle(double a)
{
    m_dAlpha = a;
}

CAngle::CAngle(const CAngle &a)
{
    m_dAlpha = a.m_dAlpha;
}

double CAngle::GetAlpha(void)
{
    return m_dAlpha;
}

double CAngle::GetSin(void)
{
    return sin(m_dAlpha);
}

double CAngle::GetCos(void)
{
    return cos(m_dAlpha);
}
// 形参
void Print1(CAngle a)
{
    cout << a.GetCos() << endl;
}
// 引用型变量作为参数
void Print2(CAngle &a)
{
    cout << a.GetCos() << endl;
}

int main()
{
    CAngle aa(3.0);
    Print1(aa);
    Print2(aa);
    return 1;
}
// Print1传递参数，采用值传递，会将CAngle类的aa在内存中拷贝一份，执行效率较低
// Print2传递参数，通过引用传递参数，不需要进行内存拷贝，执行效率较高