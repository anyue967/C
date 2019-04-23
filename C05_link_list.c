#include <stdio.h>
#include <stdlib.h>
#include "sll_node.c"

#define	TRUE	１
#define	FALSE	０


typedef struct NODE
{
	int value;
	struct NODE *next;	// 指针 next 指向这个结构体
} Node;		//	type struct NODE Node 结构类型名 "struct NODE"　等价于 "Node"

/**
 * 版本1，非正确
 */
int sll_insert(Node *current, int new_value)
{
	Node *previous;
	Node *new;

// 移动 指针
	while( current->value < new->value ){
		previous = current;
		current = current->next;	// 
	}	
// 分配内存
	new = (Node *)malloc( sizeof( Node ) );
	if( new == NULL)
		return FALSE;
	new->value = new_value;

//插入新节点
	new->next = current;	// 
	previous->next = new;	// 
	return TRUE;
}
result = sll_insert( root, 12 );	// 调用 root的值是一份拷贝作为形参current传递给函数



/**
 * 版本2
 */
result = sll_insert( &root, 12 );	// 指向root的指针，指针即地址

int sll_node(Node **rootp, int new_value)	// &root 传递给 rootp，这样rootp本就是指针，*rootp即访问root的值
{
	Node *current;
	Node *previous;
	Node *new;

// 得到指向第一个节点的指针 root
	current = *rootp;	// rootp = &root，*(&root) = root
	previous = NULL;	

// 移动 指针
	while( current != NULL && current->value < new->value ){
		previous = current;
		current = current->next;	// 
	}	
// 分配内存
	new = (Node *)malloc( sizeof( Node ) );
	if( new == NULL)
		return FALSE;
	new->value = new_value;

//插入新节点
	new->next = current;	// 
	if( previous == NULL )
		*rootp = new;
	else
		previous->next = new;	// 
	return TRUE;
}


/**
 * 版本3
 */
result = sll_insert( &root, 12 );	// 指向root的指针，指针即地址

int sll_node( register Node **nextp, int new_value )	// &root 传递给 rootp，这样rootp本就是指针，*rootp即访问root的值
{
	register Node *current;
	register Node *new;

// 得到指向第一个节点的指针 root
	current = *rootp;	// rootp = &root，*(&root) = root
	previous = NULL;	

// 移动 指针
	while( ( current = *nextp ) != NULL && current->value < new->value ){
		nextp = &current->next;
	}	
// 分配内存
	new = (Node *)malloc( sizeof( Node ) );
	if( new == NULL)
		return FALSE;
	new->value = new_value;

//插入新节点
	new->link = current;
	*nextp = new;
	return TRUE;
}