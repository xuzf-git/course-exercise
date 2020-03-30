// 一元二次方程类的实现

#include <iostream>
using namespace std;

// 定义方程的根的结构类型
typedef struct ans
{
	double ans1;
	double ans2;
}ans;

// 声明一元二次方程类
class Equation
{
private:
	double a, b, c; // a 二次项系数；b 一次项系数；c 常数项
public:
	Equation(void);								// 缺少构造函数
	Equation(double ax, double bx, double cx);	// 构造函数
	Equation(const Equation& equ);				// 拷贝构造函数
	ans getAns(void); // 求根函数
};
Equation::Equation(void)
{
	a = 0.0;
	b = 0.0;
	c = 0.0;
}
Equation::Equation(double ax, double bx, double cx)
{
	a = ax;
	b = bx;
	c = cx;
}
Equation::Equation(const Equation& equ)
{
	a = equ.a;
	b = equ.b;
	c = equ.c;
}
ans Equation::getAns()
{
	if (a == 0)
	{
		cout << "这不是一个一元二次方程" << endl;
		exit(0);
	}
	else
	{
		double delta = (b * b - 4.0 * a * c);
		if (delta < 0.0)
		{
			cout << "方程没有实数解" << endl;
			exit(1);
		}
		else
		{
			ans result;
			result.ans1 = (-b + sqrt(delta)) / (2 * a);
			result.ans2 = (-b - sqrt(delta)) / (2 * a);
			return result;
		}
	}
}

int main(int argc, char * argv[])
{
	double ax = 0.0, bx = 0.0, cx = 0.0;
	cin >> ax >> bx >> cx;
	Equation equtest(ax, bx, cx);
	ans result = equtest.getAns();
	double ans1 = result.ans1;
	double ans2 = result.ans1;
	if (ans1 == ans2)
	{
		cout << "Ans: " << ans1 << endl;
	}
	else
	{
		cout << "Ans1: " << ans1 << "Ans2" << ans2 << endl;
	}
	return 0;
}