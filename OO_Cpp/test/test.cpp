#include <iostream>
#include <cstring>
using namespace std;
class KeepString
{
private:
	char* str;

public:
	KeepString();
	KeepString(const char* pstr);
	~KeepString();
	const char* GetString() { return str; }
};
KeepString::KeepString()
{
	str = NULL;
}
KeepString::KeepString(const char * pstr)
{
	int len = strlen(pstr);
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		str[i] = pstr[i];
	}
}
KeepString::~KeepString()
{
	if (str != NULL)
	{
		delete[] str;
	}
}
int main(int argc, char const* argv[])
{
	KeepString KS("Internal String");
	const char* p = KS.GetString();
	cout << p << endl; // Output is:  Internal String
	return 0;
}