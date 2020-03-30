#include <iostream>
using namespace std;
class CSmart
{
private:
	static int count;

public:
	CSmart()
	{
		cout << ++count << " ";
		if (count > 1)
			cout << "objects" << endl;
		else
			cout << "object" << endl;
	}
	~CSmart()
	{
		cout << --count << " ";
		if (count > 1)
			cout << "objects" << endl;
		else
			cout << "object" << endl;
	}
};

int CSmart::count = 0; // 初始化静态变量

void DoSomething()
{
	CSmart s;
}

CSmart s1;

int main(int argc, char const *argv[])
{
	CSmart s2;
	DoSomething();
	CSmart *s3 = new CSmart;
	delete s3;
	return 0;
}
