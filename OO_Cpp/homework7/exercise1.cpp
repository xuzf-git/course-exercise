#include <iostream>
using namespace std;
void Sort(int *const num)
{
	// 插入排序
	for (int i = 1; i < 10; ++i)
	{
		int temp = num[i], j;
		for (j = i; j > 0; --j)
		{
			if (temp < num[j - 1])
			{
				num[j] = num[j - 1];
			}
			else
			{
				break;
			}
		}
		num[j] = temp;
	}
}

void Show(int const *const num)
{
	// 无mod参数，从小到大print
	for (int i = 0; i < 10; ++i)
	{
		cout << num[i] << " ";
	}
	cout << endl;
}

void Show(int const *const num, char mod)
{
	// 有mod参数，从大到小print
	for (int i = 9; i >= 0; --i)
	{
		cout << num[i] << " ";
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	int num[10];
	for (int i = 0; i < 10; ++i)
	{
		cin >> num[i];
	}
	Sort(num);
	cout << "Decrement: ";
	Show(num);
	cout << "Increasing: ";
	Show(num, 'd');
	return 0;
}