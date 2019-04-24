#include <stdio.h>
void f(int *p);		// 函数先声明
void g(int k);

int main(int argc, char const *argv[])
{
	/* code */
	int i =6;
	printf("&i=%p\n", &i);
	f(&i);
	g(i);
	return 0;
}

void f(int *p)	// 再定义
{
	printf("p=%p\n", p);
	printf("*p=%d\n", *p);
	*p = 26;
}

void g(int k)
{
	printf("k=%d\n", k);
}