#include <stdio.h>

typedef int INT;
typedef struct 
{
	int a;
	char b;
}Node, *pNode;

int main()
{
	INT a = 10;
	printf("%d\n", a);
	Node s;
	s.a = 10;
	s.b = 'a';
	printf("%d, %c\n", s.a, s.b);
	pNode p = &s;
	printf("%d, %c\n", p->a, p->b);
	return 0;
}
