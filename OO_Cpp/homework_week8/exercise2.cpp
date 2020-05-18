//: C12:IostreamOperatorOverloading.cpp
// Example of non-member overloaded operators
#include "../require.h"
#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;

template <typename T, int sz>
class Array
{
    T i[sz];

public:
    Array() { memset(i, 0, sz * sizeof(*i)); }
    int &operator[](int x)
    {
        // require(x >= 0 && x < sz, "Array::operator[] out of range");
        if (x < 0 || x >= sz)
        {
            cout << "Array::operator[] out of range" << endl;
            exit(1);
        }
        return i[x];
    }
    friend ostream &operator<<(ostream &os, const Array<T, sz> &ia)
    {
        for (int j = 0; j < sz; j++)
        {
            os << ia.i[j];
            if (j != sz - 1)
                os << ", ";
        }
        os << endl;
        return os;
    }
    friend istream &operator>>(istream &is, Array<T, sz> &ia)
    {
        for (int j = 0; j < sz; j++)
            is >> ia.i[j];
        return is;
    }
};

int main()
{
    stringstream input("47 34 56 92 103");
    Array<int, 5> a;
    input >> a;
    a[4] = -1; // Use overloaded operator[]
    cout << a;
    return 0;
} ///:~