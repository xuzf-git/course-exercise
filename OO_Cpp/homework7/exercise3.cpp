#include <iostream>
#include <cstring>
using namespace std;
class KeepString
{
private:
	char *str;

public:
	KeepString();
	KeepString(char *const pstr);
	~KeepString();
	const char *GetString() { return str; }
};
KeepString::KeepString()
{
	str = NULL;
}
KeepString::KeepString(char *const pstr)
{
	int len = strlen(pstr);
	str = new char[len + 1];
	strcpy(str, pstr);
}
KeepString::~KeepString()
{
	if (str != NULL)
	{
		delete[] str;
	}
}
int main(int argc, char const *argv[])
{
	KeepString KS("Internal String");
	const char *p = KS.GetString();
	cout << p << endl; // Output is:  Internal String
	return 0;
}