// Experiment1-copyfile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include <fstream>
using namespace std;
// 文件拷贝函数
// 输入：inpath——待拷贝文件路径；outpath——目标文件路径
// 输出：true——拷贝成功；false——拷贝失败
bool copyfile(char* inpath, char* outpath)
{

	ifstream in;
	ofstream out;
	in.open(inpath);
	if (in.fail())
	{
		cout << "输入文件打开失败" << endl;
		in.close();
		out.close();
		return false;
	}
	out.open(outpath);
	if (out.fail())
	{
		cout << "输出文件打开失败" << endl;
		in.close();
		out.close();
		return false;
	}
	out << in.rdbuf();
	in.close();
	out.close();
	return true;
}
int main(int argc, char* argv[])
{
	if (argc <= 2)
	{
		cout << "传入参数错误" << endl;
		exit(1);
	}
	if (copyfile(argv[1], argv[2]))
	{
		cout << "文件拷贝成功：" << argv[2] << endl;
	}
	else
	{
		cout << "文件拷贝失败" << endl;
	}
	return 0;
}
