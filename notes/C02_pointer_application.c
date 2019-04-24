#include <stdio.h>
void swap(int *pa, int*pb);	// 交换函数的声明
void minmax(int *c, int len, int *max, int *min);	//int c[]
int divide(int a, int b, int *result);	


int main(int argc, char const *argv[])
{
	/* code */
/*
指针应用场景一：交换两个变量的值
 */
	int a = 5;
	int b = 6;
	printf("swap before：a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap after：a=%d, b=%d\n", a, b);
	printf("\n");

/*
指针应用场景二a：函数返回多个值，某些值就只能通过指针返回；
传入的参数实际上是需要保存带回的结果的变量
 */
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int min, max;
	printf("main sizeof(c)=%lu\n", sizeof(c));
	printf("main c=%p\n", c);
	minmax(c, sizeof(c)/sizeof(c[0]), &min, &max);
	printf("min=%d, max=%d\n", min, max);
	printf("\n");

/*
指针应用场景二b：函数返回运算状态，结果通过指针返回；
 */
	int d = 10;
	int e = 2;
	int f;
	if( divide(d, e, &f) ){
		printf("%d/%d=%d\n", d, e, f);
	}
	printf("\n");

/*
测验：
 */
	int g[] = {5, 15, 34, 54, 14, 2, 52, 72};
	int *p1 = &g[5];
	int *p2 = g;	// 数组名是一个常量指针 即 int *const p2
	/*
	p == a[0]	// false
	p == &a[0]	// true
	*p == a[0]	// true
	p[0] == a[0]	// true
	 */
	printf("p1[-2]=%d\n", p1[-2]);	// 向左为负，向右为正
	return 0;
}

void swap(int *pa, int *pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

void minmax(int *c, int len, int *min, int *max)	// int c[]
{
	int i;
	printf("minmax sizeof(c)=%lu\n", sizeof(c));
	printf("minmax c=%p\n", c);
	*min = *max=c[0];
	for( i = 1; i < len; i++ ){
		if (c[i] < *min){
			*min = c[i];
		}
		if( c[i] > *max ){
			*max = c[i];
		}
	}
}

int divide(int d, int e, int *result)
{
	int ret = 1;
	if ( e==0)	ret = 0;
	else{
		*result = d/e;
	}
	return ret;
}