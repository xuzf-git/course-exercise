#include <iostream>
using namespace std;
class Shape
{
protected:
    double area_val; // 图形面积

public:
    Shape() { area_val = 0.0; }         // 构造函数
    virtual void Area() = 0;            // 纯虚函数、计算面积
    friend double PrintArea(Shape &obj) // 显示面积
    {
        obj.Area();
        return obj.area_val;
    }
};
class Circle : public Shape
{
private:
    int Radius; // 半径

public:
    Circle(int r = 0) : Shape() // 构造函数
    {
        Radius = r;
    }
    void Area() // 计算圆的面积
    {
        area_val = 3.14 * Radius * Radius;
    }
};
class Triangle : public Shape
{
private:
    int Bottom_length; // 底边长
    int Height;        // 高

public:
    Triangle(int b, int h) : Shape() // 构造函数
    {
        Bottom_length = b;
        Height = h;
    }
    void Area() // 计算三角形的面积
    {
        area_val = 0.5 * Bottom_length * Height;
    }
};
void main()
{
    Shape *p = new Circle(2);
    cout << "The area of the circle is: " << PrintArea(*p) << endl;
    Triangle triangle(3, 4);
    cout << "The area of the triangle is: " << PrintArea(triangle) << endl;
    delete p;
}
