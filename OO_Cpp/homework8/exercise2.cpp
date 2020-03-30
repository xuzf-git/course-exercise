#include <iostream>
#include <math.h>
using namespace std;

class CCircle
{
private:
	double X, Y, R;
public:
	CCircle() { X = Y = R = 0; }
	CCircle(double cX, double cY, double cR) : X(cX), Y(cY), R(cR) {}
	~CCircle(){}
	double CalcuLen(double ax, double ay, double bx, double by);
	double CalcuLen(CCircle otcircle);
	void Relationship(CCircle otcircle);
};

double CCircle::CalcuLen(double ax, double ay, double bx, double by)
{
	// 计算距离的成员函数
	return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
double CCircle::CalcuLen(CCircle otcircle)
{
	// 计算距离的成员函数
	return sqrt((X - otcircle.X) * (X - otcircle.X) + (Y - otcircle.Y) * (Y - otcircle.Y));
}
void CCircle::Relationship(CCircle otcircle)
{
	// 判断两个圆的关系
	double len = this->CalcuLen(otcircle);
	if (len > R + otcircle.R)
	{
		cout << "seperation" << endl;
	}
	else if (len == R + otcircle.R)
	{
		cout << "externally tangent" << endl;
	}
	else if (len > fabs(R - otcircle.R) && len < R + otcircle.R)
	{
		cout << "intersection" << endl;
	}
	else if (len == fabs(R - otcircle.R))
	{
		cout << "intenally tangent" << endl;
	}
	else
	{
		cout << "Contained" << endl;
	}
}

double CalcuLen(double ax, double ay, double bx, double by)
{
	// 计算距离的非成员函数
	return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
int main(int argc, char const* argv[])
{
	CCircle testa(1, 2, 3);
	CCircle testb(4, 6, 2);
	testa.Relationship(testb);
	return 0;
}