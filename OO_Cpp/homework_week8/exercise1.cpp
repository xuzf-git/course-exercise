#include <iostream>
using namespace std;

class Vehicle
{
protected:
    double distance;        // 运输路程
    double weight;          // 运输重量
    const double wdistance; // 路程权重
    const double wweight;   // 重量权重

public:
    Vehicle(double dis = 0.0, double wei = 0.0,
            double wdis = 0.0, double wwei = 0.0) : wdistance(wdis), wweight(wwei)
    {
        distance = dis;
        weight = wei;
    }
    virtual double Fee() = 0;
};

class Aircraft : public Vehicle
{
public:
    Aircraft(double dis = 0.0, double wei = 0.0) : Vehicle(dis, wei, 1.15, 1.05) {}
    virtual double Fee()
    {
        return distance * wdistance + weight * wweight;
    }
};

class Steamship : public Vehicle
{
public:
    Steamship(double dis = 0.0, double wei = 0.0) : Vehicle(dis, wei, 1.05, 0.9) {}
    virtual double Fee()
    {
        return distance * wdistance + weight * wweight;
    }
};

class Car : public Vehicle
{
public:
    Car(double dis = 0.0, double wei = 0.0) : Vehicle(dis, wei, 1.2, 1.1) {}
    virtual double Fee()
    {
        return distance * wdistance + weight * wweight;
    }
};

int main(int argc, char const *argv[])
{
    Aircraft p1(1000, 1000);
    Steamship p2(1000, 1000);
    Car p3(1000, 1000);

    Vehicle *ptr;
    ptr = &p1;
    cout << "Aircraft costs " << ptr->Fee() << endl;
    ptr = &p2;
    cout << "Steamship costs " << ptr->Fee() << endl;
    ptr = &p3;
    cout << "Car costs " << ptr->Fee() << endl;

    return 0;
}
