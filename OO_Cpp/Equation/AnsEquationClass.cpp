#include "iostream"
#include "cmath"
using namespace std;

class QuadrEquation
{
public:
    double m_dA;
    double m_dB;
    double m_dC;

public:
    double Root1()
    {
        double Q = m_dB * m_dB - 4 * m_dA * m_dC;
        if (Q <= 0 || m_dA < 0.00001)
        {
            cout << "This equation has no root" << endl;
            exit(1);
        }
        return 0.5 * (-m_dB - sqrt(Q)) / m_dA;
    }

    double Root2()
    {
        double Q = m_dB * m_dB - 4 * m_dA * m_dC;
        if (Q <= 0 || m_dA < 0.00001)
        {
            cout << "This equation has no root" << endl;
            exit(1);
        }
        return 0.5 * (-m_dB + sqrt(Q)) / m_dA;
    }
};

int main(int argc, char* argv[])
{
    QuadrEquation qe;
    qe.m_dA = 1;   qe.m_dB = 3;   qe.m_dC = 2;
    cout << "The first root of this equation is   " << qe.Root1() << endl;
    cout << "The second root of this equation is   " << qe.Root2() << endl;
    return 0;
}

