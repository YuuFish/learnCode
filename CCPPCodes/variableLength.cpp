#include<iostream>
#include<cstdarg>

using namespace std;

/************************************************************************/
/* 　
    type va_arg(va_list argptr, type);
　　void va_end(va_list argptr);
　　void va_start(va_list argptr, last_parm); 
	都包含在头文件<stdarg.h>中      
	任何可变长度的变元被访问之前，必须先用va_start()初始化变元指针argptr
	#define _INTSIZEOF(n) ((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1) )
	#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) ) //第一个可选参数地址
	#define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) ) //下一个参数地址
　　#define va_end(ap) ( ap = (va_list)0 ) // 将指针置为无效
 */
/************************************************************************/

int var_arg(int first, ...)
{
	int sum = 0;
	int nArg = 0;
	sum += first;
	va_list arg_ptr;
	va_start(arg_ptr, first);
	do
	{
		nArg = va_arg(arg_ptr, int);
		sum += nArg;
	}while(nArg != 0);
	va_end(arg_ptr);
	return sum;
}

int main()
{
	cout << "variable arguments test: " << endl;
	cout << var_arg(1,2,3,4,5,0) << endl;
	cout << var_arg(2,5,5,0) << endl;
	return 0;
}
