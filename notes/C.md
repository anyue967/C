## 目录
* [指针](#指针)
* [typedef](#typedef)
* [数组](#数组)
* [ 结构体](# 结构体)

#### 1. 从逻辑上删除C代码,标准头文件结构： 
   
    #if 0  
    	statements  
    #endif  

#### 2. 参数传递：
**数组参数:**是以引用传递形式传递的 即**地址传递**，而**标量和常量**是按 **值传递**的。当数组名作为参数时，就产生引用传递的效果。  
程序中，传给函数的是一个**指向数组起始位置的指针**，即数组在内存中的地址。即**传入函数的数组是指针**  

    int a[10]; int* p=a; 	//a==&a[0] 无需用&取地址
    int a[] <===> int * const a=...	// 用const修饰，数组变量是const型指针   
 
    int i;  
    const int* p1 = &i;  //
    int const* p2 = &i;  //
    int *const p3 = &i;  // 修饰指针
    **判断哪个被const的标志是const在*的前边还是后边**

#### 3. gets 函数： 
从标准输入读取文本，**字符串**是以**NUL（ASCII：'\0'）字节结尾**的字符，例如："HELLO" H、E、L、L、O、NUL顺序存储的。  

+ 字符串可以表达为char *s的形式;
+ puts 函数 是gets 的输出版本，把指定字符串写到标准输出并在末尾添加一个换行符。
      
        while( ch = getchar() != EOF && ch != '\n');	// 提示文件结尾：EOF(-1)  
	  
        printf( "Original input : %s\n", input );// 执行格式化输出：Original input : Hi friends!      
        scanf( "%d", &columns[num] );// 格式化化输入，必须有“&”符号，数组参数前可以不需要
 	
#### 4. 指针即地址：  
 **指针变量**就是**一个其值为另外一个（一些）**内存地址的变量**，就是存放地址的变量，**未初始化的指针很危险！！！**   

*左值之所以叫左值：是因为出现在赋值号左边的**不是变量**，而是值，是表达式计算的结果，是特殊的值，所以叫左值*  

+ *&yptr -> * (&yptr) -> * (yptr的地址) -> 得到那个地址上的变量 -> yptr  
+ &*yptr -> &(*yptr) -> &(y) -> 得到y的地址，也就是yptr -> yptr      

声明 指针： `int *a;` 或者 `int* a;`	　　// a是：指向int型的指针，a的类型为：int*  
例1：   

    int a = 112,　b = -1;  	 
    float c = 3.14;  
    int *d = &a;	// d是指向a的指针(地址)，*d访问d所指向把内存单元的内容
    float* e = &c; 
    
例2：  
 
    *&a = 25;	     // 等价于 a = 25；访问指针常量指向的内存地址里的内容

例3：  

    int a = 12;  
    int *b = &a;	   // b指向a的地址  
    c = &b	         // c是指向b的指针
    int **c = &b;     // *操作符具有从右向左的结合性，相当于*(*c)，从里往外逐层求值，c本就是指针，*c访问c所指向的位置，即变量b 也即"*(&b) = b" 

指针（地址）指向内存地址		*（取值）访问地址里的内容   

#### 5. typedef:为各种 数据类型 定义新名字:
	
    #define d_ptr_to_char char *;
    typedef char *d_ptr_to_char;   	
    d_ptr_to_char a, b;   

const：声明常量，`int const a;` 或者 `const int a;`    
   	
    int const *ptr;      // 一个指向*整型常量*的指针，可以修改指针的值，但不能修改它所指向的值    
    int * const ptr;   // 一个指向整型的*常量指针*，此时指针是常量，无法修改，但可以修改它所指向的整型的值  
    int const * const ptr;	// *都不能修改*  

#### 6. 数组：  

    int vector[10], *vp = vector;	// 合法指针声明，vp是一个指向int型的指针，并把其初始化指向vector数组的第1个元素  
    int matrix[3][10], *mp = matrix;	// 不合法，mp是一个指向int型的指针，但mp是指向整型数组的指针  
    int (*p)[10];	// 合法声明  

#### 7. 结构体：  
+ 和本地变量一样，在函数内部声明的结构类型只能在函数内部使用；所以通常在函数外部声明结构类型，可以被多个函数使用；  

+ . 的左边是一个结构，否则无意义  

        声明1：  									 声明2：  
    		sturct {							     struct { 
    			int a;  								int a;   
    			char b;  						    	char b;  
    			float c;  							    float c;  
    		} x;	// 结构体变量	  					 } y[20], *z;	// 指针z 指向 这个类型的结构体 
 
    
    	声明2：                                      声明4：
    		struct SIMPLE {							typedef struct {  
    			// 结构体类型：struct SIMPLE					int a;  
    			int a;								 		char b;  
    			char b;								 		float c;  
    			float c;  							} Simple;	// 结构体类型名：Simple  
    		};										Simple x;  	
    		struct SIMPLE x;						Simple y[20], *z;  	
    		struct SIMPLE y[20], *z;					
    
    	访问成员：  
    		直接访问：  
    			struct COMPLEX comp {  
    				flaot f;
    				int a[20];  
    				long *lp;  
    				struct SIMPLE s;  
    				struct SIMPLE sa[10];  
    				struct SIMPLE *sp;  
    			};	
    			comp.a;	// 选择成员a，结果是数组名，为指针常量  
    			comp.s;	// 选择成员s，结果是个结构  
    

		间接访问：  
			void func( struct COMPLEX *cp);	// 假如是访问结构体的函数原型  
			则，(*cp).f，简洁访问结构体成员f；亦可以这样做：cp->f、cp->a、cp->s  

	情况1：直接访问： 

		typedef struct {  
			char product [PRODUCT_SIZE];  
			int quantity;
			float unit_price;  
			float total_amount;  
		} Transaction;	// 共32字节  
		void print_receipt(Tansaction trans)  
		{  
			printf( "%s\n", trans.product );  
			printf( "%d @ %.2f total %.2f\n", trans.quantity, trans.unit_price, trans.total_amount );  
		}	// 声明print_receipt函数  
		print_recepit( current_trans );	// 调用print_receipt函数，但是执行效率低  

	情况2：间接访问： 
 
		void print_receipt(Tansaction const *trans)    
		{    
		  	printf( "%s\n", trans->product );    
			printf( "%d @ %.2f total %.2f\n", trans->quantity, trans->unit_price, trans->total_amount );  
		}	// 声明print_receipt函数    
		print_recepit( &current_trans );	// 调用print_receipt函数，因为指针比整个结构要小的多，压倒堆栈上执行效率高  
  
	 情况3：中断服务程序模型：

		 typedef struct tagIntQueue
		 {
         	int intType;
            struct tagIntQueue *next;
         }IntQueue;
         intQueue* IpIntQueueHead;
         __interrupt ISRexample()
         {
             int intType;
             intType = GetSystemType();
             QueueAddTail(IpIntQueueHead, intType);
         }
		
#### 8. 动态内存分配：  
	malloc()：动态内存分配，函数原型：void *malloc( size_t size);    
		1.参数就是需要分配内存字节数，若内存有满足这个需要，malloc会返回一个指向这块内存起始位置的指针；    
		2.若如果无法向malloc提供内存，就返回NULL指针，这就需要检查malloc返回值是很重要的   
 
	calloc()：函数原型：void *calloc( size_t num_elements，size_t element_size );  
		1.返回指向内存的指针之前把内存初始化为0  

	realloc():函数原型：void realloc( void *ptr, size_t new_size );  
		1.修改一个原先已经分配的内存块的大小  

	free()：动态内存释放,函数原型：void free( void *pointer );  
		1.参数要么是NULL，要么是malloc、calloc、realloc返回值，向free传NULL不会产生任何效果 
 
	    /*  
		**	Get 10 integers  
		 */  
		    int *pi;  
		    pi = malloc( 10 * sizeof( int ) );  
		...  
		/*  
		** Free only the last 5 integers； keep the first 5  
		 */  
		    free( pi + 5 );  
**注：释放一部分内存是不允许的，动态分配内存必须整块一起释放。但是，realloc函数可缩小一块动态分配的内存，有效释放尾部的部分内存不要访问已经被free释放的内存**
**分配内存但在使用完毕后不释放将引起内存泄露，因为一个持续分配却一点不释放内存的程序最终将耗尽可用内存**



#### 9. 链表：  
+ 链表包含一个"头指针"，指向下一个元素，称作"结点"，包含*用户数据 与 下一个结点的地址*   

        typedef struct NODE {
    		struct NODE *next;	// 指针next 指向结构体类型
    		int value;
    	} Node; // typedef struct NODE Node	即 "struct NODE" 等价于 "Node"，可以用Node代替结构体类型名  	
		
#### 10. 关于作用域、链接属性、存储类型：     
[链接属性]()：标识符的作用域与它的链接属性有关，'external、internal、none'，非代码快内部或者函数内部缺省状态下具有external属性，static用于修改标识符的链接属性由external-->internal    
[存储类型]():凡在任何代码快之外声明的变量总是存储于静态内存中，即不属于堆栈的内存，称作静态变量(static)，存在于整个程序执行期间，始终保持原先的值，除非给它另赋值  
[总结]()：external-->称为全局实体，不受访问限制
  
 
	    int a = 5;		// 链接属性：external，b也具有
		extern int b;	// a，b，c存储类型静态
		static int c;	// 链接属性由external-->internal，仅仅由源文件访问
		int d(int e)
		{
			int f = 15;
			register int b;
			static int g = 20;
			extern int a;
  			...
			{
				int e;
				int a;
				extern int h;
				...
			}
			...
			{
				int x;
				int e;
				...
			}
   		...
		}
		static int i()
		{
			...
		}
		...
    
	






