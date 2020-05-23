#include <stdio.h>
struct node{
	int a;
};
int main(int argc, char const *argv[])
{
	node h;
	h.a = 11;
	printf("%d\n", h.a);
	return 0;
}