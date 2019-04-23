#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * 安全版本
 * char* strncpy(char *restrict dst, const char *restrict src, size_t n);
 * char* strncat(char *restrict s1, const char *restrict s2, size_t n);
 * int strncmp(const char *s1, const char *s2, size_t n);
 *
 *
 * char* strchr(const char *s, int c);	// 从左边 返回指针
 * char* strrchr(const char *s, int c);
 * 
 * char* strstr(const char *s1, const chat *s2);
 * char* strcasestr(const char *s1, const char *s2);
 */

size_t mystrlen(const char *s1)
{
	int index_1 = 0;
	while( s1[index_1] != '\0' ){
		index_1++;
	}
	return index_1;

}

int mystrcmp(const char *s2, const char *s3)
{
	int index_2 = 0;
	while( *s2 == *s3 && *s2 != '\0'){
		s2++;
		s3++;
	}
	return *s2 - *s3;
}

char* mystrcpy(char* dst, const char* src)
{
	char* ret = dst;
	while( *dst++ = *src++ )
		;
	*dst = '\0';
	return ret;
}



int main(int argc, char const *argv[])
{
	/* code */
/*
strlen()
 */
	char s1[] = "Hello";
	printf("strlen=%lu\n", mystrlen(s1));
	printf("sizeof=%lu\n", sizeof(s1));
	printf("\n");

/*
strcmp
 */
	char s2[]="abc";
	char s3[]="abc";
	printf("%d\n", mystrcmp(s2,s3));	// 返回0相等
	printf("\n"); 

/*
strcpy
 */
	printf("\n");

/*
strcat
 */

/*
strchr
 */
	char s4[] = "hello";
	char* s5 = strchr(s4, 'l');
	char a = *s5;	// --> c = 'l'
	*s5 = '\0';
	char* t = (char*)malloc(strlen(s4)+1);
	strcpy(t, s4);
	printf("%s\n", t);
	free(t);
	return 0;
}


 