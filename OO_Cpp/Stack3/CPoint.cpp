#include <iostream>
using namespace std;
class  CPointer
{
private:
	int *p;
public:
	pointer(int x);
	~pointer()
	void Copy(CPointer fa);
};
void main()
{
      CPointer p(10), q(20);
      q.Copy(p); 
}
